#include <stdio.h>

int main(void) {
    int arr[3] = { 5, 10, 15 };

    // 배열의 pointer 변수는 기본적으로 0번째 인덱스를 가리키므로 동일하게 배열을 찾아갈 수 있다.
    for (int i = 0; i < 3; i++) {
        printf("배열 arr[%d]의 값 : %d\n", i, arr[i]);
    }

    int * ptr = arr;
    for (int j = 0; j < 3; j++) {
        printf("포인터 변수 ptr[%d]의 값 : %d\n", j, ptr[j]);
    }
}