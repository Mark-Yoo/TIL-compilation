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

void initCats(void);
void printCat(int selected);
int checkCollection(void);

int main(void) {
    srand(time(NULL));
    initCats();

    while (1) {
        printf("어떤 고양이가 나올까요? \n Press Enter to Find out!");
        getchar();

        int selected = rand() % 5;
        printCat(selected);

        collections[selected] = 1;
        int collectAll = checkCollection();
        if(collectAll == 1) {
            break;
        }
    }
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

void printCat(int selected) {
    printf("\n\n == 다음 고양이의 주인이 되었습니다! ==");
    printf(" 이름 : %s\n", cats[selected].name);
    printf(" 나이 : %d\n", cats[selected].age);
    printf(" 특징 : %s\n", cats[selected].character);
    printf(" 레벨 : ");

    for (int i = 0; i < cats[selected].level; i++) {
        printf("%s", "*");
    }

    printf("\n\n");
}

int checkCollection() {
    int collectAll = 1;
    printf("\n\n === 보유 고양이 목록 === \n\n");
    for (int i = 0; i < 5; i++) {
        if (collections[i] == 0) {
            printf("%10s", "(빈 상자)");
            collectAll = 0;
        } else {
            printf("%10s", cats[i].name);
        }
    }
    printf("\n===========\n\n");
    if (collectAll) {
        printf("\n\n축하합니다! 고양이 5마리를 모두 모았습니다!\n\n");
    }
    return collectAll;
}
