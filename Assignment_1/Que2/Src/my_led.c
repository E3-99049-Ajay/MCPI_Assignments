/*
 * my_led.c
 *
 *  Created on: 17-Sept-2026
 *      Author: soham
 */

#include<my_led.h>
#include<stm32f4xx.h>

void led_on_green()
{
	LED_PORT -> ODR |= BV(GREEN_LED);
}
void led_on_orange()
{
	LED_PORT -> ODR |= BV(ORANGE_LED);
}
void led_on_red()
{
	LED_PORT -> ODR |= BV(RED_LED);
}
void led_on_blue()
{
	LED_PORT -> ODR |= BV(BLUE_LED);
}

void led_off_green()
{
	LED_PORT->ODR&=~BV(GREEN_LED);
}
void led_off_orange()
{
	LED_PORT->ODR&=~BV(ORANGE_LED);
}
void led_off_red()
{
	LED_PORT->ODR&=~BV(RED_LED);
}
void led_off_blue()
{
	LED_PORT->ODR&=~BV(BLUE_LED);
}


void led_init()
{
	RCC->AHB1ENR |= BV(3);

	LED_PORT->MODER |= (BV(24)|BV(26)|BV(28)|BV(30));
	LED_PORT->MODER &=~ (BV(25)|BV(27)|BV(29)|BV(31));
	LED_PORT->OTYPER &=~ (BV(12)|BV(13)|BV(14)|BV(15));
	LED_PORT->OSPEEDR &=~ (BV(24)|BV(25)|BV(26)|BV(27)|BV(28)|BV(29)|BV(30)|BV(31));
	LED_PORT->PUPDR &=~ (BV(24)|BV(25)|BV(26)|BV(27)|BV(28)|BV(29)|BV(30)|BV(31));
}
