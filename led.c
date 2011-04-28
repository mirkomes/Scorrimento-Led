#include <stdint.h>

void led_main(void)
{
        int j = 7, i;
        int direzione = 1;
        
        //scorrimento dei led usando indirizzi cablati
        
        //programmo la porta 3 in uscita
        *(volatile uint32_t *)0x50038000 = 0x0f;
        
        //programmo la porta 2 in uscita (pin 4, 5, 6, 7)
        
        //il pulsante 1 "BUT1" è collegato alla PIO2_9
        //devo abilitare il pin 9 della porta 2 in ingresso
        
        uint32_t reg = *(volatile uint32_t *)0x50028000;
        
        reg |= 0x0f0; //porte dei led in uscita e porta del BUT1 in ingresso
        
        *(volatile uint32_t *)0x50028000 = reg;
        
        while(1)
        {
	      switch (j)
	      {
		    case 0:
			  *(volatile uint32_t *)0x500203c0 = 0xfff;
			  *(volatile uint32_t *)0x50030038 = 0xf;
			  *(volatile uint32_t *)0x50030004 = 0x0;
			  break;
		    case 1:
			  *(volatile uint32_t *)0x500203c0 = 0xfff;
			  *(volatile uint32_t *)0x50030034 = 0xf;
			  *(volatile uint32_t *)0x50030008 = 0x0;
			  break;
		    case 2:
			  *(volatile uint32_t *)0x500203c0 = 0xfff;
			  *(volatile uint32_t *)0x5003002c = 0xf;
			  *(volatile uint32_t *)0x50030010 = 0x0;
			  break;
		    case 3:
			  *(volatile uint32_t *)0x500203c0 = 0xfff;
			  *(volatile uint32_t *)0x5003001c = 0xf;
			  *(volatile uint32_t *)0x50030020 = 0x0;
			  break;
		    case 4:
			  *(volatile uint32_t *)0x5003003c = 0xf;
			  *(volatile uint32_t *)0x50020380 = 0xfff;
			  *(volatile uint32_t *)0x50020040 = 0x0;
			  break;
		    case 5:
			  *(volatile uint32_t *)0x5003003c = 0xf;
			  *(volatile uint32_t *)0x50020340 = 0xfff;
			  *(volatile uint32_t *)0x50020080 = 0x0;
			  break;
		    case 6:
			  *(volatile uint32_t *)0x5003003c = 0xf;
			  *(volatile uint32_t *)0x500202c0 = 0xfff;
			  *(volatile uint32_t *)0x50020100 = 0x0;
			  break;
		    case 7:
			  *(volatile uint32_t *)0x5003003c = 0xf;
			  *(volatile uint32_t *)0x500201c0 = 0xfff;
			  *(volatile uint32_t *)0x50020200 = 0x0;
			  break;
		    default:
			  break;
	      }
	      	      
	      if (!direzione)
	      	    j = (j==7) ? 0 : j + 1;
	      else
		    j = (j==0) ? 7 : j - 1;
	      
	      for (i = 0; i < 1000*70; i++)
	      {
		    //durante il tempo porto di attesa chiamo la funzione polling per verificarne lo stato
		    direzione = polling();
	      }
        }
}