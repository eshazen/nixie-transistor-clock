
// for m328 D0 is in PCMSK2
#define PCMSK PCMSK2

#include <picoUART.h>
#include <pu_print.h>
#include "lcd.h"

static char c;

static char buff[80];
static char* buff_p;
static char chr;

//
// read string until \n seen
//
void pu_gets() {
  buff_p = buff;

  do {
    while( !purx_dataready())
      ;
    chr = pu_read();
    *buff_p++ = chr;
  } while( chr != '\n');
}
  
  

void setup() {
  io_init();
  lcd_init();
  lcd_addr( 0);

  lcd_puts( "WiFi Test 1.0");

  //  prints_P(PSTR("AT+CWMODE=1\r\n"));
  
}

void loop()
{
  ;
}

