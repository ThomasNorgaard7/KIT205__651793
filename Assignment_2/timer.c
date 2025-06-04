// ================================
// timer.c
// ================================
#include "timer.h"

void timer_start(Timer* timer) {
    timer->start_time = clock();
}

double timer_elapsed_seconds(Timer* timer) {
    clock_t end_time = clock();
    return ((double)(end_time - timer->start_time)) / CLOCKS_PER_SEC;
}
