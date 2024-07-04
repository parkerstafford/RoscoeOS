#ifndef TASK_H
#define TASK_H

#include <stdint.h>

#define MAX_TASKS 8

typedef  void (*task_func_t)(void*);

typedef struct {
    uint32_t *stack_pointer;
    uint32_t stack[256];
    task_func_t task_func;
    void *task_param;
} task_t;

void task_create(task_func_t func, void *param);
void task_start_scheduler(void);

#endif