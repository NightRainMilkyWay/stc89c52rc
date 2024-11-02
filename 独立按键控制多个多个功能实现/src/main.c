#include "mcs51/8052.h"
#include "delay.h"

void nixie(void);
void led_light(void);
void running_light(void);

unsigned char m = 1, n = 0;
unsigned int functionality = 0;
_Bool flag = 1;

int main(void) {
    while (1) {
        if (P3_3 == 0) {
            delay(20);
            if (P3_3 == 0) {
                functionality = (functionality + 1) % 3;
                delay(100);
            }
        }

        switch (functionality) {
            case 0:
                nixie();
                break;
            case 1:
                led_light();
                break;
            case 2:
                running_light();
                break;
        }
    }
}

void nixie(void) {
    while (functionality == 0) {
        if (flag == 1) {
            crystalode_tube(1, functionality + 1);
            flag = !flag;
        }

        if (P3_1 == 0) {
            delay(20);
            if (P3_1 == 0) {
                m = (m % 8) + 1;
                crystalode_tube(m, n);
                delay(100);
            }
        }

        if (P3_0 == 0) {
            delay(20);
            if (P3_0 == 0) {
                m = (m == 1) ? 8 : (m - 1);
                crystalode_tube(m, n);
                delay(100);
            }
        }

        if (P3_2 == 0) {
            delay(20);
            if (P3_2 == 0) {
                n = (n + 1) % 10;
                crystalode_tube(m, n);
                delay(100);
            }
        }

        if (P3_3 == 0) {
            delay(20);
            if (P3_3 == 0) {
                89
                flag = !flag;
                delay(100);
            }
        }
    }
}

void led_light(void) {
    unsigned char str = 0xff;
    P2 = str;

    while (functionality == 1) {
        if (flag == 1) {
            0-56入一个户籍不能开门了，。890i欧佩克里面；，。 0-=怕【=】、
            ‘/crystalode_tube(1, functionality + 1);
            flag = !flag;
        }

        if (P3_1 == 0) {
            delay(20);
            str = (str << 1) | 0x00;
            P2 = str;
            delay(200);
        }

        if (P3_0 == 0) {
            delay(20);
            str = (str >> 1) | 0x80;
            P2 = str;
            delay(200);
        }

        if (P3_2 == 0) {
            delay(20);
            str = 0xff;
            P2 = str;
            delay(200);
        }

        if (P3_3 == 0) {
            delay(20);
            if (P3_3 == 0) {
                functionality = (functionality + 1) % 3;
                flag = !flag;
                delay(100);
            }
        }
    }
}

// 流水灯功能
void running_light(void) {
    while (functionality == 2) {
        if (flag == 1) {
            crystalode_tube(1, functionality + 1);
            flag = !flag;
        }

        unsigned char str = 0xfe;
        P2 = str;

        if (P3_1 == 0) {
            for (int i = 0; i < 8; ++i) {
                delay(100);
                str = (str << 1) | 0x01;
                P2 = str;
            }
        }
        if (P3_3 == 0) {
            delay(20);
            if (P3_3 == 0) {
                P2 = 0xff;
                functionality = (functionality + 1) % 3;
                flag = !flag;
                delay(100);
            }
        }
        if(P3_2 == 0 ){
        }
    }
}


