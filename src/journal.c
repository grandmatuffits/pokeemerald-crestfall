#include "global.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/songs.h"
#include "event_data.h"
#include "main.h"
#include "menu.h"
#include "sound.h"
#include "string_util.h"
#include "text.h"
#include "window.h"

#define JOURNAL_LINE_H      16   // pixels per text line
#define JOURNAL_ENTRY_GAP    6   // pixels between entries
#define JOURNAL_BODY_Y      20   // first entry's y (below the title)
#define JOURNAL_BODY_HEIGHT 108  // pixels available for entries (128 window height - 20)
#define JOURNAL_TEXT_X      12   // indent, leaves room for the checkbox

enum JournalEntry
{
    JE_BADGE1,
    JE_BADGE2,
    JE_BADGE3,
    JE_BADGE4,
    JE_SILVIO,
    JE_BADGE5,
    JE_COVENANT_DELMARK,
    JE_BADGE6,
    JE_COVENANT_WHITECAPS,
    JE_BADGE7,
    JE_GRANT_ISLAND,
    JE_BACK_TO_MAINLAND,
    JE_BADGE8,
    JE_BRIGHAM,
    JE_RETURN_MINSI,
    JE_LEAGUE,
    JE_CATCHER,
    JE_PORYGON_FIND,
    JE_PORYGON_RETURN,
    JE_OVAL_DELIVER,
    JE_OVAL_RETURN,
    JE_UMBRA,
    JE_HEMLOCK,
    JE_ROSS,
    JE_REMATCHES,
    JE_SILVIO_REMATCH,
    JE_UMBRA_REMATCH,
    JE_ELDERS,
    JE_SAFARI,
    JE_OAK,
    JE_RED,
    JE_STEVEN,
    JE_CYNTHIA,
    JE_COUNT
};

static u8 sJournalWindowId;
static u8 sJournalPage;
static u8 sJournalPageCount;
static u8 sJournalActiveCount;
static u8 sJournalActive[JE_COUNT];
static u8 sJournalPageFirst[JE_COUNT + 1];
static u8 sJournalCounterText[48];

static const u8 sJournalTitle[] = _("JOURNAL");
static const u8 sJournalNone[] = _("No current objectives.");
static const u8 sJournalPageOpen[] = _(" (");
static const u8 sJournalSlash[] = _("/");
static const u8 sJournalPageClose[] = _(")");
static const u8 sJournalRematchA[] = _("Rematch the GYM LEADERS\n(");
static const u8 sJournalRematchB[] = _("/6 done)");

static const u8 *const sJournalText[JE_COUNT] =
{
    [JE_BADGE1] = COMPOUND_STRING("Get your 1st GYM BADGE."),
    [JE_BADGE2] = COMPOUND_STRING("Get your 2nd GYM BADGE."),
    [JE_BADGE3] = COMPOUND_STRING("Get your 3rd GYM BADGE."),
    [JE_BADGE4] = COMPOUND_STRING("Get your 4th GYM BADGE."),
    [JE_SILVIO] = COMPOUND_STRING("Find MAYOR SILVIO in the\nWALLAR MARSHLANDS."),
    [JE_BADGE5] = COMPOUND_STRING("Get your 5th GYM BADGE in\nVALERYTOWN."),
    [JE_COVENANT_DELMARK] = COMPOUND_STRING("Take down TEAM COVENANT in\nDELMARK CITY."),
    [JE_BADGE6] = COMPOUND_STRING("Get your 6th GYM BADGE in\nDELMARK CITY."),
    [JE_COVENANT_WHITECAPS] = COMPOUND_STRING("Stop TEAM COVENANT in\nWHITECAPS."),
    [JE_BADGE7] = COMPOUND_STRING("Get your 7th GYM BADGE."),
    [JE_GRANT_ISLAND] = COMPOUND_STRING("Surf north of ROSEBANK TOWN\nto GRANT ISLAND."),
    [JE_BACK_TO_MAINLAND] = COMPOUND_STRING("Surf west back to mainland\nENPALE."),
    [JE_BADGE8] = COMPOUND_STRING("Get your 8th GYM BADGE."),
    [JE_BRIGHAM] = COMPOUND_STRING("Stop BRIGHAM in BAYNOE TOWN."),
    [JE_RETURN_MINSI] = COMPOUND_STRING("Go west to return to\nMINSI CITY."),
    [JE_LEAGUE] = COMPOUND_STRING("Face the POKéMON LEAGUE."),
    [JE_CATCHER] = COMPOUND_STRING("Catch a RALTS on ROUTE 1 and\nbring it to MINSI CITY."),
    [JE_PORYGON_FIND] = COMPOUND_STRING("Find the data module in\nALLENWOOD FOREST."),
    [JE_PORYGON_RETURN] = COMPOUND_STRING("Return the data module to\nthe MINSI CITY POKéMON LAB."),
    [JE_OVAL_DELIVER] = COMPOUND_STRING("Deliver the letter to\nCOPPERGATE CITY."),
    [JE_OVAL_RETURN] = COMPOUND_STRING("Return to the MINSI CITY\napartment for your reward."),
    [JE_UMBRA] = COMPOUND_STRING("Speak to UMBRA in\nVELDTMOOR CITY."),
    [JE_HEMLOCK] = COMPOUND_STRING("Speak to PROFESSOR HEMLOCK\nin MINSI CITY."),
    [JE_ROSS] = COMPOUND_STRING("Speak to ROSS in the\nMINSI CITY GYM."),
    [JE_REMATCHES] = NULL, // built at runtime (counter)
    [JE_SILVIO_REMATCH] = COMPOUND_STRING("Speak to SILVIO in the\nDELMARK CITY GYM."),
    [JE_UMBRA_REMATCH] = COMPOUND_STRING("Face the POKéMON LEAGUE."),
    [JE_ELDERS] = COMPOUND_STRING("Find and stop the ELDERS in\nthe WALLAR BELLTOWER."),
    [JE_SAFARI] = COMPOUND_STRING("Visit the SAFARI ZONE in\nCOPPERGATE CITY."),
    [JE_OAK] = COMPOUND_STRING("Speak to PROFESSOR OAK in\nthe MINSI CITY POKéMON LAB."),
    [JE_RED] = COMPOUND_STRING("Speak to RED in the\nWALLAR MARSHLANDS."),
    [JE_STEVEN] = COMPOUND_STRING("Speak to STEVEN in\nWHITECAPS."),
    [JE_CYNTHIA] = COMPOUND_STRING("Speak to CYNTHIA on\nGRANT ISLAND."),
};

