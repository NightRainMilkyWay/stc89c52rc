#include "mcs51/8052.h"
#include "test.h"

extern _Bool flag;
extern unsigned int functionality;
extern unsigned int *fun;

// 功能1
void Function_1(void) {
    while (functionality == 0) {
        digital_tube();

        if (P3_3 == 0) {
            functionality = (functionality + 1) % 2;
            break;
        }
        if (P3_1 == 0) {
            flag = 1;
        }
        if (P3_0 == 0) {
            flag = 0;
        }
    }
}

// 功能2
void Function_2(void) {
    while (functionality == 1) {
        digital_tube();

        if (P3_3 == 0) {
            functionality = (functionality + 1) % 2;
            break;
        }
        if (P3_1 == 0) {
            flag = 1;
        }
        if (P3_0 == 0) {
            flag = 0;
        }
    }
}



