//------------------------------------------------------------------------------
// container.c - содержит функции обработки контейнера
//------------------------------------------------------------------------------
#include "container.h"
#include "extdata.h"

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного файла
void In(void *c, FILE *fp, const int* size, int *length) {
    int result;
    while(*length < *size) {
        result = n_In(c + *length * numberSize, fp);
        if (result == 1) { (*length)++; }
        else if (result == 2) { return; }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(void *c, int size) {
    int counter = 0;
    printf("Start Rnd\n");
    while(counter < size) {
        n_InRnd(c + counter++ * numberSize);
    }
    printf("End Rnd\n");
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(void *c, FILE *fp, int length) {
    fprintf(fp, "Container contains %d elements.\n", length);
    int i;
    for(i = 0; i < length; i++) {
        fprintf(fp, "%d: ", i);
        n_Out(c + i * numberSize, fp);
    }
}

//------------------------------------------------------------------------------
// Поиск позиции для вставки (через бин поиск)
/*
int BinarySearch(void *c, void *item, int l_border, int r_border) {
    if (r_border <= l_border) { return (n_cast(item) > n_cast(c + l_border * numberSize)) ? (l_border + 1) : l_border; }

    int mid = (l_border + r_border) / 2;

    if (n_cast(item) == n_cast(c + mid * numberSize)) { return mid + 1; }

    if (n_cast(item) > n_cast(c + mid * numberSize)) { return BinarySearch(c, item, mid + 1, r_border); }
    return BinarySearch(c, item, l_border, mid - 1);
}
*/

//------------------------------------------------------------------------------
// Сортировка бинарными вставками

/*
void BinaryInsertion(void *c, int length) {
    int loc, counter;
    void *selected;
    double f_value, s_value;

    int j;
    for (j = 0; j < length - 1; ++j)
    {
        counter = j;
        selected = c + (counter + 1) * numberSize;
        int k = *((int*)selected);
        if (k != FRACTION) {
            f_value = *((double*)(selected + intSize));
            s_value = *((double*)(selected + intSize + doubleSize));
        } else {
            f_value = (double)*((int*)(selected + intSize));
            s_value = (double)*((int*)(selected + intSize + doubleSize));
        }
        // find location where selected should be inserted
        loc = BinarySearch(c, selected, 0, counter + 1);
        // Move all elements after location to create space
        while (counter >= loc) {
            selected = c + (counter + 1) * numberSize;
            *((int*)(selected)) = *((int*)(selected - numberSize));
            if (*((int*)(selected)) != FRACTION) {
                *((double*)(selected + intSize)) = *((double*)(selected - numberSize + intSize));
                *((double*)(selected + intSize + doubleSize)) = *((double*)(selected - numberSize + intSize + doubleSize));
            } else {
                *((int*)(selected + intSize)) = *((int*)(selected - numberSize + intSize));
                *((int*)(selected + intSize + doubleSize)) = *((int*)(selected - numberSize + intSize + doubleSize));
            }
            counter--;
        }
        selected = c + (counter + 1) * numberSize;
        *((int*)selected) = k;
        if (k != FRACTION) {
            *((double*)(selected + intSize)) = f_value;
            *((double*)(selected + intSize + doubleSize)) = s_value;
        } else {
            *((int*)(selected + intSize)) = (int)f_value;
            *((int*)(selected + intSize + doubleSize)) = (int)s_value;
        }
    }
}
*/
