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
* File Name        : r_cg_ad.h
* Version          : 1.0.30
* Device(s)        : R7F124FPJ5xFB
* Description      : General header file for ADC peripheral.
***********************************************************************************************************************/

#ifndef ADC_H
#define ADC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 0 (PER0)
*/
/* Control over supply of the input clock for the 12-bit A/D converter (ADCEN) */
#define _00_AD_CLOCK_STOP                                (0x00U)    /* stops input clock supply */
#define _20_AD_CLOCK_SUPPLY                              (0x20U)    /* enables input clock supply */

/*
    A/D Control Register (ADCSR)
*/
/* Control of A/D conversion start (ADST) */
#define _0000_AD_CONVERSION_STOP                         (0x0000U)    /* stop A/D conversion process */
#define _8000_AD_CONVERSION_START                        (0x8000U)    /* start A/D conversion process */
/* Selection of scan mode (ADCS1, ADCS0) */
#define _0000_AD_SINGLE_SCAN_MODE                        (0x0000U)    /* single scan mode */
#define _2000_AD_GROUP_SCAN_MODE                         (0x2000U)    /* group scan mode */
#define _4000_AD_CONTINUOUS_SCAN_MODE                    (0x4000U)    /* continuous scan mode */
/* Control of scan end interrupt enable (ADIE) */
#define _0000_AD_SCAN_END_INTERRUPT_DISABLE              (0x0000U)    /* disables INTAD interrupt generation */
#define _1000_AD_SCAN_END_INTERRUPT_ENABLE               (0x1000U)    /* enables INTAD interrupt generation */
/* Control of trigger start enable (TRGE) */
#define _0000_AD_SYNCASYNCTRG_DISABLE                    (0x0000U)    /* disables A/D conversion started by trigger */
#define _0200_AD_SYNCASYNCTRG_ENABLE                     (0x0200U)    /* enables A/D conversion started by trigger */
/* Control of group B scan end interrupt enable (GBADIE) */
#define _0000_AD_GBADIE_DISABLE                          (0x0000U)    /* disables INTADGB interrupt generation */
#define _0040_AD_GBADIE_ENABLE                           (0x0040U)    /* enables INTADGB interrupt generation */

