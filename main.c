#include "stm32l476xx.h"

void GPIO_Clock_Enable(){
	// Enable the clock to GPIO Port B and Port A	
	RCC->AHB2ENR		|=  RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOAEN | RCC_AHB2ENR_GPIOEEN; 
}

void GPIO_Pin2_Init(){
	GPIOB->MODER &= ~(0x03<<(2*2));
	GPIOB->MODER |= 0x01<<(2*2);
	GPIOB->OTYPER &= ~(1<<2);
	GPIOB->OSPEEDR &= ~(0x03<<(2*2));
	GPIOB->OSPEEDR |= 0x01<<(2*2);
	GPIOB->PUPDR &= ~(0x03<<(2*2));
	
}

void GPIO_Pin8_Init(){
	GPIOE->MODER &= ~(0x03<<(2*8));
	GPIOE->MODER |= 0x01<<(2*8);
	GPIOE->OTYPER &= ~(1<<8);
	GPIOE->OSPEEDR &= ~(0x03<<(2*8));
	GPIOE->OSPEEDR |= 0x01<<(2*8);
	GPIOE->PUPDR &= ~(0x03<<(2*8));
	
}

void GPIO_Pin0_Init(){
	GPIOA->MODER &= ~(0x03);
	GPIOA->OTYPER &= ~(0x1);
	GPIOA->OSPEEDR &= ~(0x03);
  GPIOA->OSPEEDR |= (0x01);
	GPIOA->PUPDR &= ~(0x03);
}

int main(void){  
	GPIO_Clock_Enable();
	GPIO_Pin2_Init();
	GPIO_Pin8_Init();
	GPIO_Pin0_Init();
	
	while(1){
	if(GPIOA->IDR & 0x01){
				GPIOB->ODR |= 1<< 2;  
				GPIOE->ODR &= ~(1<< 8);}
  else {
		    GPIOE->ODR |= 1<< 8;}
		    GPIOB->ODR &= ~(1<< 2);					
	}
}

