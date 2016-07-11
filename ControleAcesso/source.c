#include <16F876.h>
#fuses XT, NOWDT, NOPROTECT, NOLVP
#use delay(clock = 4000000)
#use standard_io(a)

#define use_portb_kbd TRUE
#define use_portb_lcd TRUE

#include <lcd.c>
#include <kbd.c>
#include <stdlib.h>

//#rom 0x2100={'7','2','3'}

void main(){
   char k;
   int i;
   char data[3], chave[3];

   chave[0] = '7'; chave[1] = '2'; chave[2] = '3';

   lcd_init();
   kbd_init();
   port_b_pullups(TRUE);

   while(TRUE){
      i = 0;
      printf(lcd_putc, "\fDigite a tecla 1\n");
      while(i<=2){
         k=kbd_getc();
         if(k!=0){
            data[i] = k;
            i++;
            printf(lcd_putc, "\fDigite a tecla %u\n", i+1);
         }
      }
      if(data[0]==chave[0] && data[1]==chave[1]  && data[2]==chave[2] ){
         printf(lcd_putc, "\fPorta aberta!");
         output_high(PIN_A0);
         delay_ms(500);
         output_low(PIN_A0);
      }else{
         printf(lcd_putc, "\fSenha errada!");
         delay_ms(1000);
      }
   }
}
