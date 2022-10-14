#include <stdio.h>
/* 전처리기 지시문
stdio.h는 표준 입춝력 함수를 포함하는 헤더 파일을 의미
 */

int main(void) {
    int age = 20;
    printf("%d\n", age);
    /* %d - 정수값일 때, %.nf - 실수값, %.nlf - 실수값, %c - 문자, %s - 문자열*/
    age = 21;
    printf("%d\n", age);
    return 0;
}