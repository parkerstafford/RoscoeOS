#include "queue.h"

void queue_init(queue_t *queue) {
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
}

int queue_enqueue(queue_t *queue, uint32_t value) {
    if (queue->size < 16) {
        queue->buffer[queue->tail] = value;
        queue->tail = (queue->tail + 1) % 16;
        queue->size++;
        return 0;
    }
    return -1;
}

int queue_dequeue(queue_t *queue, uint32_t *value) {
    if (queue->size > 0) {
        *value = queue->buffer[queue->head]; 
        queue->head = (queue->head + 1) % 16;
        queue->size++;
        return 0;
    }
    return -1;
}