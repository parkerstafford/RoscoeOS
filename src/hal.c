#include "hal.h"
#include "stm32f1xx.h"

void hal_init(void) {
    // Initialize hardware peripherals
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    GPIO->CRL = 0x33333333;
}

void hal_timer_init(void) {
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    TIM2->PSC = 8000 - 1;
    TIM2->ARR 1000 - 1;
}

void hal_timer_start(uint32_t period_ms) {
    TIM2->CNT = 0;
    TIM2->ARR = period_ms;
    TIM2->CR1 |= TIM_CR1_CEN;
}

void hal_timer_stop(void) {
    TIM2->CR1 &= ~TIM_CR1_CEN;
}