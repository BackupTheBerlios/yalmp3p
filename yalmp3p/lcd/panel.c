#include "panel.h"


void lcd_reset() {
  out_lcd(0x30,0); //Display mode
  usleep(10000);
  out_lcd(0x38,0); //Display mode
  usleep(10000);
  lcd_clr(); //Clear
  out_lcd(0x0c,0); //Display on
  out_lcd(0x06,0); //Entry mode
}

void lcd_clr() {
  out_lcd(0x01,0);
  usleep(3000);
}

void lcd_put_line(char *s, int y){
  int i,j;
  char ctmp;
  char sout[21];
  
  if (strlen(s) > 20){
    char banner[strlen(s)];
    strncpy( banner, s, strlen(s) );
    banner[strlen(s)] = '\0';
    strncat( banner, " ***  ", 6 );
    
    while(1){
      
      for (i = 0; i < 20; i++){
        sout[i] = banner [i];
      }
      sout[20] = '\0';
    
      gotoxy(0,y);
      lcd_puts(sout);
      delay(SCROLLDELAY);
      
      ctmp = banner[0];
      
      for (i = 0; i < strlen(banner)-1; i++){
        banner[i] = banner[i+1];
      }
      
      banner[ strlen(banner)-2 ] = ctmp;
      
    }
          
  } else {
    gotoxy( (20 - strlen(s) ) / 2, y);
    lcd_puts(s);
    delay(SCROLLDELAY);
    while(1);
  }
 
}

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
  out_lcd(0x06,0); //Entry mode
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
  out_lcd(128|addr,0);

}
