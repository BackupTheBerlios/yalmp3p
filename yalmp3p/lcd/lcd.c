#include "panel.h"
#include <stdio.h>
int idelay = 500000;

int main(void) {
  int i;
  char buf[161];

  hw_init();
  lcd_reset();
  
  /*
  fgets(buf,161,stdin);
  buf[160]='\0';
  for(i=0;(i<161)&&(buf[i]!='\0');i++)
    if(buf[i]=='&')
      buf[i]='\n';
  lcd_puts(buf);*/
  
  //lcd_put_line("Eine kleine Mickeymaus zog sich mal die Hose aus",3);
 
  return(0);
}