/*
    A/D Channel Select Register A (ADANSA0, ADANSA1)
*/
/* Selection of A/D conversion channel 0 of ADANSA0 (ANSA00) */
#define _0000_AD_ANI0_UNUSED                             (0x0000U)    /* ANI0 is not subjected to conversion */
#define _0001_AD_ANI0_USED                               (0x0001U)    /* ANI0 is subjected to conversion */
#define _0001_AD_ANI0_GROUPA_USED                        (0x0001U)    /* ANI0 is subjected to group A conversion */
/* Selection of A/D conversion channel 1 of ADANSA0 (ANSA01) */
#define _0000_AD_ANI1_UNUSED                             (0x0000U)    /* ANI1 is not subjected to conversion */
#define _0002_AD_ANI1_USED                               (0x0002U)    /* ANI1 is subjected to conversion */
#define _0002_AD_ANI1_GROUPA_USED                        (0x0002U)    /* ANI1 is subjected to group A conversion */
/* Selection of A/D conversion channel 2 of ADANSA0 (ANSA02) */
#define _0000_AD_ANI2_UNUSED                             (0x0000U)    /* ANI2 is not subjected to conversion */
#define _0004_AD_ANI2_USED                               (0x0004U)    /* ANI2 is subjected to conversion */
#define _0004_AD_ANI2_GROUPA_USED                        (0x0004U)    /* ANI2 is subjected to group A conversion */
/* Selection of A/D conversion channel 3 of ADANSA0 (ANSA03) */
#define _0000_AD_ANI3_UNUSED                             (0x0000U)    /* ANI3 is not subjected to conversion */
#define _0008_AD_ANI3_USED                               (0x0008U)    /* ANI3 is subjected to conversion */
#define _0008_AD_ANI3_GROUPA_USED                        (0x0008U)    /* ANI3 is subjected to group A conversion */
/* Selection of A/D conversion channel 4 of ADANSA0 (ANSA04) */
#define _0000_AD_ANI4_UNUSED                             (0x0000U)    /* ANI4 is not subjected to conversion */
#define _0010_AD_ANI4_USED                               (0x0010U)    /* ANI4 is subjected to conversion */
#define _0010_AD_ANI4_GROUPA_USED                        (0x0010U)    /* ANI4 is subjected to group A conversion */
/* Selection of A/D conversion channel 5 of ADANSA0 (ANSA05) */
#define _0000_AD_ANI5_UNUSED                             (0x0000U)    /* ANI5 is not subjected to conversion */
#define _0020_AD_ANI5_USED                               (0x0020U)    /* ANI5 is subjected to conversion */
#define _0020_AD_ANI5_GROUPA_USED                        (0x0020U)    /* ANI5 is subjected to group A conversion */
/* Selection of A/D conversion channel 6 of ADANSA0 (ANSA06) */
#define _0000_AD_ANI6_UNUSED                             (0x0000U)    /* ANI6 is not subjected to conversion */
#define _0040_AD_ANI6_USED                               (0x0040U)    /* ANI6 is subjected to conversion */
#define _0040_AD_ANI6_GROUPA_USED                        (0x0040U)    /* ANI6 is subjected to group A conversion */
/* Selection of A/D conversion channel 7 of ADANSA0 (ANSA07) */
#define _0000_AD_ANI7_UNUSED                             (0x0000U)    /* ANI7 is not subjected to conversion */
#define _0080_AD_ANI7_USED                               (0x0080U)    /* ANI7 is subjected to conversion */
#define _0080_AD_ANI7_GROUPA_USED                        (0x0080U)    /* ANI7 is subjected to group A conversion */
/* Selection of A/D conversion channel 8 of ADANSA0 (ANSA08) */
#define _0000_AD_ANI8_UNUSED                             (0x0000U)    /* ANI8 is not subjected to conversion */
#define _0100_AD_ANI8_USED                               (0x0100U)    /* ANI8 is subjected to conversion */
#define _0100_AD_ANI8_GROUPA_USED                        (0x0100U)    /* ANI8 is subjected to group A conversion */
/* Selection of A/D conversion channel 9 of ADANSA0 (ANSA09) */
#define _0000_AD_ANI9_UNUSED                             (0x0000U)    /* ANI9 is not subjected to conversion */
#define _0200_AD_ANI9_USED                               (0x0200U)    /* ANI9 is subjected to conversion */
#define _0200_AD_ANI9_GROUPA_USED                        (0x0200U)    /* ANI9 is subjected to group A conversion */
/* Selection of A/D conversion channel 10 of ADANSA0 (ANSA010) */
#define _0000_AD_ANI10_UNUSED                            (0x0000U)    /* ANI10 is not subjected to conversion */
#define _0400_AD_ANI10_USED                              (0x0400U)    /* ANI10 is subjected to conversion */
#define _0400_AD_ANI10_GROUPA_USED                       (0x0400U)    /* ANI10 is subjected to group A conversion */
/* Selection of A/D conversion channel 11 of ADANSA0 (ANSA011) */
#define _0000_AD_ANI11_UNUSED                            (0x0000U)    /* ANI11 is not subjected to conversion */
#define _0800_AD_ANI11_USED                              (0x0800U)    /* ANI11 is subjected to conversion */
#define _0800_AD_ANI11_GROUPA_USED                       (0x0800U)    /* ANI11 is subjected to group A conversion */
/* Selection of A/D conversion channel 12 of ADANSA0 (ANSA012) */
#define _0000_AD_ANI12_UNUSED                            (0x0000U)    /* ANI12 is not subjected to conversion */
#define _1000_AD_ANI12_USED                              (0x1000U)    /* ANI12 is subjected to conversion */
#define _1000_AD_ANI12_GROUPA_USED                       (0x1000U)    /* ANI12 is subjected to group A conversion */
/* Selection of A/D conversion channel 13 of ADANSA0 (ANSA013) */
#define _0000_AD_ANI13_UNUSED                            (0x0000U)    /* ANI13 is not subjected to conversion */
#define _2000_AD_ANI13_USED                              (0x2000U)    /* ANI13 is subjected to conversion */
#define _2000_AD_ANI13_GROUPA_USED                       (0x2000U)    /* ANI13 is subjected to group A conversion */
/* Selection of A/D conversion channel 14 of ADANSA0 (ANSA014) */
#define _0000_AD_ANI14_UNUSED                            (0x0000U)    /* ANI14 is not subjected to conversion */
#define _4000_AD_ANI14_USED                              (0x4000U)    /* ANI14 is subjected to conversion */
#define _4000_AD_ANI14_GROUPA_USED                       (0x4000U)    /* ANI14 is subjected to group A conversion */
/* Selection of A/D conversion channel 15 of ADANSA0 (ANSA015) */
#define _0000_AD_ANI15_UNUSED                            (0x0000U)    /* ANI15 is not subjected to conversion */
#define _8000_AD_ANI15_USED                              (0x8000U)    /* ANI15 is subjected to conversion */
#define _8000_AD_ANI15_GROUPA_USED                       (0x8000U)    /* ANI15 is subjected to group A conversion */
/* Selection of A/D conversion channel 16 of ADANSA1 (ANSA016) */
#define _0000_AD_ANI16_UNUSED                            (0x0000U)    /* ANI16 is not subjected to conversion */
#define _0001_AD_ANI16_USED                              (0x0001U)    /* ANI16 is subjected to conversion */
#define _0001_AD_ANI16_GROUPA_USED                       (0x0001U)    /* ANI16 is subjected to group A conversion */
/* Selection of A/D conversion channel 17 of ADANSA1 (ANSA017) */
#define _0000_AD_ANI17_UNUSED                            (0x0000U)    /* ANI17 is not subjected to conversion */
#define _0002_AD_ANI17_USED                              (0x0002U)    /* ANI17 is subjected to conversion */
#define _0002_AD_ANI17_GROUPA_USED                       (0x0002U)    /* ANI17 is subjected to group A conversion */
/* Selection of A/D conversion channel 18 of ADANSA1 (ANSA018) */
#define _0000_AD_ANI18_UNUSED                            (0x0000U)    /* ANI18 is not subjected to conversion */
#define _0004_AD_ANI18_USED                              (0x0004U)    /* ANI18 is subjected to conversion */
#define _0004_AD_ANI18_GROUPA_USED                       (0x0004U)    /* ANI18 is subjected to group A conversion */
/* Selection of A/D conversion channel 19 of ADANSA1 (ANSA019) */
#define _0000_AD_ANI19_UNUSED                            (0x0000U)    /* ANI19 is not subjected to conversion */
#define _0008_AD_ANI19_USED                              (0x0008U)    /* ANI19 is subjected to conversion */
#define _0008_AD_ANI19_GROUPA_USED                       (0x0008U)    /* ANI19 is subjected to group A conversion */
/* Selection of A/D conversion channel 20 of ADANSA1 (ANSA020) */
#define _0000_AD_ANI20_UNUSED                            (0x0000U)    /* ANI20 is not subjected to conversion */
#define _0010_AD_ANI20_USED                              (0x0010U)    /* ANI20 is subjected to conversion */
#define _0010_AD_ANI20_GROUPA_USED                       (0x0010U)    /* ANI20 is subjected to group A conversion */
/* Selection of A/D conversion channel 21 of ADANSA1 (ANSA021) */
#define _0000_AD_ANI21_UNUSED                            (0x0000U)    /* ANI21 is not subjected to conversion */
#define _0020_AD_ANI21_USED                              (0x0020U)    /* ANI21 is subjected to conversion */
#define _0020_AD_ANI21_GROUPA_USED                       (0x0020U)    /* ANI21 is subjected to group A conversion */
/* Selection of A/D conversion channel 22 of ADANSA1 (ANSA022) */
#define _0000_AD_ANI22_UNUSED                            (0x0000U)    /* ANI22 is not subjected to conversion */
#define _0040_AD_ANI22_USED                              (0x0040U)    /* ANI22 is subjected to conversion */
#define _0040_AD_ANI22_GROUPA_USED                       (0x0040U)    /* ANI22 is subjected to group A conversion */
/* Selection of A/D conversion channel 23 of ADANSA1 (ANSA023) */
#define _0000_AD_ANI23_UNUSED                            (0x0000U)    /* ANI23 is not subjected to conversion */
#define _0080_AD_ANI23_USED                              (0x0080U)    /* ANI23 is subjected to conversion */
#define _0080_AD_ANI23_GROUPA_USED                       (0x0080U)    /* ANI23 is subjected to group A conversion */
/* Selection of A/D conversion channel 24 of ADANSA1 (ANSA024) */
#define _0000_AD_ANI24_UNUSED                            (0x0000U)    /* ANI24 is not subjected to conversion */
#define _0100_AD_ANI24_USED                              (0x0100U)    /* ANI24 is subjected to conversion */
#define _0100_AD_ANI24_GROUPA_USED                       (0x0100U)    /* ANI24 is subjected to group A conversion */
/* Selection of A/D conversion channel 25 of ADANSA1 (ANSA025) */
#define _0000_AD_ANI25_UNUSED                            (0x0000U)    /* ANI25 is not subjected to conversion */
#define _0200_AD_ANI25_USED                              (0x0200U)    /* ANI25 is subjected to conversion */
#define _0200_AD_ANI25_GROUPA_USED                       (0x0200U)    /* ANI25 is subjected to group A conversion */
/* Selection of A/D conversion channel 26 of ADANSA1 (ANSA026) */
#define _0000_AD_ANI26_UNUSED                            (0x0000U)    /* ANI26 is not subjected to conversion */
#define _0400_AD_ANI26_USED                              (0x0400U)    /* ANI26 is subjected to conversion */
#define _0400_AD_ANI26_GROUPA_USED                       (0x0400U)    /* ANI26 is subjected to group A conversion */
/* Selection of A/D conversion channel 27 of ADANSA1 (ANSA027) */
#define _0000_AD_ANI27_UNUSED                            (0x0000U)    /* ANI27 is not subjected to conversion */
#define _0800_AD_ANI27_USED                              (0x0800U)    /* ANI27 is subjected to conversion */
#define _0800_AD_ANI27_GROUPA_USED                       (0x0800U)    /* ANI27 is subjected to group A conversion */
/* Selection of A/D conversion channel 28 of ADANSA1 (ANSA028) */
#define _0000_AD_ANI28_UNUSED                            (0x0000U)    /* ANI28 is not subjected to conversion */
#define _1000_AD_ANI28_USED                              (0x1000U)    /* ANI28 is subjected to conversion */
#define _1000_AD_ANI28_GROUPA_USED                       (0x1000U)    /* ANI28 is subjected to group A conversion */
/* Selection of A/D conversion channel 29 of ADANSA1 (ANSA029) */
#define _0000_AD_ANI29_UNUSED                            (0x0000U)    /* ANI29 is not subjected to conversion */
#define _2000_AD_ANI29_USED                              (0x2000U)    /* ANI29 is subjected to conversion */
#define _2000_AD_ANI29_GROUPA_USED                       (0x2000U)    /* ANI29 is subjected to group A conversion */
/* Selection of A/D conversion channel 30 of ADANSA1 (ANSA030) */
#define _0000_AD_ANI30_UNUSED                            (0x0000U)    /* ANI30 is not subjected to conversion */
#define _4000_AD_ANI30_USED                              (0x4000U)    /* ANI30 is subjected to conversion */
#define _4000_AD_ANI30_GROUPA_USED                       (0x4000U)    /* ANI30 is subjected to group A conversion */

