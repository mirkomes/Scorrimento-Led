#include <stdint.h>

void led_main(void)
{
    
    
    *(volatile uint32_t *)0x50038000 = 0x0f;
    *(volatile uint32_t *)0x5003003c = 0x0;
    
    uint32_t reg = *(volatile uint32_t *) 0x50028000;
    reg |= (1 << 5);
    *(volatile uint32_t *) 0x50028000 = reg;
    *(volatile uint32_t *) 0x50020080 = 0x0;
    
}

