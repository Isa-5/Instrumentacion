/*
 * LPTMR_driver.c
 *
 *  Created on: Oct 22, 2020
 *      Author: isae_
 */



///////////////////////////////////////////////////////////////////////////////////////////////////
//                                      Includes Section
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "LPTMR_driver.h"
#include "MKL25Z4.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//                                      Functions Section
///////////////////////////////////////////////////////////////////////////////////////////////////

void LPTMR_Init (void)
{
	SIM_SCGC5|= SIM_SCGC5_LPTMR_MASK;
	LPTMR0_PSR|= LPTMR_PSR_PBYP_MASK|LPTMR_PSR_PCS(CLK_LPO);

}

void LPTMR_interrupt (uint32_t time_inter)
{
	uint32_t time;
	time=time_inter;
	LPTMR0_CMR = tiempo;
	LPTMR0_CSR |= LPTMR_CSR_TIE_MASK|LPTMR_CSR_TEN_MASK; //se habilita interrupcion y timer
}

void LPTMR_delay (uint32_t time_delay)
{
	LPTMR0_CSR &=~ LPTMR_CSR_TIE_MASK; //deshabilito interrupcion
	uint32_t time;
	time=time_delay;
	LPTMR0_CMR = tiempo;
	LPTMR0_CSR |= LPTMR_CSR_TEN_MASK; //inicio conteo
	do {
				do{} while ((LPTMR0_CSR & LPTMR_CSR_TCF_MASK)==0); 
				LPTMR0_CSR|=LPTMR_CSR_TCF_MASK;
					
			}while (--time); 
			LPTMR0_CSR&=~LPTMR_CSR_TEN_MASK;
	
}
