#if !defined(ACS_HW1_DATA_H)
#define ACS_HW1_DATA_H


// Константа, определяющая размер числа с плавающей точкой.
int const doubleSize = sizeof(double);
// Константа, определяющая размер целого числа
int const intSize = sizeof(int);
// Константа, задающая размер для полярных координат
int const polarSize = 2 * sizeof(double);
// Константа, задающая размер для дробей
int const fractSize = 2 * sizeof(int);
// Константа, задающая размер для комплексных чисел.
int const complexSize = 2 * sizeof(double);
// Константа, задающая размер для треугольника
int const numberSize = sizeof(int) + polarSize;
// Константа, определяющая размерность массива фигур
int const maxSize = 10000 * numberSize;
// Константа, задающая признак полярных координат
int const FRACTION = 1;
// Константа, задающая признак дроби
int const POLAR = 2;
// Константа, задающая признак комплексного числа
int const COMPLEX = 3;

#endif //ACS_HW1_DATA_H
