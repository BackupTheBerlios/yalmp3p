#include "hw_iface.h"

int hw_init() {
  #ifdef DEBUG
  printf("In hw_iface:hw_init()\n");
  #endif
  if(ioperm(BASE,3,1)) {
    perror("hw_iface:hw_init()");
    return(0);
  }
  return(1);
}

void out_lcd(char d, char f) {
  char to_port;

  #ifdef DEBUG
  printf("In hw_iface:out_lcd(char,char)\n");
  #endif
  outb(d,BASE);
  if(f==1) {
    outb(4,BASE+2);
    delay(10);
    outb(2,BASE+2);
    delay(50);
  }
  else {
    outb(2,BASE+2);
    delay(10);
    outb(0,BASE+2);
    delay(50);
  }
  delay(200);
}

//Delay t port ops
void delay(int t) {
  int i;

  #ifdef DEBUG
  printf("In hw_iface:delay(int)\n");
  #endif
  for(i=0;i<t;i++)
	inb(BASE);
}
