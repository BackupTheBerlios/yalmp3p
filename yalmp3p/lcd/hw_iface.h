#ifndef HW_IFACE_H
#define HW_IFACE_H
#include <sys/io.h>

//Base IO address of lp0
#define BASE 0x378

int hw_init();
void out_lcd(char,char);
void delay(int);
#endif
