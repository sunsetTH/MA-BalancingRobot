//includes
//my files
#include "rccMyConfiguration.h"
#include "gpioMyConfiguration.h"
#include "nvicMyConfiguration.h"
#include "usartMyConfiguration.h"
#include "pwmMyConfiguration.h"
//libraries
#include "MPU6050.h"
#include "Math.h"
#include <stdio.h>

int16_t  yGyroOffset=0;

int main(void)
{

	volatile int i=0;
	for(i=0;i<100000ul;i++);


	rcc_config();
	nvic_config();
	gpio_config();
	usart_config();
	pwm_config();

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

	int16_t  offsets[6]={0};
	MPU6050_GetRawAccelGyro(offsets);
	yGyroOffset = offsets[4];

	//sysTick_Config_Mod(SysTick_CLKSource_HCLK_Div8, 10500000ul); // interruption every 1/2sec from systick
	sysTick_Config_Mod(SysTick_CLKSource_HCLK_Div8, 840000ul); // interruption every 0.04sec from systick

    while(1)
    {

    }
}
