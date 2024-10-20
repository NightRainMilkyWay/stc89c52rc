#include "mcs51/8052.h"

void delay (unsigned int n ){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 120; ++j) {
            ;
        }
    }
}

int main() {
    unsigned int str = 0xff;
    P2 = str;
    delay(100);

    while (1){

        if (P3_1 == 0) {
            delay(20);
            str = (str << 1 ) | 0x00; // 1111 1111  >>  1111 1110
            P2 = str;
            delay(200);
        }

        if (P3_0 == 0) {
            delay(20);
            str = ( str >> 1 ) |  0x80;
            P2 = str;
            delay(200);   // 1111 1000 >> 1111 1100

        }
        if  (P3_2 == 0 ){
            for (int i = 0; i < 5; ++i) {
                P2 = 0x00;
                delay(100);
                P2 = 0xff;
                delay(200);
            }
        }
        if (P3_3 == 0 ){
            str = 0xff;
            P2 = str;
            delay(200);
        }
    }
}


