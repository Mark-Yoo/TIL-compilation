#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arrayAnimal[4][5];
char * strAnimal[10];
int checkAnimal[4][5];

void initAnimalArray(void);
void initAnimalName(void);
void shuffleAnimal(void);
int getEmptyPosition(void);
int convert_pos_x(int x);
int convert_pos_y(int y);
void printAnimals(void);
void printQuestions(void);
int foundAllAnimals(void);


int main(void) {
    srand(time(NULL));
    initAnimalArray();
    initAnimalName();
    shuffleAnimal();

    int failCount = 0;
    
    while (1)
    {
        int select1 = 0;
        int select2 = 0;
        printAnimals();
        printQuestions();
        printf("\n뒤집을 카드를 2장 고르세요.(예 : 1 2)");
        scanf("%d %d", &select1, &select2);

        if (select1 == select2) {
            continue;
        }

        int firstSelect_x = convert_pos_x(select1);
        int firstSelect_y = convert_pos_y(select1);
        int secondSelect_x = convert_pos_x(select2);
        int secondSelect_y = convert_pos_y(select2);
    
        if ((checkAnimal[firstSelect_x][firstSelect_y] == 0 && checkAnimal[secondSelect_x][secondSelect_y] == 0) && (arrayAnimal[firstSelect_x][firstSelect_y] == arrayAnimal[secondSelect_x][secondSelect_y])) {
            printf("\n\n정답! %s 발견\n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            checkAnimal[firstSelect_x][firstSelect_y] = 1;
            checkAnimal[secondSelect_x][secondSelect_y] = 1;
        } else {
            printf("\n\n오답! 다른 동물 카드 혹은 이미 뒤집힌 카드.\n");
            printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
            printf("\n");
            failCount++;
        }

        if (foundAllAnimals() == 1) {
            printf("\n\n축하합니다! 모든 정답을 찾았습니다!");
            printf("총 %d번 실패했습니다!\n", failCount);
            break;
        }
    }
    return 0;
}

void initAnimalArray(void) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            arrayAnimal[i][j] = -1;
        }
    }
}

void initAnimalName(void) {
    strAnimal[0] = "원숭이";
    strAnimal[1] = "하마";
    strAnimal[2] = "강아지";
    strAnimal[3] = "고양이";
    strAnimal[4] = "돼지";
    strAnimal[5] = "코끼리";
    strAnimal[6] = "기린";
    strAnimal[7] = "낙타";
    strAnimal[8] = "타조";
    strAnimal[9] = "호랑이";
}

void shuffleAnimal(void) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            int pos = getEmptyPosition();
            int x = convert_pos_x(pos);
            int y = convert_pos_y(pos);
            arrayAnimal[x][y] = i;
        }
    }
}

int getEmptyPosition() {
    while (1) {
        int randomPos = rand() % 20;
        int x = convert_pos_x(randomPos);
        int y = convert_pos_y(randomPos);

        if (arrayAnimal[x][y] == -1) {
            return randomPos;
        }
    }
    return 0;
}

int convert_pos_x(int x) {
    return x / 5;
}

int convert_pos_y(int y) {
    return y % 5;
}

void printAnimals() {
    printf("\n===== 동물 위치. =====\n\n");

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%8s", strAnimal[arrayAnimal[i][j]]);
        }
        printf("\n");
    }
}

void printQuestions() {
    printf("\n(문제)\n\n");
    
    int seq = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (checkAnimal[i][j] != 0) {
                printf("%8s", strAnimal[arrayAnimal[i][j]]);
            } else {
                printf("%8d", seq);
            }
            seq++;
        }
        printf("\n");
    }
}

int foundAllAnimals() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (checkAnimal[i][j] == 0) {
                return 0;
            }
        }
    } 
    return 1;
}