/*
    A/D Channel Select Register B (ADANSB0, ADANSB1)
*/
/* Selection of A/D conversion channel 0 of ADANSB0 (ANSB00) */
#define _0000_AD_ANI0_GROUPB_UNUSED                      (0x0000U)    /* ANI0 is not subjected to conversion */
#define _0001_AD_ANI0_GROUPB_USED                        (0x0001U)    /* ANI0 is subjected to conversion */
/* Selection of A/D conversion channel 1 of ADANSB0 (ANSB01) */
#define _0000_AD_ANI1_GROUPB_UNUSED                      (0x0000U)    /* ANI1 is not subjected to conversion */
#define _0002_AD_ANI1_GROUPB_USED                        (0x0002U)    /* ANI1 is subjected to conversion */
/* Selection of A/D conversion channel 2 of ADANSB0 (ANSB02) */
#define _0000_AD_ANI2_GROUPB_UNUSED                      (0x0000U)    /* ANI2 is not subjected to conversion */
#define _0004_AD_ANI2_GROUPB_USED                        (0x0004U)    /* ANI2 is subjected to conversion */
/* Selection of A/D conversion channel 3 of ADANSB0 (ANSB03) */
#define _0000_AD_ANI3_GROUPB_UNUSED                      (0x0000U)    /* ANI3 is not subjected to conversion */
#define _0008_AD_ANI3_GROUPB_USED                        (0x0008U)    /* ANI3 is subjected to conversion */
/* Selection of A/D conversion channel 4 of ADANSB0 (ANSB04) */
#define _0000_AD_ANI4_GROUPB_UNUSED                      (0x0000U)    /* ANI4 is not subjected to conversion */
#define _0010_AD_ANI4_GROUPB_USED                        (0x0010U)    /* ANI4 is subjected to conversion */
/* Selection of A/D conversion channel 5 of ADANSB0 (ANSB05) */
#define _0000_AD_ANI5_GROUPB_UNUSED                      (0x0000U)    /* ANI5 is not subjected to conversion */
#define _0020_AD_ANI5_GROUPB_USED                        (0x0020U)    /* ANI5 is subjected to conversion */
/* Selection of A/D conversion channel 6 of ADANSB0 (ANSB06) */
#define _0000_AD_ANI6_GROUPB_UNUSED                      (0x0000U)    /* ANI6 is not subjected to conversion */
#define _0040_AD_ANI6_GROUPB_USED                        (0x0040U)    /* ANI6 is subjected to conversion */
/* Selection of A/D conversion channel 7 of ADANSB0 (ANSB07) */
#define _0000_AD_ANI7_GROUPB_UNUSED                      (0x0000U)    /* ANI7 is not subjected to conversion */
#define _0080_AD_ANI7_GROUPB_USED                        (0x0080U)    /* ANI7 is subjected to conversion */
/* Selection of A/D conversion channel 8 of ADANSB0 (ANSB08) */
#define _0000_AD_ANI8_GROUPB_UNUSED                      (0x0000U)    /* ANI8 is not subjected to conversion */
#define _0100_AD_ANI8_GROUPB_USED                        (0x0100U)    /* ANI8 is subjected to conversion */
/* Selection of A/D conversion channel 9 of ADANSB0 (ANSB09) */
#define _0000_AD_ANI9_GROUPB_UNUSED                      (0x0000U)    /* ANI9 is not subjected to conversion */
#define _0200_AD_ANI9_GROUPB_USED                        (0x0200U)    /* ANI9 is subjected to conversion */
/* Selection of A/D conversion channel 10 of ADANSB0 (ANSB010) */
#define _0000_AD_ANI10_GROUPB_UNUSED                     (0x0000U)    /* ANI10 is not subjected to conversion */
#define _0400_AD_ANI10_GROUPB_USED                       (0x0400U)    /* ANI10 is subjected to conversion */
/* Selection of A/D conversion channel 11 of ADANSB0 (ANSB011) */
#define _0000_AD_ANI11_GROUPB_UNUSED                     (0x0000U)    /* ANI11 is not subjected to conversion */
#define _0800_AD_ANI11_GROUPB_USED                       (0x0800U)    /* ANI11 is subjected to conversion */
/* Selection of A/D conversion channel 12 of ADANSB0 (ANSB012) */
#define _0000_AD_ANI12_GROUPB_UNUSED                     (0x0000U)    /* ANI12 is not subjected to conversion */
#define _1000_AD_ANI12_GROUPB_USED                       (0x1000U)    /* ANI12 is subjected to conversion */
/* Selection of A/D conversion channel 13 of ADANSB0 (ANSB013) */
#define _0000_AD_ANI13_GROUPB_UNUSED                     (0x0000U)    /* ANI13 is not subjected to conversion */
#define _2000_AD_ANI13_GROUPB_USED                       (0x2000U)    /* ANI13 is subjected to conversion */
/* Selection of A/D conversion channel 14 of ADANSB0 (ANSB014) */
#define _0000_AD_ANI14_GROUPB_UNUSED                     (0x0000U)    /* ANI14 is not subjected to conversion */
#define _4000_AD_ANI14_GROUPB_USED                       (0x4000U)    /* ANI14 is subjected to conversion */
/* Selection of A/D conversion channel 15 of ADANSB0 (ANSB015) */
#define _0000_AD_ANI15_GROUPB_UNUSED                     (0x0000U)    /* ANI15 is not subjected to conversion */
#define _8000_AD_ANI15_GROUPB_USED                       (0x8000U)    /* ANI15 is subjected to conversion */
/* Selection of A/D conversion channel 16 of ADANSB1 (ANSB016) */
#define _0000_AD_ANI16_GROUPB_UNUSED                     (0x0000U)    /* ANI16 is not subjected to conversion */
#define _0001_AD_ANI16_GROUPB_USED                       (0x0001U)    /* ANI16 is subjected to conversion */
/* Selection of A/D conversion channel 17 of ADANSB1 (ANSB017) */
#define _0000_AD_ANI17_GROUPB_UNUSED                     (0x0000U)    /* ANI17 is not subjected to conversion */
#define _0002_AD_ANI17_GROUPB_USED                       (0x0002U)    /* ANI17 is subjected to conversion */
/* Selection of A/D conversion channel 18 of ADANSB1 (ANSB018) */
#define _0000_AD_ANI18_GROUPB_UNUSED                     (0x0000U)    /* ANI18 is not subjected to conversion */
#define _0004_AD_ANI18_GROUPB_USED                       (0x0004U)    /* ANI18 is subjected to conversion */
/* Selection of A/D conversion channel 19 of ADANSB1 (ANSB019) */
#define _0000_AD_ANI19_GROUPB_UNUSED                     (0x0000U)    /* ANI19 is not subjected to conversion */
#define _0008_AD_ANI19_GROUPB_USED                       (0x0008U)    /* ANI19 is subjected to conversion */
/* Selection of A/D conversion channel 20 of ADANSB1 (ANSB020) */
#define _0000_AD_ANI20_GROUPB_UNUSED                     (0x0000U)    /* ANI20 is not subjected to conversion */
#define _0010_AD_ANI20_GROUPB_USED                       (0x0010U)    /* ANI20 is subjected to conversion */
/* Selection of A/D conversion channel 21 of ADANSB1 (ANSB021) */
#define _0000_AD_ANI21_GROUPB_UNUSED                     (0x0000U)    /* ANI21 is not subjected to conversion */
#define _0020_AD_ANI21_GROUPB_USED                       (0x0020U)    /* ANI21 is subjected to conversion */
/* Selection of A/D conversion channel 22 of ADANSB1 (ANSB022) */
#define _0000_AD_ANI22_GROUPB_UNUSED                     (0x0000U)    /* ANI22 is not subjected to conversion */
#define _0040_AD_ANI22_GROUPB_USED                       (0x0040U)    /* ANI22 is subjected to conversion */
/* Selection of A/D conversion channel 23 of ADANSB1 (ANSB023) */
#define _0000_AD_ANI23_GROUPB_UNUSED                     (0x0000U)    /* ANI23 is not subjected to conversion */
#define _0080_AD_ANI23_GROUPB_USED                       (0x0080U)    /* ANI23 is subjected to conversion */
/* Selection of A/D conversion channel 24 of ADANSB1 (ANSB024) */
#define _0000_AD_ANI24_GROUPB_UNUSED                     (0x0000U)    /* ANI24 is not subjected to conversion */
#define _0100_AD_ANI24_GROUPB_USED                       (0x0100U)    /* ANI24 is subjected to conversion */
/* Selection of A/D conversion channel 25 of ADANSB1 (ANSB025) */
#define _0000_AD_ANI25_GROUPB_UNUSED                     (0x0000U)    /* ANI25 is not subjected to conversion */
#define _0200_AD_ANI25_GROUPB_USED                       (0x0200U)    /* ANI25 is subjected to conversion */
/* Selection of A/D conversion channel 26 of ADANSB1 (ANSB026) */
#define _0000_AD_ANI26_GROUPB_UNUSED                     (0x0000U)    /* ANI26 is not subjected to conversion */
#define _0400_AD_ANI26_GROUPB_USED                       (0x0400U)    /* ANI26 is subjected to conversion */
/* Selection of A/D conversion channel 27 of ADANSB1 (ANSB027) */
#define _0000_AD_ANI27_GROUPB_UNUSED                     (0x0000U)    /* ANI27 is not subjected to conversion */
#define _0800_AD_ANI27_GROUPB_USED                       (0x0800U)    /* ANI27 is subjected to conversion */
/* Selection of A/D conversion channel 28 of ADANSB1 (ANSB028) */
#define _0000_AD_ANI28_GROUPB_UNUSED                     (0x0000U)    /* ANI28 is not subjected to conversion */
#define _1000_AD_ANI28_GROUPB_USED                       (0x1000U)    /* ANI28 is subjected to conversion */
/* Selection of A/D conversion channel 29 of ADANSB1 (ANSB029) */
#define _0000_AD_ANI29_GROUPB_UNUSED                     (0x0000U)    /* ANI29 is not subjected to conversion */
#define _2000_AD_ANI29_GROUPB_USED                       (0x2000U)    /* ANI29 is subjected to conversion */
/* Selection of A/D conversion channel 30 of ADANSB1 (ANSB030) */
#define _0000_AD_ANI30_GROUPB_UNUSED                     (0x0000U)    /* ANI30 is not subjected to conversion */
#define _4000_AD_ANI30_GROUPB_USED                       (0x4000U)    /* ANI30 is subjected to conversion */

