/* Copyright (C) Liebherr Werk Nenzing GmbH - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

/**
 * @file li_can_slv_uload_handler.c
 * @brief
 * @addtogroup
 * @{
 */

/*--------------------------------------------------------------------------*/
/* include files                                                            */
/*--------------------------------------------------------------------------*/
#include "li_can_slv_uload_handler.h"
#include "li_can_slv_port.h"

#include "li_can_slv_xload_handler_defines.h"

#ifdef LI_CAN_SLV_TUPLE
#include "io_util.h"
#endif // #ifdef LI_CAN_SLV_TUPLE

#ifdef LI_CAN_SLV_ULOAD
#include "io_os.h"
#endif // #ifdef LI_CAN_SLV_ULOAD

#if defined(OUTER) || defined(OUTER_APP)
#ifdef LI_CAN_SLV_ULOAD
#include "io_os.h"
#endif // #ifdef LI_CAN_SLV_ULOAD
#endif // #if defined(OUTER) || defined(OUTER_APP)

#if defined(OUTER) || defined(OUTER_APP)
#ifdef SMP
#include "io_smp.h"
#endif // #ifdef SMP
#ifdef DLOAD_USE_BGNDCMD
#include "io_bgndcmd.h"
#endif // #ifdef DLOAD_USE_BGNDCMD
#endif // #if defined(OUTER) || defined(OUTER_APP)

/*--------------------------------------------------------------------------*/
/* general definitions (private/not exported)                               */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* structure/type definitions (private/not exported)                        */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* global variables (public/exported)                                       */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* function prototypes (private/not exported)                               */
/*--------------------------------------------------------------------------*/
#ifdef LI_CAN_SLV_ULOAD
#ifdef LI_CAN_SLV_TUPLE
static lcsa_errorcode_t uload_read_tuple_and_send(tuple_id_t tuple_id, li_can_slv_module_nr_t module_nr);
#endif // #ifdef LI_CAN_SLV_TUPLE
static lcsa_errorcode_t uload_data(li_can_slv_module_nr_t module_nr, li_can_slv_xload_component_t *uload_component);
#endif // #ifdef LI_CAN_SLV_ULOAD

/*--------------------------------------------------------------------------*/
/* global variables (private/not exported)                                  */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* function prototypes (private/not exported)                               */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* function definition (public/exported)                                    */
/*--------------------------------------------------------------------------*/
#ifdef LI_CAN_SLV_ULOAD
lcsa_errorcode_t uload_info_request_handle(li_can_slv_xload_component_t *uload_component, uint32_t *size_of_component, li_can_slv_xload_end_handle_status_t *status)
{
	lcsa_errorcode_t err = LCSA_ERROR_OK;
	uint16_t bytes_read = 0;
#ifdef LI_CAN_SLV_TUPLE
	crc16_t crc_of_component = DLOAD_CRC_DEFAULT;
	uint32_t date_of_component = DLOAD_DATE_DEFAULT;
#endif // #ifdef LI_CAN_SLV_TUPLE

	*status = LI_CAN_SLV_XLOAD_STACK_END_HANDLING;

#ifdef LI_CAN_SLV_TUPLE
	err = tuple_read((tuple_id_t) util_hexchar_to_uint32(uload_component->name + 4, 4), (byte_t *) dload_buffer.data, ULOAD_BLOCK_BUFFER_SIZE, &bytes_read, &date_of_component, &crc_of_component);
	if (err != LCSA_ERROR_OK)
	{
		return err;
	}
#endif // #ifdef LI_CAN_SLV_TUPLE

	*size_of_component = bytes_read;
	return (err);
}

/**
 * @param uload_component
 * @return LCSA_ERROR_OK or LCSA_ERROR_DLOAD_UNKNOWN_COMPONENT
 */
lcsa_errorcode_t uload_start_request_handle(li_can_slv_xload_component_t *uload_component)
{
	lcsa_errorcode_t err;

	// component TUPLE
	if (li_can_slv_port_string_n_cmp(uload_component->name, DLOAD_TUPLE, 4) == 0)
	{
		err = uload_data(uload_component->module_nr, uload_component);
	}
	// component: UNKNOWN COMPONENT
	else
	{
		err = LCSA_ERROR_DLOAD_UNKNOWN_COMPONENT;
	}

	return err;
}

