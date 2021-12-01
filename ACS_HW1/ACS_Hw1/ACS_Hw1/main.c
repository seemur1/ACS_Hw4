//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------
#include "container.h"

#include "extdata.h"
#include "string.h"   // для функций strcmp
#include "time.h"     // для функций time()
#include <sys/stat.h> // Для функций stat
#include "math.h"

// Названия папок, в которые будут записываться результаты работы программ
const char test[100] = "./../ACS_Hw1_Tests/", res[100] = "./../ACS_Hw1_Results/";

void errMessage1() {
    printf("incorrect command line!\n  Waited:\n     command -f infile outfile01 outfile02\n");
    printf("  Or:\n     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n  Waited:\n     command -f infile outfile01 outfile02\n");
    printf("  Or:\n     command -n number outfile01 outfile02\n");
}

bool isFile(char* argv[], int * size) {
    if(!strcmp(argv[1], "-f")) { return true; }
    else if(!strcmp(argv[1], "-n")) { *size = atoi(argv[2]); }
    return false;
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    clock_t start, end;
    start = clock();
    if(argc != 5) {
        errMessage1();
        return 1;
    }
    printf("Start\n");
    sqrt(3);

    int size, length = 0;
    FILE *fp;

    // Собираем адреса файлов.
    char testDir[200], resDir1[200], resDir2[200];
    strcpy(testDir, test);
    strcpy(resDir1, res);
    strcpy(resDir2, res);
    // Задаём Директории хранения (для тестов и результатов).
    strcat(testDir, argv[2]);
    strcat(resDir1, argv[3]);
    strcat(resDir2, argv[4]);

    unsigned char c[maxSize];

    ///printf("argv[1] = %s\n", argv[1]);

    // Проверка иcточника данных
    if(isFile(argv, &size)) {
        struct stat buffer;
        if (stat(testDir, &buffer)) {
            printf("incorrect Name Of File!\n");
            return 4;
        }
        fp = fopen(testDir, "r");
        fscanf(fp, "%d", &size);
        if((size < 1) || (size > 10000)) {
            printf("incorrect numer of figures = %d. Set 0 < number <= 10000\n", size);
            return 3;
        }
        // Автоматичеcкое выделение памяти для маcива
        In(c, fp, &size, &length);
        fclose(fp);
    } else {
        if (!strcmp(argv[1], "-f") && !strcmp(argv[1], "-n")) {
            errMessage2();
            return 2;
        }
        // cиcтемные чаcы в качеcтве инициализатора
        srand((unsigned int)(time(0)));
        // Заполнение контейнера генератором cлучайных чиcел
        length = size;
        InRnd(c, size);
    }
    printf("size = %d\n", size);
    // Вывод cодержимого контейнера в файл
    fp = fopen(resDir1, "w+");
    fprintf(fp, "Filled container:\n");
    Out(c, fp, length);
    fclose(fp);

    // The 2nd part of task
    fp = fopen(resDir2, "w+");
    BinaryInsertion(&c, length);
    Out(c, fp, length);
    fprintf(fp, "\n");
    printf("Stop\n");
    end = clock();
    printf("time = %f\n", (double) (end - start) / CLOCKS_PER_SEC);
    return 0;
}