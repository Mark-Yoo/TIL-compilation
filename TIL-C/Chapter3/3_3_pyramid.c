#include <stdio.h>

int main(void) {
    int stairs;
    char indivStairs[256];

    printf("몇 층짜리 피라미드?\n");
    scanf("%d", &stairs);

    for (int i = 0; i < stairs; i++) {
        for (int j = 0; j < stairs - i; j++) {
            printf(" ");
        }

        for (int k = 0; k < (i * 2) + 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}