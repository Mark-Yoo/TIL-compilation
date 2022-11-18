#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    FILE * file = fopen("c:\\Users\\사용자계절\\test1.txt", "rb");
    if (file = NULL) {
        printf("파일 열기 실패");
        return 1;
    }
    return 0;
}