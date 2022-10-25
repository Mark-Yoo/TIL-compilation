#include <stdio.h>
#include <time.h>

int level;
int arrayFish[6];
int num;

void initData(void);
void printFishes(void);
void decreaseWater(void);

int main(void) {
    long startTime = 0;
    long totalElapsedTime = 0;
    long prevElapsedTime = 0;

    initData();
    startTime = clock();
    while (1) {
        printFishes();
        printf("물을 더할 어항은? (1-6) ");
        scanf("%d", &num);

        if (num < 1 || num > 6) {
            printf("\n입력값이 잘못되었습니다. 다시 확인해주세요\n");
            continue;
        }

        totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC;
        printf("총 경과 시간 : %ld초\n", totalElapsedTime);

        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("최근 경과한 시간 : %ld\n", prevElapsedTime);
    }
    return 0;
}

void initData() {
    level = 1;

    for (int i = 0; i < 6; i++) {
        arrayFish[i] = 100;
    }
}

void printFishes() {
    printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
    for (int i = 0; i < 6; i++) {
        printf("    %3d ", arrayFish[i]);
    }
    printf("\n\n");
}

void decreaseWater() {

}