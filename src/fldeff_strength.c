#include "global.h"
#include "event_data.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "fldeff.h"
#include "party_menu.h"
#include "script.h"
#include "string_util.h"
#include "task.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"

// static functions
static void FieldCallback_Strength(void);
static void StartStrengthFieldEffect(void);

// text
bool32 SetUpFieldMove_Strength(void)
{
    if (CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_PUSHABLE_BOULDER) == TRUE
     || CheckObjectGraphicsInFrontOfPlayer(OBJ_EVENT_GFX_PUSHABLE_BOULDER_FRLG) == TRUE)
    {
        gSpecialVar_Result = GetCursorSelectionMonId();
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_Strength;
        return TRUE;
    }
    return FALSE;
}

static void FieldCallback_Strength(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(EventScript_UseStrength);
}

static void Task_StrengthNoBanner(u8 taskId)
{
    // wait one frame so the script's waitstate is fully armed
    if (gTasks[taskId].data[0]++ < 1)
        return;
    StartStrengthFieldEffect();
    DestroyTask(taskId);
}

bool8 FldEff_UseStrength(void)
{
    u8 taskId = CreateTask(Task_StrengthNoBanner, 8);
    gTasks[taskId].data[0] = 0;
    return FALSE;
}

// Just passes control back to EventScript_UseStrength
static void StartStrengthFieldEffect(void)
{
    FieldEffectActiveListRemove(FLDEFF_USE_STRENGTH);
    ScriptContext_Enable();
}
