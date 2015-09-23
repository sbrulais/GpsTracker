#include <stdint.h>
#include "peripheral_config.h"

int main(void)
{
	uint32_t i;
	GPIO_Config();
    while(1)
    {
    	for(i=0x000AFFFF;i;i--);
    	GPIO_SetBits(LED_GPIO_PORT,LED_PIN);
    	for(i=0x0000FFFF;i;i--);
    	GPIO_ResetBits(LED_GPIO_PORT,LED_PIN);
    }
}
