#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>

typedef struct {
    uint32_t buffer[16];
    uint8_t head;
    uint8_t tail;
    uint8_t size;
} queue_t;

void queue_init(queue_t *queue);
int queue_enqueue(queue_t *queue, uint32_t value);
int queue_dequeue(queue_t *queue, uint32_t *value);

#endif