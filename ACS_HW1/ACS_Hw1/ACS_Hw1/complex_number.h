#ifndef ACS_HW1_COMPLEX_NUMBER_H
#define ACS_HW1_COMPLEX_NUMBER_H

//------------------------------------------------------------------------------
// complex_number.h - содержит описание комплексного числа и его интерфейса
//------------------------------------------------------------------------------

#include "rnd.h"
#include <stdbool.h>
#include <stdio.h>
#include "math.h"


// Вычисление "длины" комплексного числа.
double c_cast (void *me);

// Вывод параметров комплексного числа в файл
bool c_Out (void *me, FILE *fp);

// Ввод параметров комплексного числа из файла
int c_In(void *c, FILE *fp);

// Случайный ввод параметров комплексного числа.
bool c_InRnd(void *c);

#endif //ACS_HW1_COMPLEX_NUMBER_H
