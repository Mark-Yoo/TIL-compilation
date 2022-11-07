#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    char * name;
    int age;
    char * character;
    int level;
} CAT;

CAT cats[5];
int collections[5] = { 0, 0, 0, 0, 0 };

void initCats();

int main(void) {
    initCats();
    return 0;
}

void initCats(void) {
    cats[0].name = "냥냥이";
    cats[0].age = 5;
    cats[0].character = "상냥함";
    cats[0].level = 1;
    cats[1].name = "콩콩이";
    cats[1].age = 3;
    cats[1].character = "온순함";
    cats[1].level = 2;
    cats[2].name = "점박이";
    cats[2].age = 3;
    cats[2].character = "게으름";
    cats[2].level = 3;
    cats[3].name = "호랭이";
    cats[3].age = 5;
    cats[3].character = "예민함";
    cats[3].level = 4;
    cats[4].name = "하울이";
    cats[4].age = 2;
    cats[4].character = "호기로움";
    cats[4].level = 5;
}