//
// Created by NightRain on 2024/11/2.
//

#include "add.h"
#include "test.h"

typedef unsigned int u16;
extern u16 h1;
extern u16 h2;
extern u16 m1;
extern u16 m2;
extern u16 s1;
extern u16 s2;

int *p1 = &s1;
int *p2 = &s2;
int *k1 = &m1;
int *k2 = &m2;
int *j1 = &h1;
int *j2 = &h2;

void add(void) {
    if (*p2 < 9) {
        (*p2)++;
    } else {
        *p2 = 0;
        if (*p1 < 5) {
            (*p1)++;
        } else {
            *p1 = 0;
            if (*k2 < 9) {
                (*k2)++;
            } else {
                *k2 = 0;
                if (*k1 < 5) {
                    (*k1)++;
                } else {
                    *k1 = 0;
                    if (*j1 < 9) {
                        (*j2)++;
                    } else {
                        *j2 = 0;
                        if (*j1 < 9) {
                            (*j1)++;
                        } else {
                            *j1 = 0;
                        }
                    }
                }
            }
        }
    }
    digital_tube();
}

void red(void) {
    if (*p1 == *p2 && *p1 == *k1 && *p1 == *k2 && *p1 == *j1 && *p1 == *j2) {
        digital_tube();
    } else {

        if (*p2 > 0) {
            (*p2)--;
        } else {
            *p2 = 9;
            if (*p1 > 0) {
                (*p1)--;
            } else {
                *p1 = 5;
                if (*k2 > 0) {
                    (*k2)--;
                } else {
                    *k2 = 9;
                    if (*k1 > 0) {
                        (*k1)--;
                    } else {
                        *k1 = 5;
                        if (*j2 > 0) {
                            (*j2)--;
                        } else {
                            *j2 = 9;
                            if (*j1 > 0) {
                                (*j1)--;
                            } else {
                                *j1 = 9;
                            }
                        }
                    }
                }
            }
        }
    }
    digital_tube();
}
