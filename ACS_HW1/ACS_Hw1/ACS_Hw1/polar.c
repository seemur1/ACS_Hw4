//------------------------------------------------------------------------------
// polar.c - содержит процедуру ввода параметров
// для уже созданного полярного числа.
//------------------------------------------------------------------------------

#include "extdata.h"
#include "polar.h"
#include "string.h"


//------------------------------------------------------------------------------
// Вывод параметров комплексного числа в файл
bool p_Out(void *me, FILE *fp) {
    fprintf(fp, "It is Polar Coords: radius = %f"
                ", angle = %f\n", *((double*)(me)), *((double*)(me + doubleSize)));
    return true;
}

//------------------------------------------------------------------------------
// Ввод параметров комплексного числа из файла
int p_In(void *p, FILE *fp) {
    char buffer1[100], buffer2[100];
    if (fscanf(fp, "%s%s", buffer1, buffer2) == EOF) { return 2; }
    if ((((*((double*)(p)) = atof(buffer1)) == 0) && (strcmp(buffer1, "0") != 0)) ||
        (((*((double*)(p + doubleSize)) = atof(buffer2)) == 0) && (strcmp(buffer2, "0") != 0))) { return 0; }
    return 1;
}

// Случайный ввод параметров комплексного числа
bool p_InRnd(void *p) {
    *((double*)(p)) = Random();
    *((double*)(p + doubleSize)) = Random();
    return true;
}