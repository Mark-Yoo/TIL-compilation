#include <stdio.h>

int main(void) {
    int numA;
    int numB;
    printf("첫 번째 인수를 입력하세요\n");
    scanf("%d", &numA);
    printf("두 번째 인수를 입력하세요\n");
    scanf("%d", &numB);
    printf("%d + %d = %d\n", numA, numB, numA + numB);
    return 0;
}