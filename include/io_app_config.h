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

#ifndef IO_APP_CONFIG_H_
#define IO_APP_CONFIG_H_

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
#define APP_MA_W
#define APP_MA_W_SIM

//#define APP_MA_W2
#define APP_MA_W_NUM_OF_MODULES 2

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

#endif // #ifndef IO_APP_CONFIG_H_

/** @} */
