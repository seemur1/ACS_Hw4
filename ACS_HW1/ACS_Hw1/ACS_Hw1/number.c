//------------------------------------------------------------------------------
// number.c - содержит процедуру ввода параметров
// для уже созданного обобщённого числа.
//------------------------------------------------------------------------------
#include "number.h"
#include "data.h"

//------------------------------------------------------------------------------
// Вывод параметров обобщённого числа в файл
bool n_Out(void *n, FILE *fp) {
    switch(*((int*)n)) {
        case 3:
            return c_Out(n + intSize, fp);
        case 2:
            return p_Out(n + intSize, fp);
        case 1:
            return f_Out(n + intSize, fp);
        default:
            fprintf(fp, "Incorrect figure!\n");
            return false;
    }
}

//------------------------------------------------------------------------------
// Ввод параметров обобщённого числа из файла
int n_In(void *n, FILE *fp) {
    int number_type;
    if (fscanf(fp, "%d", &number_type) == EOF) { return 2; }
    *((int*)n) = number_type;
    switch(number_type) {
        case 1:
            return f_In(n + intSize, fp);
        case 2:
            return p_In(n + intSize, fp);
        case 3:
            return c_In(n + intSize, fp);
        default:
            *((int*)n) = -1;
            return 0;
    }
}

// Случайный ввод параметров обобщённого числа
bool n_InRnd(void *n) {
    *((int*)n) = (abs(rand()) % 3) + 1;
    switch(*((int*)n)) {
        case 1:
            return f_InRnd(n + intSize);
        case 2:
            return p_InRnd(n + intSize);
        default:
            return c_InRnd(n + intSize);
    }
}