/*
    A/D-converted Value Addition/Average Function Channel Select Register (ADADS0, ADADS1)
*/
/* Selection of A/D-converted value addition/average channel 0 of ADADS0 (ADS00) */
#define _0000_AD_ANI0_ADD_UNUSED                         (0x0000U)    /* ANI0 addition/average mode is not used */
#define _0001_AD_ANI0_ADD_USED                           (0x0001U)    /* ANI0 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 1 of ADADS0 (ADS01) */
#define _0000_AD_ANI1_ADD_UNUSED                         (0x0000U)    /* ANI1 addition/average mode is not used */
#define _0002_AD_ANI1_ADD_USED                           (0x0002U)    /* ANI1 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 2 of ADADS0 (ADS02) */
#define _0000_AD_ANI2_ADD_UNUSED                         (0x0000U)    /* ANI2 addition/average mode is not used */
#define _0004_AD_ANI2_ADD_USED                           (0x0004U)    /* ANI2 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 3 of ADADS0 (ADS03) */
#define _0000_AD_ANI3_ADD_UNUSED                         (0x0000U)    /* ANI3 addition/average mode is not used */
#define _0008_AD_ANI3_ADD_USED                           (0x0008U)    /* ANI3 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 4 of ADADS0 (ADS04) */
#define _0000_AD_ANI4_ADD_UNUSED                         (0x0000U)    /* ANI4 addition/average mode is not used */
#define _0010_AD_ANI4_ADD_USED                           (0x0010U)    /* ANI4 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 5 of ADADS0 (ADS05) */
#define _0000_AD_ANI5_ADD_UNUSED                         (0x0000U)    /* ANI5 addition/average mode is not used */
#define _0020_AD_ANI5_ADD_USED                           (0x0020U)    /* ANI5 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 6 of ADADS0 (ADS06) */
#define _0000_AD_ANI6_ADD_UNUSED                         (0x0000U)    /* ANI6 addition/average mode is not used */
#define _0040_AD_ANI6_ADD_USED                           (0x0040U)    /* ANI6 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 7 of ADADS0 (ADS07) */
#define _0000_AD_ANI7_ADD_UNUSED                         (0x0000U)    /* ANI7 addition/average mode is not used */
#define _0080_AD_ANI7_ADD_USED                           (0x0080U)    /* ANI7 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 8 of ADADS0 (ADS08) */
#define _0000_AD_ANI8_ADD_UNUSED                         (0x0000U)    /* ANI8 addition/average mode is not used */
#define _0100_AD_ANI8_ADD_USED                           (0x0100U)    /* ANI8 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 9 of ADADS0 (ADS09) */
#define _0000_AD_ANI9_ADD_UNUSED                         (0x0000U)    /* ANI9 addition/average mode is not used */
#define _0200_AD_ANI9_ADD_USED                           (0x0200U)    /* ANI9 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 10 of ADADS0 (ADS010) */
#define _0000_AD_ANI10_ADD_UNUSED                        (0x0000U)    /* ANI10 addition/average mode is not used */
#define _0400_AD_ANI10_ADD_USED                          (0x0400U)    /* ANI10 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 11 of ADADS0 (ADS011) */
#define _0000_AD_ANI11_ADD_UNUSED                        (0x0000U)    /* ANI11 addition/average mode is not used */
#define _0800_AD_ANI11_ADD_USED                          (0x0800U)    /* ANI11 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 12 of ADADS0 (ADS012) */
#define _0000_AD_ANI12_ADD_UNUSED                        (0x0000U)    /* ANI12 addition/average mode is not used */
#define _1000_AD_ANI12_ADD_USED                          (0x1000U)    /* ANI12 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 13 of ADADS0 (ADS013) */
#define _0000_AD_ANI13_ADD_UNUSED                        (0x0000U)    /* ANI13 addition/average mode is not used */
#define _2000_AD_ANI13_ADD_USED                          (0x2000U)    /* ANI13 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 14 of ADADS0 (ADS014) */
#define _0000_AD_ANI14_ADD_UNUSED                        (0x0000U)    /* ANI14 addition/average mode is not used */
#define _4000_AD_ANI14_ADD_USED                          (0x4000U)    /* ANI14 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 15 of ADADS0 (ADS015) */
#define _0000_AD_ANI15_ADD_UNUSED                        (0x0000U)    /* ANI15 addition/average mode is not used */
#define _8000_AD_ANI15_ADD_USED                          (0x8000U)    /* ANI15 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 16 of ADADS1 (ADS016) */
#define _0000_AD_ANI16_ADD_UNUSED                        (0x0000U)    /* ANI16 addition/average mode is not used */
#define _0001_AD_ANI16_ADD_USED                          (0x0001U)    /* ANI16 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 17 of ADADS1 (ADS017) */
#define _0000_AD_ANI17_ADD_UNUSED                        (0x0000U)    /* ANI17 addition/average mode is not used */
#define _0002_AD_ANI17_ADD_USED                          (0x0002U)    /* ANI17 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 18 of ADADS1 (ADS018) */
#define _0000_AD_ANI18_ADD_UNUSED                        (0x0000U)    /* ANI18 addition/average mode is not used */
#define _0004_AD_ANI18_ADD_USED                          (0x0004U)    /* ANI18 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 19 of ADADS1 (ADS019) */
#define _0000_AD_ANI19_ADD_UNUSED                        (0x0000U)    /* ANI19 addition/average mode is not used */
#define _0008_AD_ANI19_ADD_USED                          (0x0008U)    /* ANI19 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 20 of ADADS1 (ADS020) */
#define _0000_AD_ANI20_ADD_UNUSED                        (0x0000U)    /* ANI20 addition/average mode is not used */
#define _0010_AD_ANI20_ADD_USED                          (0x0010U)    /* ANI20 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 21 of ADADS1 (ADS021) */
#define _0000_AD_ANI21_ADD_UNUSED                        (0x0000U)    /* ANI21 addition/average mode is not used */
#define _0020_AD_ANI21_ADD_USED                          (0x0020U)    /* ANI21 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 22 of ADADS1 (ADS022) */
#define _0000_AD_ANI22_ADD_UNUSED                        (0x0000U)    /* ANI22 addition/average mode is not used */
#define _0040_AD_ANI22_ADD_USED                          (0x0040U)    /* ANI22 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 23 of ADADS1 (ADS023) */
#define _0000_AD_ANI23_ADD_UNUSED                        (0x0000U)    /* ANI23 addition/average mode is not used */
#define _0080_AD_ANI23_ADD_USED                          (0x0080U)    /* ANI23 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 24 of ADADS1 (ADS024) */
#define _0000_AD_ANI24_ADD_UNUSED                        (0x0000U)    /* ANI24 addition/average mode is not used */
#define _0100_AD_ANI24_ADD_USED                          (0x0100U)    /* ANI24 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 25 of ADADS1 (ADS025) */
#define _0000_AD_ANI25_ADD_UNUSED                        (0x0000U)    /* ANI25 addition/average mode is not used */
#define _0200_AD_ANI25_ADD_USED                          (0x0200U)    /* ANI25 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 26 of ADADS1 (ADS026) */
#define _0000_AD_ANI26_ADD_UNUSED                        (0x0000U)    /* ANI26 addition/average mode is not used */
#define _0400_AD_ANI26_ADD_USED                          (0x0400U)    /* ANI26 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 27 of ADADS1 (ADS027) */
#define _0000_AD_ANI27_ADD_UNUSED                        (0x0000U)    /* ANI27 addition/average mode is not used */
#define _0800_AD_ANI27_ADD_USED                          (0x0800U)    /* ANI27 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 28 of ADADS1 (ADS028) */
#define _0000_AD_ANI28_ADD_UNUSED                        (0x0000U)    /* ANI28 addition/average mode is not used */
#define _1000_AD_ANI28_ADD_USED                          (0x1000U)    /* ANI28 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 29 of ADADS1 (ADS029) */
#define _0000_AD_ANI29_ADD_UNUSED                        (0x0000U)    /* ANI29 addition/average mode is not used */
#define _2000_AD_ANI29_ADD_USED                          (0x2000U)    /* ANI29 addition/average mode is used */
/* Selection of A/D-converted value addition/average channel 30 of ADADS1 (ADS030) */
#define _0000_AD_ANI30_ADD_UNUSED                        (0x0000U)    /* ANI30 addition/average mode is not used */
#define _4000_AD_ANI30_ADD_USED                          (0x4000U)    /* ANI30 addition/average mode is used */

