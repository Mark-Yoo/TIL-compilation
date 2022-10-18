#include <stdio.h>

int sum(int numA, int numB);
int sub(int numA, int numB);
int mul(int numA, int numB);
int div(int numA, int numB);

int main(void) {
    int numA;
    int numB;

    printf("첫 번째 숫자를 입력하세요.\n");
    scanf("%d", &numA);
    printf("두 번째 숫자를 입력하세요.\n");
    scanf("%d", &numB);

    printf("sum : %d\n", sum(numA, numB));
    printf("sub : %d\n", sub(numA, numB));
    printf("multiple : %d\n", mul(numA, numB));
    printf("divide : %d\n", div(numA, numB));
    return 0;
}

int sum(int numA, int numB) {
    return numA + numB;
}

int sub(int numA, int numB) {
    return numA - numB;
}

int mul(int numA, int numB) {
    return numA * numB;
}

int div(int numA, int numB) {
    return numA / numB;
}