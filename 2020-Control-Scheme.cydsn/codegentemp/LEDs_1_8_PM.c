/*******************************************************************************
* File Name: LEDs_1_8_PM.c
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

#include "LEDs_1_8.h"

/* Check for removal by optimization */
#if !defined(LEDs_1_8_Sync_ctrl_reg__REMOVED)

static LEDs_1_8_BACKUP_STRUCT  LEDs_1_8_backup = {0u};

    
/*******************************************************************************
* Function Name: LEDs_1_8_SaveConfig
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
void LEDs_1_8_SaveConfig(void) 
{
    LEDs_1_8_backup.controlState = LEDs_1_8_Control;
}


/*******************************************************************************
* Function Name: LEDs_1_8_RestoreConfig
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
void LEDs_1_8_RestoreConfig(void) 
{
     LEDs_1_8_Control = LEDs_1_8_backup.controlState;
}


/*******************************************************************************
* Function Name: LEDs_1_8_Sleep
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
void LEDs_1_8_Sleep(void) 
{
    LEDs_1_8_SaveConfig();
}


/*******************************************************************************
* Function Name: LEDs_1_8_Wakeup
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
void LEDs_1_8_Wakeup(void)  
{
    LEDs_1_8_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
