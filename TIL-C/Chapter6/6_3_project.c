#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    int treatment;
    srand(time(NULL));

    treatment = rand() % 4;
    printf("\n\n === 치료제를 찾아라! === \n\n");
    
    for (int i = 1; i <= 3; i++) {
        int bottle[4] = {0, 0, 0, 0};
        int cntShowBottle = 0;
        int prevCntShowBottle = 0;

        do {
           cntShowBottle = rand() % 2 + 2;
        } while (cntShowBottle == prevCntShowBottle);

        prevCntShowBottle = cntShowBottle;
        printf(" > %d번째 테스트 : \n", i);

        int isIncluded = 0;
        for (int j = 0; j < cntShowBottle; j++) {
            int randBottle = rand() % 4;
            if (bottle[randBottle] == 0) {
                bottle[randBottle] = 1;

                if (randBottle == treatment) {
                    isIncluded = 1;
                }
            } else {
                j--;
            }
        }

        for (int k = 0; k < 4; k++) {
            if (bottle[k] == 1) {
                printf("%d번 ", k + 1);
            }
        }
        printf("치료제를 사용합니다.\n\n");

        if (isIncluded == 1) {
            printf(">> 성공! 치료에 성공하였습니다!\n");
        } else {
            printf(">> 실패! 치료에 실패하였습니다!\n");
        }
        printf("\n 계속 진행하시려면 Enter를 누르세요 \n");
        (void) getchar();
    }
    printf("치료제는 몇 번일까요?");
    int answer;
    scanf("%d", &answer);

    if (answer == treatment + 1) {
        printf("정답입니다!");
    } else {
        printf("오답입니다! 정답은 %d 번입니다!", treatment + 1);
    }
    return 0;
}