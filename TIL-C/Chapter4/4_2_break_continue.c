#include <stdio.h>

int main(void) {
    printf("다음 학생들은 교무실로 오세요\n");

    for (int i = 0; i < 30; i++) {
        if (i >= 5 && i <= 20) {
            if (i == 11 || i == 13 || i == 16) {
                printf("%d 번 학생은 안 와도 됩니다\n", i);
                continue;
            }
            printf("%d 번 학생\n", i);
        }
    }
    return 0;
}