#include "./stm32f1xx_it.h"
#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/EXTI/exti.h"

uint8_t running_flag = 1;   // 1: 运行, 0: 停止
uint32_t speed_delay = 500; // 延时时间，单位ms
uint32_t last_time = 0;     // 上次翻转的时间点

void all_led_off(void)
{
    LED0(1);
    LED1(1);
}

int main(void)
{
    uint8_t key;

    HAL_Init();
    sys_stm32_clock_init(RCC_PLL_MUL9);
    delay_init(72);

    led_init();
    extix_init();                          /* 初始化外部中断输入 */
    led_flow_init();
    all_led_off();

    while (1)
    {
        led_flow_task();
    }
}