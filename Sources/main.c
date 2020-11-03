/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#include "UART_driverU.h"
#include "MKL25Z4.h"

#define Bus_CLK  (uint32_t)(24000000)
#define baud_rate (uint32_t)(9600)

uint8_t Buffer=0xAA;
uint8_t dato;

void Prueba_recieve (uint8_t data);


int main(void)
{
	
	UART_Init(UART1_BASE_PTR, &Prueba_recieve , Bus_CLK,  baud_rate);
	
	UART_transmit (&Buffer,UART1_BASE_PTR);
	for(;;) {	   
	
	}
	
	
	return 0;
}

void Prueba_recieve (uint8_t data)
	{
		dato=data;
		
	}
