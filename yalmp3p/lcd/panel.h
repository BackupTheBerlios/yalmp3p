#ifndef PANEL_H
#define PANEL_H
#include "hw_iface.h"

#define LINE1_ADDR 0x00
#define LINE2_ADDR 0x40
#define LINE3_ADDR 0x14
#define LINE4_ADDR 0x54
#define LINE_LENGTH 20

void lcd_reset();
void lcd_clr();
void lcd_putc(char);
void lcd_puts(const char*);
void gotoxy(int,int);
#endif
