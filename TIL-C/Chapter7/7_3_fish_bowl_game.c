#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int level;
int arrayFish[6];
int * cursor;

void initData(void);
void printFishes(void);
void decreaseWater(long elapsedTime);
int checkFishAlive(void);

int main(void) {
    int num;
    clock_t startTime = 0;
    clock_t prevElapsedTime = 0;
    double totalElapsedTime = 0;

    initData();
    startTime = clock();
    cursor = arrayFish;

    while (1) {
        printFishes();
        printf("물을 더할 어항은? (1-6) ");
        scanf("%d", &num);

        if (num < 1 || num > 6) {
            printf("\n입력값이 잘못되었습니다. 다시 확인해주세요\n");
            continue;
        }

        totalElapsedTime = (double)(clock() - startTime) / 1000;
        printf("총 경과 시간1 : %f초\n", totalElapsedTime);

        prevElapsedTime = totalElapsedTime - prevElapsedTime;
        printf("최근 경과한 시간 : %ld초\n", prevElapsedTime);

        decreaseWater(prevElapsedTime);

        if (cursor[num - 1] <= 0) {
            printf("%d번 어항의 물고기는 이미 죽어 물을 주지 않습니다.\n", num);
        } else if (cursor[num - 1] + 1 <= 100) {
            printf("%d번 어항에 물을 줍니다.\n\n", num);
            cursor[num - 1] += 1;
        }

        if (totalElapsedTime / 20 > level - 1) {
            level++;
            printf("*** 축하합니다. %d레벨에서 %d레벨로 올랐습니다. ***\n\n", level - 1, level);

            if (level == 5) {
                printf("\n\n축하합니다. 최고 레벨 달성! 게임을 종료합니다.\n\n");
                exit(0);
            }
        }

        if (checkFishAlive() == 0) {
            printf("모든 물고기가 죽었습니다 ㅠㅠㅠㅠㅠㅠㅠ");
            exit(0);
        } else {
            printf("물고기가 아직 살아 있어요!\n\n");
        }
        prevElapsedTime = totalElapsedTime;
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
        printf("  %3d ", arrayFish[i]);
    }
    printf("\n\n");
}

void decreaseWater(long elapsedTime) {
    for (int i = 0; i < 6; i++) {
        arrayFish[i] -= (3 * level * (int)elapsedTime);

        if (arrayFish[i] < 0) {
            arrayFish[i] = 0;
        }
    }
}

int checkFishAlive() {
    for (int i = 0; i < 6; i++) {
        if (arrayFish[i] > 0) {
            return 1;
        }
    }
    return 0;
}