/**
 * @param dload_component
 * @return #LCSA_ERROR_OK or #LCSA_ERROR_DLOAD_UNKNOWN_COMPONENT
 */
lcsa_errorcode_t uload_block_ack_handle(li_can_slv_xload_component_t *uload_component)
{
	li_can_slv_errorcode_t rc = LCSA_ERROR_OK;

	// component TUPLE
	if (li_can_slv_port_string_n_cmp(uload_component->name, DLOAD_TUPLE, 4) == 0)
	{
		li_can_slv_uload_end(uload_component->module_nr);
	}

	// component: UNKNOWN COMPONENT
	else
	{
		rc = LCSA_ERROR_DLOAD_UNKNOWN_COMPONENT;
	}

	return rc;
}
#endif // #ifdef LI_CAN_SLV_ULOAD

/*--------------------------------------------------------------------------*/
/* function definition (private/not exported)                               */
/*--------------------------------------------------------------------------*/
#ifdef LI_CAN_SLV_ULOAD
/**
 * @param module_nr of the module for the upload
 * @return #errorcode_t or LCSA_ERROR_OK if successful
 */
static lcsa_errorcode_t uload_data(li_can_slv_module_nr_t module_nr, li_can_slv_xload_component_t *uload_component)
{
	lcsa_errorcode_t rc = LCSA_ERROR_OK;

	uint16_t table_pos, module_found;
	can_config_module_silent_t module_silent;

	/* check if module number valid */
	rc = can_config_module_nr_valid(module_nr, &table_pos, &module_silent, &module_found);
	if (rc != LCSA_ERROR_OK)
	{
		return rc;
	}

#ifdef LI_CAN_SLV_TUPLE
	/*----------------------------------------------------------------------*/
	/* component TUPLE														*/
	/*----------------------------------------------------------------------*/
	if (li_can_slv_port_string_n_cmp(uload_component->name, DLOAD_TUPLE, 4) == 0)
	{
		rc = uload_read_tuple_and_send((tuple_id_t) util_hexchar_to_uint32(uload_component->name + 4, 4), module_nr);
		return rc;
	}
#endif // #ifdef LI_CAN_SLV_TUPLE

	/*----------------------------------------------------------------------*/
	/* component: UNKNOWN COMPONENT											*/
	/*----------------------------------------------------------------------*/
	else
	{
		rc = LCSA_ERROR_DLOAD_UNKNOWN_COMPONENT;
	}
	return rc;
}

#ifdef LI_CAN_SLV_TUPLE
/**
 * @param module_nr number of the module for the upload
 * @return #lcsa_errorcode_t or LCSA_ERROR_OK if successful
 */
static lcsa_errorcode_t uload_read_tuple_and_send(tuple_id_t tuple_id, li_can_slv_module_nr_t module_nr)
{
	lcsa_errorcode_t rc = LCSA_ERROR_OK;
	uint16_t bytes_read;
	crc16_t crc_of_component = DLOAD_CRC_DEFAULT;
	uint32_t date_of_component = DLOAD_DATE_DEFAULT;

#ifdef LI_CAN_SLV_TUPLE
	rc = tuple_read(tuple_id, (byte_t *) dload_buffer.data, ULOAD_BLOCK_BUFFER_SIZE, &bytes_read, &date_of_component, &crc_of_component);
	if (rc != LCSA_ERROR_OK)
	{
		return rc;
	}
#endif // #ifdef LI_CAN_SLV_TUPLE

	rc = li_can_slv_uload_data_from_buffer((byte_t *) dload_buffer.data, bytes_read);

	/* send async data block end */
	rc = li_can_slv_uload_data_block_end(module_nr);
	return rc;
}
#endif // #ifdef LI_CAN_SLV_ULOAD
#endif // #ifdef LI_CAN_SLV_TUPLE

/** @} */