static const struct WindowTemplate sJournalWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 2,
    .width = 28,
    .height = 16,
    .paletteNum = 15,
    .baseBlock = 1,
};

static u8 CountRematchesDone(void)
{
    return FlagGet(FLAG_ROSS_REMATCH_DONE)
         + FlagGet(FLAG_ROBIN_REMATCH_DONE)
         + FlagGet(FLAG_OMAR_REMATCH_DONE)
         + FlagGet(FLAG_INGRID_REMATCH_DONE)
         + FlagGet(FLAG_FRIEDE_REMATCH_DONE)
         + FlagGet(FLAG_RANDALL_REMATCH_DONE)
         + FlagGet(FLAG_MERYL_REMATCH_DONE);
}

static bool8 IsJournalEntryActive(u8 id)
{
    switch (id)
    {
    case JE_BADGE1: return !FlagGet(FLAG_BADGE01_GET);
    case JE_BADGE2: return FlagGet(FLAG_BADGE01_GET) && !FlagGet(FLAG_BADGE02_GET);
    case JE_BADGE3: return FlagGet(FLAG_BADGE02_GET) && !FlagGet(FLAG_BADGE03_GET);
    case JE_BADGE4: return FlagGet(FLAG_BADGE03_GET) && !FlagGet(FLAG_BADGE04_GET);
    case JE_SILVIO: return FlagGet(FLAG_DELMARK_APARTMENT_AMBUSH_DONE) && !FlagGet(FLAG_WALLAR_SAXUS_DONE);
    case JE_BADGE5: return FlagGet(FLAG_BADGE04_GET) && !FlagGet(FLAG_BADGE05_GET);
    case JE_COVENANT_DELMARK: return FlagGet(FLAG_WALLAR_SAXUS_DONE) && VarGet(VAR_DELMARK_REVISIT_STATE) < 4;
    case JE_BADGE6: return FlagGet(FLAG_BADGE05_GET) && !FlagGet(FLAG_BADGE06_GET);
    case JE_COVENANT_WHITECAPS: return FlagGet(FLAG_BADGE06_GET) && VarGet(VAR_WHITECAPS_STATE) < 2;
    case JE_BADGE7: return FlagGet(FLAG_BADGE06_GET) && !FlagGet(FLAG_BADGE07_GET);
    case JE_GRANT_ISLAND: return VarGet(VAR_WHITECAPS_STATE) >= 2 && VarGet(VAR_GRANT_STATE) < 2;
    case JE_BACK_TO_MAINLAND: return FlagGet(FLAG_BADGE07_GET) && !FlagGet(FLAG_JOURNAL_BACK_ON_MAINLAND) && !FlagGet(FLAG_BADGE08_GET);
    case JE_BADGE8: return FlagGet(FLAG_BADGE07_GET) && !FlagGet(FLAG_BADGE08_GET);
    case JE_BRIGHAM: return FlagGet(FLAG_BERGEN_HILL_DONE) && !FlagGet(FLAG_BAYNOE_TEMPLE_DONE);
    case JE_RETURN_MINSI: return FlagGet(FLAG_BAYNOE_TEMPLE_DONE) && !FlagGet(FLAG_JOURNAL_BACK_IN_MINSI) && !FlagGet(FLAG_DEFEATED_ENPALE_CHAMP);
    case JE_LEAGUE: return FlagGet(FLAG_BADGE08_GET) && !FlagGet(FLAG_DEFEATED_ENPALE_CHAMP);
    case JE_CATCHER: return FlagGet(FLAG_MINSI_CATCHER_STARTED) && !FlagGet(FLAG_MINSI_CATCHING_CHARM_RECEIVED);
    case JE_PORYGON_FIND: return FlagGet(FLAG_PORYGON_QUEST_STARTED) && !FlagGet(FLAG_PORYGON_MODULE_FOUND);
    case JE_PORYGON_RETURN: return FlagGet(FLAG_PORYGON_MODULE_FOUND) && !FlagGet(FLAG_PORYGON_RECEIVED);
    case JE_OVAL_DELIVER: return FlagGet(FLAG_MINSI_OVAL_STARTED) && !FlagGet(FLAG_MINSI_OVAL_DELIVERED);
    case JE_OVAL_RETURN: return FlagGet(FLAG_MINSI_OVAL_DELIVERED) && !FlagGet(FLAG_MINSI_OVAL_RECEIVED);
    case JE_UMBRA: return FlagGet(FLAG_DEFEATED_ENPALE_CHAMP) && !FlagGet(FLAG_ELDERS_ARC_STARTED);
    case JE_HEMLOCK: return FlagGet(FLAG_DEFEATED_ENPALE_CHAMP) && !FlagGet(FLAG_MINSI_NATDEX_RECEIVED);
    case JE_ROSS: return FlagGet(FLAG_ELDERS_ARC_STARTED) && !FlagGet(FLAG_ROSS_REMATCH_DONE);
    case JE_REMATCHES: return FlagGet(FLAG_ROSS_REMATCH_DONE) && CountRematchesDone() < 7;
    case JE_SILVIO_REMATCH: return CountRematchesDone() >= 7 && !FlagGet(FLAG_SILVIO_REMATCH_DONE);
    case JE_UMBRA_REMATCH: return FlagGet(FLAG_SILVIO_REMATCH_DONE) && !FlagGet(FLAG_DEFEATED_UMBRA_REMATCH);
    case JE_ELDERS: return FlagGet(FLAG_DEFEATED_UMBRA_REMATCH) && !FlagGet(FLAG_ELDERS_ARC_COMPLETE);
    case JE_SAFARI: return FlagGet(FLAG_MINSI_NATDEX_RECEIVED) && !FlagGet(FLAG_SAFARI_ZONE_ENTERED);
    case JE_OAK: return FlagGet(FLAG_MINSI_NATDEX_RECEIVED) && !FlagGet(FLAG_OAK_BEATEN);
    case JE_RED: return FlagGet(FLAG_OAK_BEATEN) && !FlagGet(FLAG_RED_BEATEN);
    case JE_STEVEN: return FlagGet(FLAG_OAK_BEATEN) && !FlagGet(FLAG_STEVEN_BEATEN);
    case JE_CYNTHIA: return FlagGet(FLAG_OAK_BEATEN) && !FlagGet(FLAG_CYNTHIA_BEATEN);
    }
    return FALSE;
}

