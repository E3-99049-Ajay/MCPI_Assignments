/*
 * lcd.c
 *
 *  Created on: 21-Sept-2026
 *      Author: nishant
 */

#include "lcd.h"

extern I2C_HandleTypeDef hi2c1;

void lcd_init(void)
{
	//Init sequence as per the given flow chart
	HAL_Delay(20);
	lcd_write_nibble(LCD_CMD, 0x03);
	HAL_Delay(5);
	lcd_write_nibble(LCD_CMD, 0x03);
	HAL_Delay(1);
	lcd_write_nibble(LCD_CMD, 0x03);
	HAL_Delay(1);
	lcd_write_nibble(LCD_CMD, 0x02);
	HAL_Delay(1);

	//LCD init commands
	lcd_write_byte(LCD_CMD, FUNCTION_SET);
	lcd_write_byte(LCD_CMD, DISPLAY_ON_OFF);
	lcd_write_byte(LCD_CMD, ENTRY_MODE_SET);
	lcd_write_byte(LCD_CMD, LCD_CLEAR);
	HAL_Delay(20);
}
void lcd_write_nibble(uint8_t rs, uint8_t val)
{
	uint8_t rs_flag = (rs == LCD_DATA)? BV(LCD_RS_POS): 0;
	uint8_t data = (val << LCD_DB4_POS) | rs_flag | BV(LCD_BL_POS)|BV(LCD_EN_POS);
	PCF8574_Write(data);

	HAL_Delay(1);
	data = (val<< LCD_DB4_POS)|rs_flag|BV(LCD_BL_POS);
	PCF8574_Write(data);
}
void lcd_shift(void)
{
	lcd_write_byte(LCD_CMD, 0x1C);
}

void lcd_write_byte(uint8_t rs, uint8_t val)
{
	uint8_t high = val >> 4, low = val & 0x0Fl;
	lcd_write_nibble(rs, high);
	lcd_write_nibble(rs, low);
	HAL_Delay(3);

}
void lcd_puts(uint8_t line, char str[])
{
	lcd_write_byte(LCD_CMD, line);
	for(int i=0; str[i]!='\0'; i++)
		lcd_write_byte(LCD_DATA, str[i]);

}


void PCF8574_Write(uint8_t val)
{
	HAL_I2C_Master_Transmit(&hi2c1, PCF8574_ADDR, &val, 1, HAL_MAX_DELAY);
}
uint8_t PCF8574_Read(void)
{
	uint8_t val;
	HAL_I2C_Master_Receive(&hi2c1, PCF8574_ADDR, &val, 1, HAL_MAX_DELAY);
	return val;
}

void lcd_clear(void)
{
	lcd_write_byte(LCD_CMD, LCD_CLEAR);
	HAL_Delay(2);
}
