#include "panel.h"

void lcd_reset() {
  out_lcd(0x30,0); //Display mode
  usleep(10000);
  out_lcd(0x38,0); //Display mode
  usleep(10000);
/*  out_lcd(0x08,0); //Display mode
  usleep(10000);*/
  lcd_clr(); //Clear
  out_lcd(0x0c,0); //Display on
  out_lcd(0x06,0); //Entry mode
}

void lcd_clr() {
  out_lcd(0x01,0);
  usleep(3000);
}

void lcd_putc(char c) {out_lcd(c,1);}

//No scrolling
void lcd_puts(const char *s) {
  int i,j;

  i=0;
  j=0;
  while(s[i]!='\0') {
    if(s[i]=='\n') break;
    if(i<20) {
      out_lcd(s[i],1);
    }
    i++;
  }
}

void gotoxy(int x, int y) {
  int addr;
  
  switch (y)
  {
          case 0: addr=LINE1_ADDR;
                  break;
          case 1: addr=LINE2_ADDR;
                  break;
          case 2: addr=LINE3_ADDR;
                  break;
          case 3: addr=LINE4_ADDR;
                  break;
  }
  
  addr+=x;
  out_lcd(0x80|addr,0);

}
