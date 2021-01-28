/****************************************************************************/
/*                                                                          */
/*                     Copyright (c) 2021, Liebherr PME1                    */
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
 * @file io_app_demo_canpie_test.c
 * @addtogroup app
 * @{
 */

/*--------------------------------------------------------------------------*/
/* include files                                                            */
/*--------------------------------------------------------------------------*/
#include "io_app_config.h"
#include "io_app_demo_hw.h"

#include "canpie.h"
#include "cp_core.h"
#include "cp_msg.h"
#include <string.h>

#include "stdio.h"

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
CpCanMsg_ts myMessage;

CpPort_ts can_port_main;

CpFifo_ts rx_fifo;
CpFifo_ts tx_fifo;
CpCanMsg_ts rx_fifo_messages[16];
CpCanMsg_ts tx_fifo_messages[16];
CpCanMsg_ts tsCanMsgReadT;
uint32_t ulMsgCntT;

CpStatus_tv tvResultT;
uint8_t tx_data[8];
uint32_t pclk;

/*--------------------------------------------------------------------------*/
/* function prototypes (private/not exported)                               */
/*--------------------------------------------------------------------------*/
static uint8_t canpie_rx_handler(CpCanMsg_ts *ptsCanMsgV, uint8_t ubBufferIdxV);
static uint8_t canpie_tx_handler(CpCanMsg_ts *ptsCanMsgV, uint8_t ubBufferIdxV);
static uint8_t canpie_err_handler(CpState_ts *state);

/*--------------------------------------------------------------------------*/
/* function definition (public/exported)                                    */
/*--------------------------------------------------------------------------*/
lcsa_errorcode_t app_init(void)
{
    tx_data[0] = 'C';
    tx_data[1] = 'A';
    tx_data[2] = 'N';
    tx_data[3] = 'P';
    tx_data[4] = 'I';
    tx_data[5] = 'E';
    tx_data[6] = 'F';
    tx_data[7] = 'D';

    pclk = HAL_RCC_GetPCLK1Freq();

    // start initialization

    //----------------------------------------------------------------
    // valid initialization
    //
    memset(&can_port_main, 0, sizeof(CpPort_ts));
    tvResultT = CpCoreDriverInit(eCP_CHANNEL_1, &can_port_main, 0);
    CpCoreIntFunctions(&can_port_main, canpie_rx_handler, canpie_tx_handler, canpie_err_handler);

    CpCoreBitrate(&can_port_main, eCP_BITRATE_125K, eCP_BITRATE_125K);
    CpCoreCanMode(&can_port_main, eCP_MODE_START);

    CpFifoInit(&tx_fifo, &tx_fifo_messages[0], 16);

	//CpCoreBufferConfig(&can_port_main, eCP_BUFFER_11, (uint32_t) 0x123, CP_MASK_STD_FRAME, CP_MSG_FORMAT_CBFF, eCP_BUFFER_DIR_TRM);
	CpCoreBufferConfig(&can_port_main, eCP_BUFFER_11, (uint32_t) 0, CP_MASK_EXT_FRAME, CP_MSG_FORMAT_CEFF, eCP_BUFFER_DIR_TRM);
    CpCoreFifoConfig(&can_port_main, eCP_BUFFER_11, &tx_fifo);

	return LCSA_ERROR_OK;
}

void app_main(void)
{
    //CpCanMsg_ts myMessage;
    uint32_t tmp;

    app_init();

    CpMsgInit(&myMessage, CP_MSG_FORMAT_CBFF);   // initialise message
    CpMsgClear(&myMessage);
    CpMsgSetIdentifier(&myMessage, 100);         // identifier is 100 dec.

    while (1)
    {
    	li_can_slv_port_disable_irq();
    	myMessage.ulMsgUser = ((uint32_t)0x00000001);
        CpMsgSetDlc(&myMessage, 1);
        CpMsgSetData(&myMessage, 0, 0xa);
        CpMsgSetIdentifier(&myMessage, 101);         // identifier is 100 dec.
        CpCoreFifoWrite(&can_port_main, eCP_BUFFER_11,  &myMessage, &tmp);
//        HAL_Delay(1);
        CpMsgSetData(&myMessage, 0, 0xb);
        CpMsgSetIdentifier(&myMessage, 102);         // identifier is 100 dec.
        CpCoreFifoWrite(&can_port_main, eCP_BUFFER_11,  &myMessage, &tmp);
//        HAL_Delay(1);
        CpMsgSetData(&myMessage, 0, 0xc);
        CpMsgSetIdentifier(&myMessage, 103);         // identifier is 100 dec.
        CpCoreFifoWrite(&can_port_main, eCP_BUFFER_11,  &myMessage, &tmp);
//        HAL_Delay(1);
        CpMsgSetData(&myMessage, 0, 0xd);
        CpMsgSetIdentifier(&myMessage, 104);         // identifier is 100 dec.
        CpCoreFifoWrite(&can_port_main, eCP_BUFFER_11,  &myMessage, &tmp);
 //       HAL_Delay(1);
        CpMsgSetData(&myMessage, 0, 0xe);
        CpMsgSetIdentifier(&myMessage, 105);         // identifier is 100 dec.
        CpCoreFifoWrite(&can_port_main, eCP_BUFFER_11,  &myMessage, &tmp);
//        HAL_Delay(1);
        CpMsgSetData(&myMessage, 0, 0xf);
        CpMsgSetIdentifier(&myMessage, 106);         // identifier is 100 dec.
        CpCoreFifoWrite(&can_port_main, eCP_BUFFER_11,  &myMessage, &tmp);


        li_can_slv_port_enable_irq();


        HAL_Delay(1000);
    }

}

lcsa_errorcode_t app_start(void)
{
	return LCSA_ERROR_OK;
}

void app_process_5msec(void)
{

}

/*--------------------------------------------------------------------------*/
/* function definition (private/not exported)                               */
/*--------------------------------------------------------------------------*/
uint8_t canpie_tx_handler(CpCanMsg_ts *ptsCanMsgV, uint8_t ubBufferIdxV)
{
    uint32_t canid = CpMsgGetStdId(ptsCanMsgV);
    printf("\ntx_handler: %d, id: 0x%lx", ubBufferIdxV, canid);
    return 0;
}

uint8_t canpie_rx_handler(CpCanMsg_ts *ptsCanMsgV, uint8_t ubBufferIdxV)
{
    uint32_t canid = CpMsgGetStdId(ptsCanMsgV);
    printf("\nrx: %d, id: 0x%lx, usr:%ld", ubBufferIdxV, canid,
           ptsCanMsgV->ulMsgUser);
    return 0;
}

uint8_t canpie_err_handler(CpState_ts *state)
{
    printf("\ncanpie_err_handler ... ");
    return 0;
}

/** @} */
