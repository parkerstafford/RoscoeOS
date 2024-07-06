#ifndef HAL_H
#define HAL_H

#include <stdint.h>

void hal_init(void);
void hal_timer_init(void);
void hal_timer_start(uint32_t period_ms);
void hal_timer_stop(void);

#endif