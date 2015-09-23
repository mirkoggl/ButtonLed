#include <stm32f4xx.h>
#include <stm32f4xx_gpio.h>

void setup();
void Delay(__IO uint32_t nCount);

int main(void){

	// initialize the GPIO pins we need
	setup();

	uint8_t i = 0;

	while (1){

		GPIOA->BSRRL = GPIO_Pin_2;
//
//		if(GPIOA->IDR & 0x0001){
//			if(i > 3){
//				i = 0;
//			}
//			else{
//				switch(i){
//
//				case 0:
//					GPIOD->BSRRL = 0x1000; // this sets LED1 (green)
//					GPIOD->BSRRH = 0x8000; // this resets LED4 (blue)
//					break;
//
//				case 1:
//					GPIOD->BSRRL = 0x2000; // this sets LED2 (orange)
//					GPIOD->BSRRH = 0x1000; // this resets LED1
//					break;
//
//				case 2:
//					GPIOD->BSRRL = 0x4000; // this sets LED3 (red)
//					GPIOD->BSRRH = 0x2000; // this resets LED2
//					break;
//
//				case 3:
//					GPIOD->BSRRL = 0x8000; // this sets LED4
//					GPIOD->BSRRH = 0x4000; // this resets LED3
//					break;
//				}
//
//				i++;
//			}
//			Delay(3000000L);
//		}
	}
}

void setup(void){
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14 | GPIO_Pin_13 | GPIO_Pin_12; // we want to configure all LED GPIO pins
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; 		// we want the pins to be an output
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz; 	// this sets the GPIO modules clock speed
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP; 	// this sets the pin type to push / pull (as opposed to open drain)
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL; 	// this sets the pullup / pulldown resistors to be inactive
	GPIO_Init(GPIOD, &GPIO_InitStruct); 			// this finally passes all the values to the GPIO_Init function which takes care of setting the corresponding bits.

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;		  // we want to configure PA0
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; 	  // we want it to be an input
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//this sets the GPIO modules clock speed
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;   // this sets the pin type to push / pull (as opposed to open drain)
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;   // this enables the pulldown resistor --> we want to detect a high level
	GPIO_Init(GPIOA, &GPIO_InitStruct);			  // this passes the configuration to the Init function which takes care of the low level stuff
}

void Delay(__IO uint32_t nCount) {
	while(nCount--) {
	}
}
