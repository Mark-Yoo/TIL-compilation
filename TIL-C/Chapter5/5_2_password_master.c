#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int getRandomNum(int level);
void printQuestions(int level, int numA, int numB);

int main(void) {
    srand(time(NULL));
    int answerCount = 0;

    for (int i = 1; i <= 5; i++) {
        int numA = getRandomNum(1);
        int numB = getRandomNum(1);
        int answer;

        printQuestions(i, numA, numB);
        scanf("%d", &answer);

        if (answer == -1) {
            printf("프로그램을 종료합니다.");
            break;
        }

        if (numA * numB != answer) {
            printf("틀렸습니다! You shall not pass!");
            break;
        }

        answerCount++;
        if (i < 5) {
            printf("지금까지 총 %d개 정답!", answerCount);
        } else {
            printf("축하합니다! 문제를 전부 맞추셨습니다!");
        }
    }

    return 0;
}

int getRandomNum(int level) {
    return rand() % (level * 9) + 1;
}

void printQuestions(int level, int numA, int numB) {
    if (level == 1) {
        printf("\n종료를 원하시면 -1을 입력하세요\n\n");
    }
    printf("%d 번째 문제\n", level);
    printf("%d X %d = ", numA, numB);
}