#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000

int main(void) {
    char str1[MAX];
    char str[MAX];
    int num[6] = { 0, 0, 0, 0, 0, 0 };
    int bonus = 0;
    FILE * file = fopen("사용자 디렉토리", "rb");
    if (file == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }
}