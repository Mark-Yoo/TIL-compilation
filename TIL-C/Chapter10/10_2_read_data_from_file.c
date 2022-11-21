#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000

int main(void) {
    char line[MAX];
    FILE * file = fopen("c:\\Users\\사용자계절\\test1.txt", "rb");
    if (file = NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }

    while ((fgets, MAX, file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}