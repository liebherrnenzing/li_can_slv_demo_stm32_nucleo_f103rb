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
 * @file li_can_slv_debug.h
 * @brief header to li_can_slv_debug.h module
 * @addtogroup li_can_slv_debug
 * @{
 */

#ifndef LI_CAN_SLV_DEBUG_H_
#define LI_CAN_SLV_DEBUG_H_

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

/*--------------------------------------------------------------------------*/
/* included files                                                           */
/*--------------------------------------------------------------------------*/
#include "li_can_slv_config.h"

/*--------------------------------------------------------------------------*/
/* general definitions                                                      */
/*--------------------------------------------------------------------------*/
#ifdef LI_CAN_SLV_DEBUG
#ifdef ZF_LOG
#define ZF_LOG_LEVEL ZF_LOG_DEBUG
#define ZF_LOG_TAG "LCS"
#include "zf_log.h"
#endif // #ifdef ZF_LOG
#endif // #ifdef LI_CAN_SLV_DEBUG

#define LI_CAN_SLV_DEBUG_PRINT ZF_LOGD
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

#endif // #ifndef LI_CAN_SLV_DEBUG_H_

/** @} */
