/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2021, 2023 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_S12AD0.c
* Component Version: 1.3.1
* Device(s)        : R7F124FPJ5xFB
* Description      : This file implements device driver for Config_S12AD0.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_S12AD0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_S12AD0_Create
* Description  : This function initializes the ADC module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_S12AD0_Create(void)
{
    ADCEN = 1U;    /* supply AD clock */
    ADCKS = _00_AD_CONVERSION_CLOCK;
    ADWINR = _00_AD_REGISTER_GROUP1_RW_ENABLE;
    ADCSR &= (~_8000_AD_CONVERSION_START);
    ADMK = 1U;    /* disable INTAD interrupt */
    ADIF = 0U;    /* clear INTAD interrupt flag */
    /* Set INTAD low priority */
    ADPR1 = 1U;
    ADPR0 = 1U;
    ADWINR = _00_AD_REGISTER_GROUP1_RW_ENABLE;
    ADCSR = _0000_AD_SINGLE_SCAN_MODE | _0000_AD_SYNCASYNCTRG_DISABLE | _1000_AD_SCAN_END_INTERRUPT_ENABLE;
    ADWINR = _01_AD_REGISTER_GROUP2_RW_ENABLE;
    ADEXICR = _0200_AD_IREF_USED;
    ADWINR = _08_AD_ADGSPCR_ADHVREFCNT_RW_ENABLE;
    ADHVREFCNT = _00_AD_ANALOG_BLOCK_NORMAL | _00_AD_LOW_POTENTIAL_VSS | _00_AD_HIGH_POTENTIAL_VDD;
    ADWINR = _00_AD_REGISTER_GROUP1_RW_ENABLE;
    ADCER = _0000_AD_RIGHT_ALIGNMENT | _0000_AD_SELFDIAG_DISABLE | _0000_AD_AUTO_CLEARING_DISABLE;
    ADWINR = _07_AD_ADDISCR_RW_ENABLE;
    ADDISCR = _00_AD_DISCONNECT_UNUSED;
    ADWINR = _00_AD_REGISTER_GROUP1_RW_ENABLE;
    ADADC = _80_AD_AVERAGE_MODE | _01_AD_2_TIME_CONVERSION;
    ADWINR = _0D_AD_ADSSTRL_ADSSTRO_RW_ENABLE;
    ADSSTRO = _C8_AD_SAMPLING_STATE_O;

    R_Config_S12AD0_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_S12AD0_Start
* Description  : This function starts the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_S12AD0_Start(void)
{
    ADIF = 0U;    /* clear INTAD interrupt flag */
    ADMK = 0U;    /* enable INTAD interrupt */
    ADWINR = _00_AD_REGISTER_GROUP1_RW_ENABLE;
    ADCSR |= _8000_AD_CONVERSION_START;    /* enable conversion operation */
}

/***********************************************************************************************************************
* Function Name: R_Config_S12AD0_Stop
* Description  : This function stops the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_S12AD0_Stop(void)
{
    ADWINR = _00_AD_REGISTER_GROUP1_RW_ENABLE;
    ADCSR &= (~_8000_AD_CONVERSION_START);    /* stop conversion operation */
    ADMK = 1U;    /* disables INTAD interrupt */
    ADIF = 0U;    /* clear INTAD interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_Config_S12AD0_Get_ValueResult
* Description  : This function gets result from the AD converter.
* Arguments    : channel -
*                    channel of data register to be read
*                buffer -
*                    buffer pointer
* Return Value : None
***********************************************************************************************************************/
void R_Config_S12AD0_Get_ValueResult(e_ad_channel_t channel, uint16_t * const buffer)
{
    switch (channel)
    {
        case ADSELFDIAGNOSIS:
        {
            ADWINR = _01_AD_REGISTER_GROUP2_RW_ENABLE;
            *buffer = (uint16_t)(ADRD);
            break;
        }
        case ADCHANNEL0:
        {
            ADWINR = _02_AD_ADDR0_7_R_ENABLE;
            *buffer = (uint16_t)(ADDR0);
            break;
        }
        case ADCHANNEL1:
        {
            ADWINR = _02_AD_ADDR0_7_R_ENABLE;
            *buffer = (uint16_t)(ADDR1);
            break;
        }
        case ADCHANNEL2:
        {
            ADWINR = _02_AD_ADDR0_7_R_ENABLE;
            *buffer = (uint16_t)(ADDR2);
            break;
        }
        case ADCHANNEL3:
        {
            ADWINR = _02_AD_ADDR0_7_R_ENABLE;
            *buffer = (uint16_t)(ADDR3);
            break;
        }
        case ADCHANNEL4:
        {
            ADWINR = _02_AD_ADDR0_7_R_ENABLE;
            *buffer = (uint16_t)(ADDR4);
            break;
        }
        case ADCHANNEL5:
        {
            ADWINR = _02_AD_ADDR0_7_R_ENABLE;
            *buffer = (uint16_t)(ADDR5);
            break;
        }
        case ADCHANNEL6:
        {
            ADWINR = _02_AD_ADDR0_7_R_ENABLE;
            *buffer = (uint16_t)(ADDR6);
            break;
        }
        case ADCHANNEL7:
        {
            ADWINR = _02_AD_ADDR0_7_R_ENABLE;
            *buffer = (uint16_t)(ADDR7);
            break;
        }
        case ADCHANNEL8:
        {
            ADWINR = _03_AD_ADDR8_15_R_ENABLE;
            *buffer = (uint16_t)(ADDR8);
            break;
        }
        case ADCHANNEL9:
        {
            ADWINR = _03_AD_ADDR8_15_R_ENABLE;
            *buffer = (uint16_t)(ADDR9);
            break;
        }
        case ADCHANNEL10:
        {
            ADWINR = _03_AD_ADDR8_15_R_ENABLE;
            *buffer = (uint16_t)(ADDR10);
            break;
        }
        case ADCHANNEL11:
        {
            ADWINR = _03_AD_ADDR8_15_R_ENABLE;
            *buffer = (uint16_t)(ADDR11);
            break;
        }
        case ADCHANNEL12:
        {
            ADWINR = _03_AD_ADDR8_15_R_ENABLE;
            *buffer = (uint16_t)(ADDR12);
            break;
        }
        case ADCHANNEL13:
        {
            ADWINR = _03_AD_ADDR8_15_R_ENABLE;
            *buffer = (uint16_t)(ADDR13);
            break;
        }
        case ADCHANNEL14:
        {
            ADWINR = _03_AD_ADDR8_15_R_ENABLE;
            *buffer = (uint16_t)(ADDR14);
            break;
        }
        case ADCHANNEL15:
        {
            ADWINR = _03_AD_ADDR8_15_R_ENABLE;
            *buffer = (uint16_t)(ADDR15);
            break;
        }
        case ADCHANNEL16:
        {
            ADWINR = _04_AD_ADDR16_23_R_ENABLE;
            *buffer = (uint16_t)(ADDR16);
            break;
        }
        case ADCHANNEL17:
        {
            ADWINR = _04_AD_ADDR16_23_R_ENABLE;
            *buffer = (uint16_t)(ADDR17);
            break;
        }
        case ADCHANNEL18:
        {
            ADWINR = _04_AD_ADDR16_23_R_ENABLE;
            *buffer = (uint16_t)(ADDR18);
            break;
        }
        case ADCHANNEL19:
        {
            ADWINR = _04_AD_ADDR16_23_R_ENABLE;
            *buffer = (uint16_t)(ADDR19);
            break;
        }
        case ADCHANNEL20:
        {
            ADWINR = _04_AD_ADDR16_23_R_ENABLE;
            *buffer = (uint16_t)(ADDR20);
            break;
        }
        case ADCHANNEL21:
        {
            ADWINR = _04_AD_ADDR16_23_R_ENABLE;
            *buffer = (uint16_t)(ADDR21);
            break;
        }
        case ADCHANNEL22:
        {
            ADWINR = _04_AD_ADDR16_23_R_ENABLE;
            *buffer = (uint16_t)(ADDR22);
            break;
        }
        case ADCHANNEL23:
        {
            ADWINR = _04_AD_ADDR16_23_R_ENABLE;
            *buffer = (uint16_t)(ADDR23);
            break;
        }
        case ADCHANNEL24:
        {
            ADWINR = _05_AD_ADDR24_30_R_ENABLE;
            *buffer = (uint16_t)(ADDR24);
            break;
        }
        case ADCHANNEL25:
        {
            ADWINR = _05_AD_ADDR24_30_R_ENABLE;
            *buffer = (uint16_t)(ADDR25);
            break;
        }
        case ADCHANNEL26:
        {
            ADWINR = _05_AD_ADDR24_30_R_ENABLE;
            *buffer = (uint16_t)(ADDR26);
            break;
        }
        case ADCHANNEL27:
        {
            ADWINR = _05_AD_ADDR24_30_R_ENABLE;
            *buffer = (uint16_t)(ADDR27);
            break;
        }
        case ADCHANNEL28:
        {
            ADWINR = _05_AD_ADDR24_30_R_ENABLE;
            *buffer = (uint16_t)(ADDR28);
            break;
        }
        case ADCHANNEL29:
        {
            ADWINR = _05_AD_ADDR24_30_R_ENABLE;
            *buffer = (uint16_t)(ADDR29);
            break;
        }
        case ADCHANNEL30:
        {
            ADWINR = _05_AD_ADDR24_30_R_ENABLE;
            *buffer = (uint16_t)(ADDR30);
            break;
        }
        case ADINTERREFVOLT:
        {
            ADWINR = _01_AD_REGISTER_GROUP2_RW_ENABLE;
            *buffer = (uint16_t)(ADOCDR);
            break;
        }
        default:
        {
            break;
        }
    }
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
