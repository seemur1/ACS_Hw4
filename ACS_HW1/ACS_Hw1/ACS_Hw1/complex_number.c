//------------------------------------------------------------------------------
// complex_number.c - содержит процедуру ввода параметров
// для уже созданного комплексного числа
//------------------------------------------------------------------------------

#include "extdata.h"
#include "complex_number.h"
#include "string.h"


//------------------------------------------------------------------------------
// Вывод параметров комплексного числа в файл
bool c_Out(void *me, FILE *fp) {
    fprintf(fp, "It is Complex Number: real value = %f"
                ", imaginary value = %f\n", *((double*)(me)),  *((double*)(me + doubleSize)));
    return true;
}

//------------------------------------------------------------------------------
// Ввод параметров комплексного числа из файла
int c_In(void *c, FILE *fp) {
    char buffer1[100], buffer2[100];
    if (fscanf(fp, "%s%s", buffer1, buffer2) == EOF) { return 2; }
    if ((((*((double*)(c)) = atof(buffer1)) == 0) && (strcmp(buffer1, "0") != 0)) ||
        (((*((double*)(c + doubleSize)) = atof(buffer2)) == 0) && (strcmp(buffer2, "0") != 0))) { return 0; }
    return 1;
}
// Случайный ввод параметров комплексного числа
bool c_InRnd(void *c) {
    *((double*)(c)) = Random();
    *((double*)(c + doubleSize)) = Random();
    return true;
}
