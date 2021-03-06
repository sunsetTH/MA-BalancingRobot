//includes
#include "rccMyConfiguration.h"
#include "gpioMyConfiguration.h"
#include "nvicMyConfiguration.h"
#include "usartMyConfiguration.h"
#include "MPU6050.h"
#include "Math.h"
#include <stdio.h>

//--------------
//main loop
int main(void)
{

	int i=0;
	for(i=0;i<100000ul;i++);


	rcc_config();
	nvic_config();
	gpio_config();
	usart_config();
	USART_puts(USART1, "USART BT initialization complete!\r\n"); // just send a message to indicate that it works

	MPU6050_I2C_Init();
	MPU6050_Initialize();
	if( MPU6050_TestConnection() == 1){
	    // connection success
		USART_puts(USART1, "I2C IMU connection initialization complete!\r\n");
	}else{
	    // connection failed
		USART_puts(USART1, "I2C initialization failed!\r\n");
	}

	//sysTick_Config_Mod(SysTick_CLKSource_HCLK_Div8, 10500000ul); // interruption every 1/2sec from systick
	sysTick_Config_Mod(SysTick_CLKSource_HCLK_Div8, 840000ul); // interruption every 0.04sec from systick


    while(1)
    {

    }
}