static const u8 *GetJournalEntryText(u8 id)
{
    u8 *dst;

    if (id != JE_REMATCHES)
        return sJournalText[id];

    dst = StringCopy(sJournalCounterText, sJournalRematchA);
    dst = ConvertIntToDecimalStringN(dst, CountRematchesDone(), STR_CONV_MODE_LEFT_ALIGN, 1);
    StringCopy(dst, sJournalRematchB);
    return sJournalCounterText;
}

static u8 CountTextLines(const u8 *s)
{
    u8 n = 1;

    for (; *s != EOS; s++)
    {
        if (*s == CHAR_NEWLINE)
            n++;
    }
    return n;
}

static void BuildJournalPages(void)
{
    u8 i, used = 0;

    sJournalActiveCount = 0;
    for (i = 0; i < JE_COUNT; i++)
    {
        if (IsJournalEntryActive(i))
            sJournalActive[sJournalActiveCount++] = i;
    }

    sJournalPageCount = 1;
    sJournalPageFirst[0] = 0;
    for (i = 0; i < sJournalActiveCount; i++)
    {
        u8 h = CountTextLines(GetJournalEntryText(sJournalActive[i])) * JOURNAL_LINE_H + JOURNAL_ENTRY_GAP;

        if (used > 0 && used + h - JOURNAL_ENTRY_GAP > JOURNAL_BODY_HEIGHT)
        {
            sJournalPageFirst[sJournalPageCount++] = i;
            used = 0;
        }
        used += h;
    }
    sJournalPageFirst[sJournalPageCount] = sJournalActiveCount;
}

