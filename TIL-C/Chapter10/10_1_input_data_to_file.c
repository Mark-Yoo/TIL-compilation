#include <stdio.h>

int main(void) {
    FILE * file = fopen("C:\\Users\\사용자계정\\test1.txt", "wb");
    if (file == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }
    return 0;
}