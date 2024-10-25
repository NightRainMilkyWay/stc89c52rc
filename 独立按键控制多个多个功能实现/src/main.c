// ���ܰ����ɶ���������4������

#include "mcs51/8052.h"

void delay(unsigned int n);
void crystalode_tube(unsigned char m, unsigned char n);
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


void delay(unsigned int n) {
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < 120; ++j);
    }
}

// ����һ����ά�������洢 P2_4, P2_3, P2_2 ��״̬
const bit states[8][3] = {
        {0, 0, 0},  // case 0 (��ʹ��)
        {1, 1, 1},  // case 1
        {1, 1, 0},  // case 2
        {1, 0, 1},  // case 3
        {1, 0, 0},  // case 4
        {0, 1, 1},  // case 5
        {0, 1, 0},  // case 6
        {0, 0, 1},  // case 7
        {0, 0, 0}   // case 8
};

void setP2Pins(int m) {
    if (m < 1 || m > 8) return; // ��� m ����Ч��
    // ���� m ֵ���� P2_4, P2_3, P2_2
    P2_4 = states[m][0]; // ��Ӧ�� P2_4
    P2_3 = states[m][1]; // ��Ӧ�� P2_3
    P2_2 = states[m][2]; // ��Ӧ�� P2_2
}

void crystalode_tube(unsigned char m, unsigned char n) {
    unsigned char str[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

    setP2Pins(m);
    P0 = str[n];
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
                functionality = (functionality + 1) % 3;
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
            crystalode_tube(1, functionality + 1);
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

// ��ˮ�ƹ���
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
