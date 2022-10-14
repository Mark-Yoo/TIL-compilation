#include <stdio.h>

int main(void) {
    int i = 1;

    /* 무조건 한 번은 실행하는 do while문 예제 */    
    do {
        printf("Count : %d\n", i++);
    } while (i <= 10);

    return 0;
}