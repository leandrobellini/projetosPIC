#include <16f876.h>
#USE DELAY(CLOCK = 4000000)
#FUSES XT, NOWDT, NOPROTECT, NOPUT

#USE fast_IO(B)
#USE fast_IO(A

byte CONST DISPLAY[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x98};

void main(){
   int ud=0, dec=0;

   SET_TRIS_B(0x00);
   SET_TRIS_A(0x00);
   
   output_low(PIN_A1);        //desliga digito descimal
   output_high(PIN_A0);       //liga digito unidade
   
   while(1){
      for(dec=0; dec < 10; dec++){
         for(ud=0; ud < 10; ud++){
            output_high(PIN_A0);       //liga digito unidade
            output_low(PIN_A1);        //desliga digito descimal
            output_B(DISPLAY[ud]);     //mostra digito unidade
            delay_ms(50);  
            
            output_high(PIN_A1);        //liga digito descimal
            output_low(PIN_A0);       //desliga digito unidade
            output_B(DISPLAY[dec]); 
            delay_ms(50); 
            
            
               
        }
        
      }
      
      
   
   }
   
   
}
