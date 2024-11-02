#include "mcs51/8052.h"
#include "Function.h"
#include "test.h"
#include "Timer0.h"
#include "add.h"

_Bool flag = 0;
unsigned int functionality = 0;
unsigned int *fun = &functionality;
typedef unsigned int  u16;
unsigned int timer_count = 0;

u16 h1 = 0;
u16 h2 = 0;
u16 m1 = 0;
u16 m2 = 0;
u16 s1 = 0;
u16 s2 = 0;



int main(void) {

    Timer0Init();
    while (1) {
        digital_tube();
        switch (functionality) {
            case 0:
                Function_1();
                break;
            case 1:
                Function_2();
                break;
        }
    }
}

void timer_interrupt(void) __interrupt(1) {
    TL0 = 0x18;
    TH0 = 0xFC;
    timer_count++;
    if (timer_count == 1000) {
        timer_count = 0;
        if (functionality == 0) {
            if (flag == 1) {
                add();
            }
        }
        if (functionality == 1) {
            if (flag == 1) {
                red();
            }
        }
    }
}
