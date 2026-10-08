/*
 * my_led.c
 *
 *  Created on: 16-Sept-2026
 *      Author: soham
 */

#include "my_led.h"

void led_init()
{
	RCC->AHB1ENR |= BV(3);

	LED_PORT->MODER |= ( BV(24) | BV(26) | BV(28) | BV(30));
	LED_PORT->MODER &= ~( BV(25) | BV(27) | BV(29) | BV(31));

	LED_PORT->OSPEEDR &= ~(BV(24) | BV(25) | BV(26) | BV(27) | BV(28) | BV(29) | BV(30) | BV(31));

	LED_PORT->OTYPER &= ~(BV(12) | BV(13) | BV(14) | BV(15));

	LED_PORT->PUPDR &= ~(BV(24) | BV(25) | BV(26) | BV(27) | BV(28) | BV(29) | BV(30) | BV(31));
}

void switch_init()
{
		RCC->AHB1ENR |= BV(0);


		GPIOA->MODER &= ~( BV(0) | BV(1));

		GPIOA->OTYPER &= ~( BV(0) | BV(1));

		GPIOA->OSPEEDR &= ~( BV(0) | BV(1));

		GPIOA->PUPDR &= ~(BV(0) | BV(1));
}
int is_switch_press()
{
	return (BV(0) & GPIOA->IDR) == 1?1:0;
}


void led_toggle()
{
	if(is_switch_press())
	{
		LED_PORT->ODR |= BV(GREEN_LED);
		DelayMs(1000);
		LED_PORT->ODR &= ~BV(GREEN_LED);
	}
	else if(is_switch_press())
	{
		LED_PORT->ODR |= BV(ORANGE_LED);
		DelayMs(1000);
		LED_PORT->ODR &= ~BV(ORANGE_LED);
	}

	else if(is_switch_press())
	{
		LED_PORT->ODR |= BV(RED_LED);
		DelayMs(1000);
		LED_PORT->ODR &= ~BV(RED_LED);

	}

	else if(is_switch_press())
	{
		LED_PORT->ODR |= BV(BLUE_LED);
		DelayMs(1000);
		LED_PORT->ODR &= ~BV(BLUE_LED);


	}


}
