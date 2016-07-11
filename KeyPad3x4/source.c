#include <16F876.h>
#USE DELAY(CLOCK = 4000000)
#FUSES XT, NOWDT, NOPROTECT, NOPUT

#define use_portb_kbd TRUE
#define use_portb_lcd TRUE

#include <KBD.c>

#include <LCD.c>


void main(){
   char k;
   int x;
   lcd_init();
   kbd_init();
   port_b_pullups(TRUE);

   lcd_putc("\fPRONTO...");
   while(TRUE){
      k = kbd_getc();
      x = k-48;
      if(k!=0){
         if(k=='*')
            lcd_putc('\f');
         else{
            lcd_putc(k);
            delay_ms(500);

            printf(lcd_putc, "\f Car=%c", k);
            delay_ms(500);

            printf(lcd_putc, "\f Car=%u", k); //ASCII
            delay_ms(500);

            printf(lcd_putc, "\f Car=%u", x); //Valor numerico
            delay_ms(500);

            lcd_putc("\fPRONTO...");

         }
      }
   }

}