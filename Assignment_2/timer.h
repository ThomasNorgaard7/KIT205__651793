// ================================
// timer.h
// ================================
#ifndef TIMER_H
#define TIMER_H

#include <time.h>

typedef struct {
    clock_t start_time;
} Timer;

void timer_start(Timer* timer);
double timer_elapsed_seconds(Timer* timer);

#endif
