#include "timer.h"

static time_t startTime;
static int maxTime;

void timerInit(int tempoMax) {
    startTime = time(NULL);  
    maxTime = tempoMax;  
}

int timerTimeOver(void) {
    return difftime(time(NULL), startTime) >= maxTime;
}
