#include "task.h"

static task_t tasks[MAX_TASKS];
static uint8_t task_count = 0;
static uint8_t current_task = 0;

void task_create(task_func_t func, void *param) {
    if (task_count < MAX_TASKS) {
        tasks[task_count].task_func = func;
        tasks[task_count].task_param = param;
        tasks[task_count].stack_pointer = &tasks[task_count].stack[256];
        task_count++;
    }
}

void task_start_scheduler(void) {
    current_task = 0;
    tasks[current_task].task_func(tasks[current_task].task_param);
    while (1);
}

extern void task_switch(void);

void task_yield(void) {
    current_task = (current_task + 1) % task_count;
    task_switch();
}