/****************************************************************************/
/*                                                                          */
/*                     Copyright (c) 2018, Liebherr PME1                    */
/*                         ALL RIGHTS RESERVED                              */
/*                                                                          */
/* This file is part of li_can_slv stack which is free software: you can    */
/* redistribute it and/or modify it under the terms of the GNU General      */
/* Public License as published by the Free Software Foundation, either      */
/* version 3 of the License, or (at your option) any later version.         */
/*                                                                          */
/* The li_can_slv stack is distributed in the hope that it will be useful,  */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of           */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General */
/* Public License for more details.                                         */
/*                                                                          */
/* You should have received a copy of the GNU General Public License which  */
/* should be located in the the root of the Stack. If not, contact Liebherr */
/* to obtain a copy.                                                        */
/****************************************************************************/

/**
 * @file io_app_config.h
 * @brief header to io_app_config.h module
 * @addtogroup app
 * @{
 */

#ifndef IO_APP_IO_APP_CONFIG_H_
#define IO_APP_IO_APP_CONFIG_H_

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

/*--------------------------------------------------------------------------*/
/* included files                                                           */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* general definitions                                                      */
/*--------------------------------------------------------------------------*/
#define APP_PLATFORM_BYTE_ORDER_LITTLE_ENDIAN

/**
 * @name MA_W Module
 */
/** @{ */
//#define APP_MA_W
//#define APP_MA_W_SIM

/** @} */

/**
 * @name STE1 Module
 */
/** @{ */
#define APP_STE1
#define APP_STE1_SIM
#define ERR_APP_STE1_MODULE_ADD_FAILED			(MSG_SG_SHIFT(MSG_SUBGROUP_CAN_APPLICATION) |0x0351u)
/** @} */

/**
 * @name MTE1 Module
 */
/** @{ */
//#define APP_MTE1
//#define APP_MTE1_SIM
//#define ERR_APP_MTE1_MODULE_ADD_FAILED			(MSG_SG_SHIFT(MSG_SUBGROUP_CAN_APPLICATION) |0x0352u)
/** @} */

/*--------------------------------------------------------------------------*/
/* structure/type definitions                                               */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* global variables                                                         */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* function prototypes                                                      */
/*--------------------------------------------------------------------------*/

#ifdef __cplusplus
}// closing brace for extern "C"
#endif // #ifdef __cplusplus

#endif // #ifndef IO_APP_IO_APP_CONFIG_H_

/** @} */