/*
    A/D-converted Value Addition/Average Count Select Register (ADADC)
*/
/* Control of average mode enable (AVEE) */
#define _00_AD_ADDITION_MODE                             (0x00U)    /* addition mode is selected */
#define _80_AD_AVERAGE_MODE                              (0x80U)    /* average mode is selected */
/* Setting of addition count selection (ADC2 - ADC0) */
#define _00_AD_1_TIME_CONVERSION                         (0x00U)    /* 1-time conversion (no addition) */
#define _01_AD_2_TIME_CONVERSION                         (0x01U)    /* 2-time conversion (addition once) */
#define _02_AD_3_TIME_CONVERSION                         (0x02U)    /* 3-time conversion (addition twice) */
#define _03_AD_4_TIME_CONVERSION                         (0x03U)    /* 4-time conversion (addition three times) */
#define _05_AD_16_TIME_CONVERSION                        (0x05U)    /* 16-time conversion (addition 15 times) */

/*
    A/D Control Extended Register (ADCER)
*/
/* Selection of A/D data register format (ADRFMT) */
#define _0000_AD_RIGHT_ALIGNMENT                         (0x0000U)    /* right aligned is selected */
#define _8000_AD_LEFT_ALIGNMENT                          (0x8000U)    /* left aligned is selected */
/* Setting of self-diagnosis enable/disable (DIAGM) */
#define _0000_AD_SELFDIAG_DISABLE                        (0x0000U)    /* disables self-diagnosis */
#define _0800_AD_SELFDIAG_ENABLE                         (0x0800U)    /* enables self-diagnosis */
/* Setting of self-diagnosis mode select (DIAGLD) */
#define _0400_AD_SELFDIAG_FIXED_MODE                     (0x0400U)    /* fixed mode for self-diagnosis voltage */
/* Setting of self-diagnosis conversion voltage (DIAGVAL1, DIAGVAL0) */
#define _0100_AD_SELFDIAG_0V                             (0x0100U)    /* uses 0V (low-potential reference voltage) */
#define _0200_AD_SELFDIAG_VREFH0_HALF                    (0x0200U)    /* uses high-potential reference voltage half */
#define _0300_AD_SELFDIAG_VREFH0                         (0x0300U)    /* uses high-potential reference voltage */
/* Setting of A/D data register automatic clearing enable/disable (ACE) */
#define _0000_AD_AUTO_CLEARING_DISABLE                   (0x0000U)    /* disables automatic clearing */
#define _0020_AD_AUTO_CLEARING_ENABLE                    (0x0020U)    /* enables automatic clearing */

