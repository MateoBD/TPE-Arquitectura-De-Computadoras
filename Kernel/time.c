#include <time.h>
#include <times.h>
#include <libasm.h>

static unsigned long ticks = 0;


void timer_handler() {
	ticks++;
}

int ticks_elapsed() {
	return ticks;
}

int seconds_elapsed() {
	return ticks / 18;
}

unsigned long getTicks(){
    return ticks;
}

void sleep(int ticksToWait) {
    unsigned long start = ticks;
    while (ticks - start < ticksToWait){
        _hlt();
    };
}

// static char getDecimalFrom(char hex){
//     char high = hex & 0xF0; // Parte alta (decenas)
//     char low = hex & 0x0F;          // Parte baja (unidades)
//     return (high * 10) + low;
// }

static time t;

time * getTime(){
    t.day = getSystemDayOfMonth();
    t.month = getSystemMonth();
    t.year = getSystemYear();
    t.hour =getSystemHour(); 
    t.min = getSystemMin();
    t.sec = getSystemSec();
    return &t;
}
