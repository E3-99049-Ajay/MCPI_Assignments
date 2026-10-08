/*
 * my_led.h
 *
 *  Created on: 16-Sept-2026
 *      Author: soham
 */

#ifndef MY_LED_H_
#define MY_LED_H_

#include<stm32f4xx.h>

#define LED_PORT     GPIOD
#define GREEN_LED    12
#define ORANGE_LED   13
#define RED_LED      14
#define BLUE_LED     15

void led_toggle();
void led_init();
void switch_init();
int is_switch_press();


#endif /* MY_LED_H_ */
