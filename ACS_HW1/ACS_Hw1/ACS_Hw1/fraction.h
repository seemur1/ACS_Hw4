#ifndef ACS_HW1_FRACTION_H
#define ACS_HW1_FRACTION_H

//------------------------------------------------------------------------------
// fraction.h - содержит описание дроби и её интерфейса
//------------------------------------------------------------------------------

#include "rnd.h"
#include <stdbool.h>
#include <stdio.h>

// Подсчёт значения дроби
double f_cast (void *me);

// Вывод параметров дроби в файл
bool f_Out (void *me, FILE *fp);

// Ввод параметров дроби из файла
int f_In(void *f, FILE *fp);

// Ввод случайных параметров дроби
bool f_InRnd(void *f);

#endif //ACS_HW1_FRACTION_H
