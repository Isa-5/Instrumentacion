/*
 * UART_driverU.c
 *
 *  Created on: Oct 31, 2020
 *      Author: isae_
 */


///////////////////////////////////////////////////////////////////////////////////////////////////
//                                      Includes Section
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "UART_driverU.h"
#include "MKL25Z4.h"
#include "derivative.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//                                      Variable Section
///////////////////////////////////////////////////////////////////////////////////////////////////

uint8_t *transmisiongbl;
funcion_de_recieve data_recieve1;
funcion_de_recieve data_recieve2;

///////////////////////////////////////////////////////////////////////////////////////////////////
//                                      Functions Section
///////////////////////////////////////////////////////////////////////////////////////////////////

void UART_Init(UART_MemMapPtr base, funcion_de_recieve call_back , uint32_t srcClock_Hz, uint32_t baud_rate)
{
	if ((base==UART1_BASE_PTR)||(base==UART2_BASE_PTR))//seguridad, solamente si selecciono parametros validos se escribo sino no hace nada
	{
		uint16_t sbr = 0; //Campo en reference manual, campo 13 bits 5BDH 8BDL pag.762  
		uint8_t temp = 0;

		/* Calculate the baud rate modulo divisor, sbr*/
		sbr = srcClock_Hz / (baud_rate * 16);
		

		if (base==UART1_BASE_PTR ) //init UART1
		{
			SIM_SCGC5|= SIM_SCGC5_PORTC_MASK; //PTC 3Rx y 4Tx ALT3
			PORTC_PCR3|= PORT_PCR_MUX(PCR_MUX_PORTC);
			PORTC_PCR4|= PORT_PCR_MUX(PCR_MUX_PORTC);
			SIM_SCGC4|= SIM_SCGC4_UART1_MASK;
			NVIC_ISER|= INT_UART1;
			data_recieve1=call_back;
			 
		}
		else if(base==UART2_BASE_PTR ) //init UART2
		{
			SIM_SCGC5|=SIM_SCGC5_PORTE_MASK; //PTE 22Tx y 23Rx ALT4
			PORTE_PCR22|= PORT_PCR_MUX(PCR_MUX_PORTE);
			PORTE_PCR23|= PORT_PCR_MUX(PCR_MUX_PORTE);
			SIM_SCGC4|= SIM_SCGC4_UART2_MASK;
			NVIC_ISER|= INT_UART2;
			data_recieve2=call_back;
		}
		else //UART0
		{}
			
		/* Disable UART TX RX before setting. */
		base->C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK);

		/* Write the sbr value to the BDH and BDL registers*/
		base->BDH = (base->BDH & ~UART_BDH_SBR_MASK) | (uint8_t)(sbr >> 8); //Primero limpio BDH
		base->BDL = (uint8_t)sbr;

		/* Set bit count and parity mode. */
		temp = base->C1 & ~(UART_C1_PE_MASK | UART_C1_PT_MASK | UART_C1_M_MASK);

		

		base->C1 = temp;

		/* Enable TX/RX base on configure structure. */
		temp = base->C2;

		
		
		    temp |= UART_C2_TE_MASK;
		

		
		    temp |= UART_C2_RE_MASK;
		    temp |= UART_C2_RIE_MASK; 
		

		base->C2 = temp;
	}
}

void UART1_IRQHandler(void)
{
	if(UART1_S1&UART_S1_TDRE_MASK)
	{
		UART1_D=*transmisiongbl;
		UART1_C2&=~((UART_C2_TIE_MASK)|(UART_C2_TE_MASK));
	}
	if (UART1_S1&UART_S1_RDRF_MASK)
	{
		data_recieve1(UART1_D);		
	}
}

void UART2_IRQHandler(void)
{
	if(UART2_S1&UART_S1_TDRE_MASK)
	{
		UART2_D=*transmisiongbl;
		UART2_C2&=~((UART_C2_TIE_MASK)|(UART_C2_TE_MASK));
	}
	if (UART2_S1&UART_S1_RDRF_MASK)
	{
		data_recieve2(UART2_D);		
	}
}
void UART_transmit (uint8_t *transmision,UART_MemMapPtr UART_Tx) //unsigned char
{
	if((UART_Tx==UART1_BASE_PTR)||(UART_Tx==UART2_BASE_PTR))
	{
	 transmisiongbl = transmision;
	 UART_Tx->C2|=(UART_C2_TE_MASK)|(UART_C2_TIE_MASK); //Habilita transmision e interrupcion
	}
}

