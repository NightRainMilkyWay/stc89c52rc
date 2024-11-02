//
// Created by NightRain on 2024/10/26.
//
#include "mcs51/8052.h"

typedef unsigned int u16;
extern u16 h1;
extern u16 h2;
extern u16 m1;
extern u16 m2;
extern u16 s1;
extern u16 s2;

void Delay(unsigned int xms) {
    unsigned char i, j;
    for (; xms > 0; xms--)  // 外层循环，控制毫秒数
    {
        for (i = 2; i > 0; i--)  // 控制内层循环次数
        {
            for (j = 239; j > 0; j--);  // 空循环，造成延迟
        }
    }
}


//数码管显示子函数
void Nixie(unsigned char Location, unsigned int Number) {
    unsigned char NixieTable[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x40};
    switch (Location)        //位码输出
    {
        case 1:
            P2_4 = 1;
            P2_3 = 1;
            P2_2 = 1;
            break;
        case 2:
            P2_4 = 1;
            P2_3 = 1;
            P2_2 = 0;
            break;
        case 3:
            P2_4 = 1;
            P2_3 = 0;
            P2_2 = 1;
            break;
        case 4:
            P2_4 = 1;
            P2_3 = 0;
            P2_2 = 0;
            break;
        case 5:
            P2_4 = 0;
            P2_3 = 1;
            P2_2 = 1;
            break;
        case 6:
            P2_4 = 0;
            P2_3 = 1;
            P2_2 = 0;
            break;
        case 7:
            P2_4 = 0;
            P2_3 = 0;
            P2_2 = 1;
            break;
        case 8:
            P2_4 = 0;
            P2_3 = 0;
            P2_2 = 0;
            break;
    }
    P0 = NixieTable[Number];    //段码输出
    Delay(1);                //显示一段时间
    P0 = 0x00;                //段码清0，消影
}


void digital_tube(void) {
    Nixie(1, h1);
    Nixie(2, h2);
    Nixie(3, 10);
    Nixie(4, m1);
    Nixie(5, m2);
    Nixie(6, 10);
    Nixie(7, s1);
    Nixie(8, s2);
}


/**
  * @brief  获取独立按键键码
  * @param  无
  * @retval 按下按键的键码，范围：0~4，无按键按下时返回值为0
  */
unsigned char Key(void) {
    unsigned char KeyNumber = 0;

    if (P3_1 == 0) {
        Delay(20);
        while (P3_1 == 0);
        Delay(20);
        KeyNumber = 1;
    }
    if (P3_0 == 0) {
        Delay(20);
        while (P3_0 == 0);
        Delay(20);
        KeyNumber = 2;
    }
    if (P3_2 == 0) {
        Delay(20);
        while (P3_2 == 0);
        Delay(20);
        KeyNumber = 3;
    }
    if (P3_3 == 0) {
        Delay(20);
        while (P3_3 == 0);
        Delay(20);
        KeyNumber = 4;
    }

    return KeyNumber;
}
