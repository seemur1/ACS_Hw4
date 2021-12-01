//------------------------------------------------------------------------------
// fraction.c - содержит процедуру ввода параметров
// для уже созданной дроби
//------------------------------------------------------------------------------

#include "extdata.h"
#include "fraction.h"
#include "string.h"
#include "stdlib.h"


//------------------------------------------------------------------------------
// Вывод параметров дроби в файл
bool f_Out(void *me, FILE *fp) {
    fprintf(fp, "It is Fraction: numerator = %d"
                ", denominator = %d\n", *((int*)(me)), *((int*)(me + doubleSize)));
    return true;
}

//------------------------------------------------------------------------------
// Ввод параметров дроби из файла
int f_In(void *f, FILE *fp) {
    char buffer1[100], buffer2[100], buffer3[100], buffer4[100];
    if (fscanf(fp, "%s%s", buffer1, buffer2) == EOF) { return 2; }
    strcpy(buffer3, buffer1);
    strcpy(buffer4, buffer2);
    sprintf(buffer1, "%d", *((int*)(f)) = atoi(buffer1));
    sprintf(buffer2, "%d", *((int*)(f + doubleSize)) = atoi(buffer2));
    if ((strlen(buffer1) != strlen(buffer3)) ||
        (strlen(buffer2) != strlen(buffer4)) ) {
        return 0;
    }
    return 1;
}

// Случайный ввод параметров дроби
bool f_InRnd(void *f) {
    *((int*)(f)) = Random();
    *((int*)(f + doubleSize)) = Random();
    return true;
}
