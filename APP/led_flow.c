#include "led_flow.h"
#include "./BSP/LED/led.h"

static LedFlow_t g_led_flow;

void led_flow_init(void)
{
    g_led_flow.running = 0;      // 默认停止
    g_led_flow.speed = 500;
    g_led_flow.last_tick = 0;
    g_led_flow.led_index = 0;
}

void led_flow_start(void)
{
    g_led_flow.running = 1;
}

void led_flow_stop(void)
{
    g_led_flow.running = 0;
    g_led_flow.speed = 500;

    LED0(1);
    LED1(1);
}

void led_flow_speed_up(void)
{
    if(g_led_flow.speed > 100)
    {
        g_led_flow.speed -= 100;
    }
}

void led_flow_task(void)
{
    if(g_led_flow.running == 0)
        return;

    if(HAL_GetTick() - g_led_flow.last_tick >= g_led_flow.speed)
    {
        g_led_flow.last_tick = HAL_GetTick();

        if(g_led_flow.led_index == 0)
        {
            LED0(0);
            LED1(1);
        }
        else
        {
            LED0(1);
            LED1(0);
        }

        g_led_flow.led_index ^= 1;
    }
}