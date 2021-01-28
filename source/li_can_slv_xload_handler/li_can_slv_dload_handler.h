/* Copyright (C) Liebherr Werk Nenzing GmbH - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

/**
 * @file li_can_slv_dload_handler.h
 * @brief header to li_can_slv_dload_handler.h module
 * @addtogroup app
 * @{
 */

#ifndef LI_CAN_SLV_DLOAD_HANDLER_H_
#define LI_CAN_SLV_DLOAD_HANDLER_H_

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
#ifdef LI_CAN_SLV_USE_ASYNC
extern lcsa_errorcode_t li_can_slv_dload_start_handle(li_can_slv_xload_component_t *dload_component);
extern lcsa_errorcode_t li_can_slv_dload_version_request_handle(li_can_slv_xload_component_t *dload_component, li_can_slv_xload_end_handle_status_t *status);
extern lcsa_errorcode_t li_can_slv_dload_start_request_handle(li_can_slv_xload_component_t *dload_component);
extern lcsa_errorcode_t li_can_slv_dload_data_block_end_handle(li_can_slv_xload_component_t *dload_component);
extern lcsa_errorcode_t li_can_slv_dload_end_handle(li_can_slv_xload_component_t *dload_component, li_can_slv_xload_end_handle_status_t *status);
#endif // #ifdef LI_CAN_SLV_USE_ASYNC

#ifdef LI_CAN_SLV_USE_ASYNC_DOWNLOAD_BUFFER_EXTERNAL
extern lcsa_errorcode_t add_byte_to_buffer(uint8_t data);
#endif // #ifdef LI_CAN_SLV_USE_ASYNC_DOWNLOAD_BUFFER_EXTERNAL

#ifdef __cplusplus
} // closing brace for extern "C"
#endif // #ifdef __cplusplus

#endif // #ifndef LI_CAN_SLV_DLOAD_HANDLER_H_

/** @} */
