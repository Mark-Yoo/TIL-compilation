#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void) {
    int totalGrades = 0;
    int grades[5] = {0, 0, 0, 0, 0};

    for (int i = 0; i < 5; i++) {
        printf("%d번 과목의 성적을 입력하세요\n", i + 1);
        scanf("%d", &grades[i]);
        totalGrades += grades[i];
    }
    printf("총점 : %d\n", totalGrades);
    printf("평균 : %.2d", totalGrades / 5);

    return 0;
}