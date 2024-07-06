#include "rtos.h"
#include "task.h"
#include "hal.h"

void task1(void *param) {
    while (1) {
        // Toggle LED
        GPIOA->ODR ^= GPIO_ODR_ODR5;
        task_yield();
    }
}

void task2(void *param) {
    while (1) {
        GPIOA->ODR ^= GPIO_ODR_ODR6;
        task_yield();
    }
}

int main(void) {
    hal_init();
    hal_timer_init();

    task_create(task1, NULL);
    task_create(task2, NULL);

    task_start_scheduler();

    while (1);
    return 0;
}