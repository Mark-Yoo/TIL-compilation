#include <stdio.h>

typedef struct {
    char * name;
    int age;
    char * character;
    int level;
} CAT;

CAT cats[5];
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
}