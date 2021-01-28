/* Copyright (C) Liebherr Werk Nenzing GmbH - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

/**
 * @file li_can_slv_uload_handler.h
 * @brief header to li_can_slv_uload_handler.h module
 * @addtogroup
 * @{
 */

#ifndef LI_CAN_SLV_ULOAD_HANDLER_H_
#define LI_CAN_SLV_ULOAD_HANDLER_H_

#ifdef __cplusplus
extern "C" {
#endif // #ifdef __cplusplus

/*--------------------------------------------------------------------------*/
/* included files                                                           */
/*--------------------------------------------------------------------------*/
#include "li_can_slv.h"

/*--------------------------------------------------------------------------*/
/* general definitions                                                      */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* structure/type definitions                                               */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* global variables                                                         */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* function prototypes                                                      */
/*--------------------------------------------------------------------------*/
#if defined(LI_CAN_SLV_ULOAD)
extern lcsa_errorcode_t uload_info_request_handle(li_can_slv_xload_component_t *uload_component, uint32_t *size_of_component, li_can_slv_xload_end_handle_status_t *status);
extern lcsa_errorcode_t uload_start_request_handle(li_can_slv_xload_component_t *uload_component);
extern lcsa_errorcode_t uload_block_ack_handle(li_can_slv_xload_component_t *uload_component);
#endif // #if defined(LI_CAN_SLV_ULOAD)

#ifdef __cplusplus
}// closing brace for extern "C"
#endif // #ifdef __cplusplus

#endif // #ifndef LI_CAN_SLV_ULOAD_HANDLER_H_

/** @} */
