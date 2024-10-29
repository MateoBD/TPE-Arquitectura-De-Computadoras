#include <time.h>
#include <times.h>

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

void sleep(int ticksToWait) {
    unsigned long start = ticks;
    while (ticks - start < ticksToWait){
        _hlt();
    };
}

static char getDecimalFrom(char hex){
    char high = (hex >> 4) & 0x0F; // Parte alta (decenas)
    char low = hex & 0x0F;          // Parte baja (unidades)
    return (high * 10) + low;
}

static time t;

//time * getTime(){
    // t.day = getDecimalFrom(getSystemDayOfMonth());
    // t.month = getDecimalFrom(getSystemMonth());
    // t.year = getDecimalFrom(getSystemYear());
    // t.hour =getDecimalFrom(getSystemHour()); 
    // t.min = getDecimalFrom(getSystemMin());
    // t.sec = getDecimalFrom(getSystemSec());
    //return &t;
//}
char * getTime(){
    char* time = "DD/MM/YY-00:00:00";
    char aux = getSystemDayOfMonth();
    char aux2 = aux>>4;
    time[0]=aux2+'0';
    time[1]=(aux&0xF)+'0';
    aux = getSystemMonth();
    aux2 = aux>>4;
    time[3]=aux2+'0';
    time[4]=(aux&0xF)+'0';
    aux = getSystemYear();
    aux2 = aux>>4;
    time[6]=aux2+'0';
    time[7]=(aux&0xF)+'0';
    aux = getSystemHour();
    aux2 = aux>>4;
    time[9]=aux2+'0';
    time[10]=(aux&0xF)+'0';
    aux = getSystemMin();
    aux2 = aux>>4;
    time[12]=aux2+'0';
    time[13]=(aux&0xF)+'0';
    aux = getSystemSec();
    aux2 = aux>>4;
    time[15]=aux2+'0';
    time[16]=(aux&0xF)+'0';
    return time;
}
