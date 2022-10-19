#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        int numA = rand() % 9 + 1;
        int numB = rand() % 9 + 1;
        int result;

        printf("%d X %d = ", numA, numB);
        scanf("%d", &result);

        if (numA * numB != result) {
            printf("오답입니다! You shall not pass!");
            break;
        }

        if (i == 4) {
            printf("정답입니다! Now you shall pass!");
        }
    }

    return 0;
}