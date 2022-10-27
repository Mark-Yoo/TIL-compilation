#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int arrayAnimal[4][5];
char * strAnimal[10];

void initAnimalArray(void);
void initAnimalName(void);
void shuffleAnimal(void);
int getEmptyPosition(void);

int main(void) {
    srand(time(NULL));
    initAnimalArray();
    initAnimalName();
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