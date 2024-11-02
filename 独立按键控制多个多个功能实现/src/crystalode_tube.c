//
// Created by NightRain on 2024/10/26.
//
#include "mcs51/8052.h"

void crystalode_tube(unsigned char m, unsigned char n) {
    unsigned char str[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};\
    char * p = str;
    switch (m) {
        case 1: P2_4 = 1; P2_3 = 1; P2_2 = 1; break;
        case 2: P2_4 = 1; P2_3 = 1; P2_2 = 0; break;
        case 3: P2_4 = 1; P2_3 = 0; P2_2 = 1; break;
        case 4: P2_4 = 1; P2_3 = 0; P2_2 = 0; break;
        case 5: P2_4 = 0; P2_3 = 1; P2_2 = 1; break;
        case 6: P2_4 = 0; P2_3 = 1; P2_2 = 0; break;
        case 7: P2_4 = 0; P2_3 = 0; P2_2 = 1; break;
        case 8: P2_4 = 0; P2_3 = 0; P2_2 = 0; break;
    }
    P0 = *(p + n);
}