/*
    A/D Conversion Start Trigger Select Register (ADSTRGR)
*/
/* Selection of A/D conversion start synchronous trigger (TRSA5 - TRSA0) */
#define _0100_AD_TRSA_INTTM01                            (0x0100U)    /* INTTM01 (TAU0 ch1 interrupt) */
#define _0200_AD_TRSA_INTRTC                             (0x0200U)    /* INTRTC (RTC interrupt) */
#define _0300_AD_TRSA_INTTRJ0                            (0x0300U)    /* INTTRJ0 (TRG0 interrupt) */
#define _0400_AD_TRSA_INTTRD0_IFA                        (0x0400U)    /* INTTRD0_IFA (TRD0 interrupt) */
#define _0500_AD_TRSA_INTTRD0_IFB                        (0x0500U)    /* INTTRD0_IFB (TRD0 interrupt) */
#define _0600_AD_TRSA_INTTRD1_IFA                        (0x0600U)    /* INTTRD1_IFA (TRD1 interrupt) */
#define _0700_AD_TRSA_INTTRD1_IFB                        (0x0700U)    /* INTTRD1_IFB (TRD1 interrupt) */
#define _0800_AD_TRSA_INTTRD1_UDF                        (0x0800U)    /* INTTRD1_UDF(TRD1 under flow) */
#define _0B00_AD_TRSA_INTTRD_ADTRG                       (0x0B00U)    /* INTTRD_ADTRG (TRD A/D trigger request) */
#define _3000_AD_TRSA_ELCTRG0                            (0x3000U)    /* ELCTRG0 (event output signal from ELC) */
#define _3F00_AD_TRSA_SYNCTRG_DISABLE                    (0x3F00U)    /* disables synchronous trigger */
/* Selection of A/D conversion start synchronous trigger (TRSB5 - TRSB0) */
#define _0001_AD_TRSB_INTTM01                            (0x0001U)    /* INTTM01 (TAU0 ch1 interrupt) */
#define _0002_AD_TRSB_INTRTC                             (0x0002U)    /* INTRTC (RTC interrupt) */
#define _0003_AD_TRSB_INTTRJ0                            (0x0003U)    /* INTTRJ0 (TRG0 interrupt) */
#define _0004_AD_TRSB_INTTRD0_IFA                        (0x0004U)    /* INTTRD0_IFA (TRD0 interrupt) */
#define _0005_AD_TRSB_INTTRD0_IFB                        (0x0005U)    /* INTTRD0_IFB (TRD0 interrupt) */
#define _0006_AD_TRSB_INTTRD1_IFA                        (0x0006U)    /* INTTRD1_IFA (TRD1 interrupt) */
#define _0007_AD_TRSB_INTTRD1_IFB                        (0x0007U)    /* INTTRD1_IFB (TRD1 interrupt) */
#define _0008_AD_TRSB_INTTRD1_UDF                        (0x0008U)    /* INTTRD1_UDF(TRD1 under flow) */
#define _000B_AD_TRSB_INTTRD_ADTRG                       (0x000BU)    /* INTTRD_ADTRG (TRD A/D trigger request) */
#define _0030_AD_TRSB_ELCTRG0                            (0x0030U)    /* ELCTRG0 (event output signal from ELC) */
#define _003F_AD_TRSB_SYNCTRG_DISABLE                    (0x003FU)    /* disables synchronous trigger */

