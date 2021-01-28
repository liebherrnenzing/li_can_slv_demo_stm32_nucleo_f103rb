/* Copyright (C) Liebherr Werk Nenzing GmbH - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

/**
 * @file li_can_slv_dload_handler.c
 * @addtogroup app
 * @{
 */

/*--------------------------------------------------------------------------*/
/* include files                                                            */
/*--------------------------------------------------------------------------*/
#include "li_can_slv_dload_handler.h"
#include "li_can_slv_xload_handler_defines.h"

#include "printf.h"

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

/*--------------------------------------------------------------------------*/
/* global variables (private/not exported)                                  */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* function prototypes (private/not exported)                               */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* function definition (public/exported)                                    */
/*--------------------------------------------------------------------------*/
#ifdef LI_CAN_SLV_USE_ASYNC
/**
 * @param dload_component
 * @return LCSA_ERROR_OK or LCSA_ERROR_DLOAD_UNKNOWN_COMPONENT
 */
lcsa_errorcode_t li_can_slv_dload_start_handle(li_can_slv_xload_component_t *dload_component __attribute__((unused)))
{
	return LCSA_ERROR_DLOAD_UNKNOWN_COMPONENT;
}

/**
 * @param dload_component
 * @param status
 * @return LCSA_ERROR_OK or LCSA_ERROR_DLOAD_UNKNOWN_COMPONENT
 */
lcsa_errorcode_t li_can_slv_dload_version_request_handle(li_can_slv_xload_component_t *dload_component, li_can_slv_xload_end_handle_status_t *status)
{
	lcsa_errorcode_t err;

	*status = LI_CAN_SLV_XLOAD_STACK_END_HANDLING;

	if (li_can_slv_port_string_n_cmp(dload_component->name, DLOAD_TEST, DLOAD_TETT_SIZE) == 0)
	{
		dload_component->crc = DLOAD_CRC_DEFAULT;
		dload_component->download_id = DLOAD_DATE_DEFAULT;
		err = LCSA_ERROR_OK;
	}
	else
	{
		err = LCSA_ERROR_DLOAD_UNKNOWN_COMPONENT;
	}

	return err;
}

/**
 * @param dload_component
 * @return LCSA_ERROR_OK or LCSA_ERROR_DLOAD_UNKNOWN_COMPONENT
 */
lcsa_errorcode_t li_can_slv_dload_start_request_handle(li_can_slv_xload_component_t *dload_component)
{
	lcsa_errorcode_t err = LCSA_ERROR_OK;

	if (li_can_slv_port_string_n_cmp(dload_component->name, DLOAD_TEST, DLOAD_TETT_SIZE) == 0)
	{
		err = li_can_slv_dload_start_ackn(dload_component->module_nr, LI_CAN_SLV_XLOAD_MAX_BYTES_PER_BLOCK_DLOAD, 5u);
	}
	else
	{
		err = LCSA_ERROR_DLOAD_UNKNOWN_COMPONENT;
	}
	return err;
}

/**
 * @param dload_component
 * @return LCSA_ERROR_OK or LCSA_ERROR_DLOAD_UNKNOWN_COMPONENT
 */
lcsa_errorcode_t li_can_slv_dload_data_block_end_handle(li_can_slv_xload_component_t *dload_component)
{
	lcsa_errorcode_t err;
#ifdef LI_CAN_SLV_DLOAD_BUFFER_INTERNAL
	uint16_t number_of_bytes;
	uint8_t data_byte;
	uint16_t i;
#endif // #ifdef LI_CAN_SLV_DLOAD_BUFFER_INTERNAL


	if (li_can_slv_port_string_n_cmp(dload_component->name, DLOAD_TEST, DLOAD_TETT_SIZE) == 0)
	{
#ifdef LI_CAN_SLV_DLOAD_BUFFER_INTERNAL
		xload_buffer_get_len(&number_of_bytes);
		printf("\nnr_bytes: %u", number_of_bytes);
		printf("\n\n");
#endif // #ifdef LI_CAN_SLV_DLOAD_BUFFER_INTERNAL

#ifdef LI_CAN_SLV_DLOAD_BUFFER_INTERNAL
		for (i = 0; i < number_of_bytes; ++i)
		{
			if (xload_buffer_get_byte(&data_byte) != ERR_MSG_CAN_DLOAD_BUF_UNDERFLOW)
			{
				printf("%c", data_byte);
			}
		}
		printf("\n\n");
#endif // #ifdef LI_CAN_SLV_DLOAD_BUFFER_INTERNAL
		err = LCSA_ERROR_OK;
	}
	else
	{
		err = LCSA_ERROR_DLOAD_UNKNOWN_COMPONENT;
	}

	return err;
}

/**
 * @param dload_component
 * @param status
 * @return LCSA_ERROR_OK or LCSA_ERROR_DLOAD_UNKNOWN_COMPONENT
 */
lcsa_errorcode_t li_can_slv_dload_end_handle(li_can_slv_xload_component_t *dload_component, li_can_slv_xload_end_handle_status_t *status)
{
	lcsa_errorcode_t err = LCSA_ERROR_OK;
	*status = LI_CAN_SLV_XLOAD_STACK_END_HANDLING;

	if (li_can_slv_port_string_n_cmp(dload_component->name, DLOAD_TEST, DLOAD_TETT_SIZE) == 0)
	{
		err = LCSA_ERROR_OK;
	}

	return err;
}

#ifdef LI_CAN_SLV_USE_ASYNC_DOWNLOAD_BUFFER_EXTERNAL
lcsa_errorcode_t add_byte_to_buffer(uint8_t data)
{
#ifdef IO_DEBUG_DLOAD
	xputc(data);
#else
	data = data;
#endif // #ifdef IO_DEBUG_DLOAD
	return (LCSA_ERROR_OK);
}
#endif // #ifdef LI_CAN_SLV_USE_ASYNC_DOWNLOAD_BUFFER_EXTERNAL

/*--------------------------------------------------------------------------*/
/* function definition (private/not exported)                               */
/*--------------------------------------------------------------------------*/
#endif // #ifdef LI_CAN_SLV_USE_ASYNC

/** @} */

