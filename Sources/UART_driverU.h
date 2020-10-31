/*
 * UART_driverU.h
 *
 *  Created on: Oct 31, 2020
 *      Author: isae_
 */

#ifndef UART_DRIVERU_H_
#define UART_DRIVERU_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
//                                      Includes Section
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "MKL25Z4.h"
#include "derivative.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//                                      Define Section
///////////////////////////////////////////////////////////////////////////////////////////////////

#define TRUE (1)
#define FALSE (0)
#define PCR_MUX_PORTC (3)
#define PCR_MUX_PORTE (4)


typedef void(*funcion_de_recieve)(uint8_t);
typedef enum 
{
    kUART_ParityDisabled = 0x0U, /*!< Parity disabled */
    kUART_ParityEven = 0x2U,     /*!< Parity enabled, type even, bit setting: PE|PT = 10 */
    kUART_ParityOdd = 0x3U,      /*!< Parity enabled, type odd,  bit setting: PE|PT = 11 */
} uart_parity_mode_t;

typedef struct 
{
    uint32_t baudRate_Bps;         /*!< UART baud rate  */
    funcion_de_recieve callBack_Rx;
    uart_parity_mode_t parityMode; /*!< Parity mode, disabled (default), even, odd */
    uint8_t enableTx; /*!< Enable TX */
    uint8_t enableRx; /*!< Enable RX */
} uart_config_t;

///////////////////////////////////////////////////////////////////////////////////////////////////
//                                      Functions Section
///////////////////////////////////////////////////////////////////////////////////////////////////

void UART_transmit (uint8_t *transmision,UART_MemMapPtr UART_Tx);
void UART_Init(UART_MemMapPtr base, uart_config_t *config, uint32_t srcClock_Hz);

#endif /* UART_DRIVERU_H_ */
