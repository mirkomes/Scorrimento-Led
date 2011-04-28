#include <stdint.h>
//legge lo stato del pulsante 1
int polling(void)
{
        uint32_t valore = *(volatile uint32_t *)0x50020800;
        
        return !((int) valore);
}