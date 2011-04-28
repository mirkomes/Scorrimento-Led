#include <stdint.h>

void led_main(void)
{
        volatile int i;
        int j = 0;
        
        //scorrimento dei led usando indirizzi cablati
        
        //programmo la porta 3 in uscita
        *(volatile uint32_t *)0x50038000 = 0x0f;
        
        //programmo la porta 2 in uscita
        uint32_t reg = *(volatile uint32_t *)0x50028000;
        reg |= 0xf0;
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
	      
	      j = (j==7) ? 0 : j+1;
	      
	      for (i = 0; i < 1000*250; i++)
	      {
		    
	      }
        }
}