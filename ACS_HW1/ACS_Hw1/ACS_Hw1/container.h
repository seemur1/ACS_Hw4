#ifndef ACS_HW1_CONTAINER_H
#define ACS_HW1_CONTAINER_H

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "number.h"

//------------------------------------------------------------------------------

// Подсчёт значения обобщённого числа.
double n_cast(void *me);

// Ввод содержимого контейнера из указанного потока
void In(void *c, FILE *fp, const int *size, int *length);

// Случайный ввод содержимого контейнера
void InRnd(void *c, int size);

// Вывод содержимого контейнера в указанный файл
void Out(void *c, FILE *fp, int length);

// Поиск позиции для вставки (через бин поиск)
int BinarySearch(void *c, void *item, int l_border, int r_border);

// Сортировка бинарными вставками
void BinaryInsertion(void *c, int length);

#endif //ACS_HW1_CONTAINER_H
