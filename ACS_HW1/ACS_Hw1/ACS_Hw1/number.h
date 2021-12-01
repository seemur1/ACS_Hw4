#ifndef ACS_HW1_NUMBER_H
#define ACS_HW1_NUMBER_H

//------------------------------------------------------------------------------
// number.h - содержит описание обобщённого числа и его интерфейса
//------------------------------------------------------------------------------

#include "rnd.h"
#include <stdbool.h>
#include <stdio.h>
#include "fraction.h"
#include "complex_number.h"
#include "polar.h"

// Вывод параметров обобщённого числа в файл
bool n_Out (void *me, FILE *fp);

// Ввод параметров обобщённого числа из файла
int n_In(void *n, FILE *fp);

// Ввод случайных обобщённого полярного числа
bool n_InRnd(void *n);

#endif //ACS_HW1_NUMBER_H
