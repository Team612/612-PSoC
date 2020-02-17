/*******************************************************************************
* File Name: LEDs_9_10_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "LEDs_9_10.h"

/* Check for removal by optimization */
#if !defined(LEDs_9_10_Sync_ctrl_reg__REMOVED)

static LEDs_9_10_BACKUP_STRUCT  LEDs_9_10_backup = {0u};

    
/*******************************************************************************
* Function Name: LEDs_9_10_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LEDs_9_10_SaveConfig(void) 
{
    LEDs_9_10_backup.controlState = LEDs_9_10_Control;
}


/*******************************************************************************
* Function Name: LEDs_9_10_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void LEDs_9_10_RestoreConfig(void) 
{
     LEDs_9_10_Control = LEDs_9_10_backup.controlState;
}


/*******************************************************************************
* Function Name: LEDs_9_10_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LEDs_9_10_Sleep(void) 
{
    LEDs_9_10_SaveConfig();
}


/*******************************************************************************
* Function Name: LEDs_9_10_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LEDs_9_10_Wakeup(void)  
{
    LEDs_9_10_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