static void PrintJournalLines(const u8 *s, u8 x, u8 y)
{
    u8 buf[40];
    u8 i;

    for (;;)
    {
        i = 0;
        while (*s != EOS && *s != CHAR_NEWLINE && i < 38)
            buf[i++] = *s++;
        buf[i] = EOS;
        AddTextPrinterParameterized(sJournalWindowId, FONT_NORMAL, buf, x, y, 0, NULL);
        y += JOURNAL_LINE_H;
        if (*s == EOS)
            break;
        if (*s == CHAR_NEWLINE)
            s++;
    }
}

static void DrawJournalCheckbox(u8 y)
{
    FillWindowPixelRect(sJournalWindowId, PIXEL_FILL(2), 1, y, 8, 8);
    FillWindowPixelRect(sJournalWindowId, PIXEL_FILL(1), 2, y + 1, 6, 6);
}

static void PrintJournalPage(void)
{
    u8 *dst;
    u8 i, y;

    FillWindowPixelBuffer(sJournalWindowId, PIXEL_FILL(1));

    dst = StringCopy(gStringVar4, sJournalTitle);
    if (sJournalPageCount > 1)
    {
        dst = StringCopy(dst, sJournalPageOpen);
        dst = ConvertIntToDecimalStringN(dst, sJournalPage + 1, STR_CONV_MODE_LEFT_ALIGN, 2);
        dst = StringCopy(dst, sJournalSlash);
        dst = ConvertIntToDecimalStringN(dst, sJournalPageCount, STR_CONV_MODE_LEFT_ALIGN, 2);
        dst = StringCopy(dst, sJournalPageClose);
    }
    AddTextPrinterParameterized(sJournalWindowId, FONT_NORMAL, gStringVar4, 0, 1, 0, NULL);

    if (sJournalActiveCount == 0)
    {
        AddTextPrinterParameterized(sJournalWindowId, FONT_NORMAL, sJournalNone, 0, JOURNAL_BODY_Y, 0, NULL);
    }
    else
    {
        y = JOURNAL_BODY_Y;
        for (i = sJournalPageFirst[sJournalPage]; i < sJournalPageFirst[sJournalPage + 1]; i++)
        {
            const u8 *text = GetJournalEntryText(sJournalActive[i]);

            DrawJournalCheckbox(y + 4);
            PrintJournalLines(text, JOURNAL_TEXT_X, y);
            y += CountTextLines(text) * JOURNAL_LINE_H + JOURNAL_ENTRY_GAP;
        }
    }

    CopyWindowToVram(sJournalWindowId, COPYWIN_GFX);
}

void ShowJournalWindow(void)
{
    sJournalWindowId = AddWindow(&sJournalWindowTemplate);
    DrawStdWindowFrame(sJournalWindowId, FALSE);
    BuildJournalPages();
    sJournalPage = 0;
    PrintJournalPage();
    PutWindowTilemap(sJournalWindowId);
    CopyWindowToVram(sJournalWindowId, COPYWIN_FULL);
}

// Returns TRUE when the journal should close.
bool8 JournalProcessInput(void)
{
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        return TRUE;
    }
    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        if (sJournalPage + 1 < sJournalPageCount)
        {
            sJournalPage++;
            PrintJournalPage();
            return FALSE;
        }
        return TRUE;
    }
    if (JOY_NEW(DPAD_DOWN | DPAD_RIGHT) && sJournalPage + 1 < sJournalPageCount)
    {
        PlaySE(SE_SELECT);
        sJournalPage++;
        PrintJournalPage();
    }
    else if (JOY_NEW(DPAD_UP | DPAD_LEFT) && sJournalPage > 0)
    {
        PlaySE(SE_SELECT);
        sJournalPage--;
        PrintJournalPage();
    }
    return FALSE;
}

void HideJournalWindow(void)
{
    ClearStdWindowAndFrame(sJournalWindowId, TRUE);
    RemoveWindow(sJournalWindowId);
}