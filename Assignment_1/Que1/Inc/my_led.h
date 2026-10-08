/*
 * my_led.h
 *
 *  Created on: 16-Sept-2026
 *      Author: soham
 */

#ifndef MY_LED_H_
#define MY_LED_H_

#include<stm32f4xx.h>

#define LED_PORT	GPIOD
#define GREEN_LED	12
#define	ORANGE_LED	13
#define RED_LED		14
#define BLUE_LED	15

void led_on_o_b();
void led_on_g_r();
void led_off_o_b();
void led_off_g_r();
void led_init();


#endif /* MY_LED_H_ */