/*
    A/D Conversion Extended Input Control Register (ADEXICR)
*/
/* Selection of internal reference voltage (VBGR) conversion (OCSA) */
#define _0000_AD_IREF_UNUSED                             (0x0000U)    /* internal reference voltage is not used */
#define _0200_AD_IREF_USED                               (0x0200U)    /* internal reference voltage is used */

/*
    A/D Sample-and-Hold Circuit Control Register (ADSHCR)
*/
/* Control of ANI2 channel-dedicated sample-and-hold circuit bypass (SHANS2) */
#define _0000_AD_DSH_ANI2_UNSELECT                       (0x0000U)    /* A/D sample-and-hold circuit is not used */
#define _0400_AD_DSH_ANI2_SELECT                         (0x0400U)    /* A/D sample-and-hold circuit is used */
/* Control of ANI1 channel-dedicated sample-and-hold circuit bypass (SHANS1) */
#define _0000_AD_DSH_ANI1_UNSELECT                       (0x0000U)    /* A/D sample-and-hold circuit is not used */
#define _0200_AD_DSH_ANI1_SELECT                         (0x0200U)    /* A/D sample-and-hold circuit is used */

/*
    A/D Disconnection Detection Control Register (ADDISCR)
*/
/* Setting of precharge/discharge selection (ADNDIS4) */
#define _00_AD_DISCONNECT_DISCHARGE                      (0x00U)    /* discharge select */
#define _10_AD_DISCONNECT_PRECHARGE                      (0x10U)    /* precharge select */
/* Period of precharge/discharge (ADNDIS3 - ADNDIS0) */
#define _00_AD_DISCONNECT_UNUSED                         (0x00U)    /* disables the disconnection detection assist */
#define _02_AD_DISCONNECT_2ADCLK                         (0x02U)    /* 2 cycles (2/ADCLK) */
#define _03_AD_DISCONNECT_3ADCLK                         (0x03U)    /* 3 cycles (3/ADCLK) */
#define _04_AD_DISCONNECT_4ADCLK                         (0x04U)    /* 4 cycles (4/ADCLK) */
#define _05_AD_DISCONNECT_5ADCLK                         (0x05U)    /* 5 cycles (5/ADCLK) */
#define _06_AD_DISCONNECT_6ADCLK                         (0x06U)    /* 6 cycles (6/ADCLK) */
#define _07_AD_DISCONNECT_7ADCLK                         (0x07U)    /* 7 cycles (7/ADCLK) */
#define _08_AD_DISCONNECT_8ADCLK                         (0x08U)    /* 8 cycles (8/ADCLK) */
#define _09_AD_DISCONNECT_9ADCLK                         (0x09U)    /* 9 cycles (9/ADCLK) */
#define _0A_AD_DISCONNECT_10ADCLK                        (0x0AU)    /* 10 cycles (10/ADCLK) */
#define _0B_AD_DISCONNECT_11ADCLK                        (0x0BU)    /* 11 cycles (11/ADCLK) */
#define _0C_AD_DISCONNECT_12ADCLK                        (0x0CU)    /* 12 cycles (12/ADCLK) */
#define _0D_AD_DISCONNECT_13ADCLK                        (0x0DU)    /* 13 cycles (13/ADCLK) */
#define _0E_AD_DISCONNECT_14ADCLK                        (0x0EU)    /* 14 cycles (14/ADCLK) */
#define _0F_AD_DISCONNECT_15ADCLK                        (0x0FU)    /* 15 cycles (15/ADCLK) */

