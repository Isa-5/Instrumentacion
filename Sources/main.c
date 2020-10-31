/*
 * main implementation: use this 'C' sample to create your own application
 *
 */





#include "derivative.h" /* include peripheral declarations */
#include "UART_driverU.h"
#include "MKL25Z4.h"

#define Bus_CLK  (uint32_t)(24000000)

uint8_t Buffer=0xAA;
uint8_t dato;

void Prueba_recieve (uint8_t data);


int main(void)
{
	uart_config_t configuracion;
	configuracion.baudRate_Bps=9600;
	configuracion.callBack_Rx=(funcion_de_recieve)(&Prueba_recieve);//lo casteamos
	configuracion.enableRx=TRUE;
	configuracion.enableTx=TRUE;
	configuracion.parityMode=kUART_ParityDisabled;
	UART_Init( UART1_BASE_PTR, &configuracion ,Bus_CLK);
	UART_Init( UART2_BASE_PTR, &configuracion ,Bus_CLK);
	
	UART_transmit (&Buffer,UART1_BASE_PTR);
	for(;;) {	   
	
	}
	
	
	return 0;
}

void Prueba_recieve (uint8_t data)
	{
		dato=data;
		
	}
