#include <16F876.h>
#fuses XT, NOWDT, NOPROTECT, NOLVP
#use delay (clock=4000000)
#define use_portb_kbd TRUE
#include <kbd.c>
#use standard_io(a)

void main(){
   char k, k_ant='0';
   char PWMH=0, PWML=0;
   kbd_init();
   PORT_B_PULLUPS(TRUE);
   while(1){
      k=kbd_getc();
      if(k==0) k=k_ant;   //nenhuma tecla
      if((k=='*') || (k=='#')) k='0';

      k_ant=K;
      k=k-48;      //de ASCII para numero
      PWMH=28*k;   //(255/9)*K
      PWML=255-PWMH;
      for(PWMH; PWMH>0;PWMH--)
         OUTPUT_HIGH(PIN_A0);
      for(PWML; PWML>0;PWML--)
         OUTPUT_LOW(PIN_A0);
      
   }
}
