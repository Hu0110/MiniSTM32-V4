#ifndef __LED_FLOW_H
#define __LED_FLOW_H

#include "stdint.h"

typedef struct
{
    uint8_t running;        // 是否运行
    uint32_t speed;         // 跑马灯速度(ms)
    uint32_t last_tick;     // 上次更新时间
    uint8_t led_index;      // 当前灯状态
} LedFlow_t;

void led_flow_init(void);
void led_flow_task(void);

void led_flow_start(void);
void led_flow_stop(void);
void led_flow_speed_up(void);

#endif