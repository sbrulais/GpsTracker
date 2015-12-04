#include <stdint.h>
#include "peripheral_config.h"

int main(void)
{
	uint32_t i;
	Clock_Config();
	GPIO_Config();
	UART_Config();
    while(1)
    {

    }
}
