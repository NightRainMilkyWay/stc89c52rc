#include <mcs51/8052.h>


unsigned char str[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
unsigned char *p = str;

void delay(unsigned int n ){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 120; ++j) {
            ;
        }
    }
}

void next(unsigned char m, unsigned char n) {
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

int main(void) {
    unsigned char m = 1, n = 0;

    while (1) {
        if (P3_1 == 0) {
            delay(20);
            if (P3_1 == 0) {
                n = (n + 1) % 10;
                next(m, n);
                delay(100);
            }
        }
        if (P3_0 == 0) {
            delay(20);
            if (P3_0 == 0) {
                n = (n == 0) ? 9 : (n - 1);
                next(m, n);
                delay(100);
            }
        }
        if (P3_2 == 0) {
            delay(20);
            if (P3_2 == 0) {
                m = (m % 8) + 1;
                next(m, n);
                delay(100);
            }
        }
        if (P3_3 == 0) {
            delay(20);
            if (P3_3 == 0) {
                m = (m == 1) ? 8 : (m - 1);
                next(m, n);
                delay(100);
            }
        }
    }
}