/*
    A/D Group Scan Priority Control Register (ADGSPCR)
*/
/* Control of single scan continuous start (GBRP) */
#define _0000_AD_GPBSCSCS_DISABLE                        (0x0000U)    /* single scan is not continuously activated */
#define _8000_AD_GPBSCSCS_ENABLE                         (0x8000U)    /* single scan is continuously activated */
/* Setting of restart channel selection (LGRRS) */
#define _0000_AD_GPBRESTART_FIRST                        (0x0000U)    /* start rescanning from the first channel */
#define _4000_AD_GPBRESTART_INCOMPLETE                   (0x4000U)    /* start rescanning is not completed */
/* Setting of lower-priority group restart (GBRSCN) */
#define _0000_AD_GPBRESTART_DISABLE                      (0x0000U)    /* disable rescanning of the stopped group */
#define _0002_AD_GPBRESTART_ENABLE                       (0x0002U)    /* enable rescanning of the stopped group */
/* Setting of group priority operation (PGS) */
#define _0000_AD_GPAPRIORITY_DISABLE                     (0x0000U)    /* operate without group priority control */
#define _0001_AD_GPAPRIORITY_ENABLE                      (0x0001U)    /* operate with group priority control */

/*
    A/D High-/Low-potential Reference Voltage Control Register (ADHVREFCNT)
*/
/* Selection of A/D analog block standby state (ADSLP) */
#define _00_AD_ANALOG_BLOCK_NORMAL                       (0x00U)    /* Normal operation */
#define _80_AD_ANALOG_BLOCK_STANDBY                      (0x80U)    /* A/D analog block standby state */
/* Selection of low-potential reference voltage (LVSEL) */
#define _00_AD_LOW_POTENTIAL_VSS                         (0x00U)    /* VSS is selected */
#define _10_AD_LOW_POTENTIAL_AVREFM                      (0x10U)    /* AVREFM is selected */
/* Selection of high-potential reference voltage (HVSEL) */
#define _00_AD_HIGH_POTENTIAL_VDD                        (0x00U)    /* VDD is selected */
#define _01_AD_HIGH_POTENTIAL_AVREFP                     (0x01U)    /* AVREFP is selected */

/*
    A/D Conversion Clock Control Register (ADCKS)
*/
/* Selects A/D conversion clock (ADCK1 - ADCK0) */
#define _00_AD_CONVERSION_CLOCK                          (0x00U)    /* non divided (fCLK) */
#define _01_AD_CONVERSION_CLOCK_2                        (0x01U)    /* divided by 2 (fCLK/2) */
#define _02_AD_CONVERSION_CLOCK_4                        (0x02U)    /* divided by 4 (fCLK/4) */
#define _03_AD_CONVERSION_CLOCK_8                        (0x03U)    /* divided by 8 (fCLK/8) */

/*
    A/D Converter Access Window Register (ADWINR)
*/
/* Selection of A/D converter access window bit (ADPAGE3 - ADPAGE0) */
#define _00_AD_REGISTER_GROUP1_RW_ENABLE                 (0x00U)    /* enables r/w access for ADCSR, ADANSA0,
                                                                       ADANSA1, ADADS0, ADADS1, ADADC, and ADCER */
#define _01_AD_REGISTER_GROUP2_RW_ENABLE                 (0x01U)    /* enables r/w access for ADSTRGR, ADEXICR,
                                                                       ADANSB0, ADANSB1, ADOCDR, and ADRD */
#define _02_AD_ADDR0_7_R_ENABLE                          (0x02U)    /* enables r access for ADDR0 to ADDR7 */
#define _03_AD_ADDR8_15_R_ENABLE                         (0x03U)    /* enables r access for ADDR8 to ADDR15 */
#define _04_AD_ADDR16_23_R_ENABLE                        (0x04U)    /* enables r access for ADDR16 to ADDR23 */
#define _05_AD_ADDR24_30_R_ENABLE                        (0x05U)    /* enables r access for ADDR24 to ADDR30 */
#define _06_AD_ADSHCR_RW_ENABLE                          (0x06U)    /* enables r/w access for ADSHCR */
#define _07_AD_ADDISCR_RW_ENABLE                         (0x07U)    /* enables r/w access for ADDISCR */
#define _08_AD_ADGSPCR_ADHVREFCNT_RW_ENABLE              (0x08U)    /* enables r/w access for ADGSPCR and ADHVREFCNT */
#define _0D_AD_ADSSTRL_ADSSTRO_RW_ENABLE                 (0x0DU)    /* enables r/w access for ADSSTRL and ADSSTRO */
#define _0E_AD_ADSSTR0_15_RW_ENABLE                      (0x0EU)    /* enables r/w access for ADSSTR0 to ADSSTR15) */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif

