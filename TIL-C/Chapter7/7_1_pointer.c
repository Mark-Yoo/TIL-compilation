#include <stdio.h>

int main(void) {
    int a = 1;
    int b = 2;
    int c = 3;

    printf("포인터 : %p // 값 : %d\n", &a, a);
    printf("포인터 : %p // 값 : %d\n", &b, b);
    printf("포인터 : %p // 값 : %d\n", &c, c);

    return 0;
}