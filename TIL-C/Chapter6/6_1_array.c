#include <stdio.h>

int main(void) {
    int subway_array[3];
    int init_array1[10] = { 1, 2, 3, 4, 5, 6,};
    int init_array2[10];

    subway_array[0] = 30;
    subway_array[1] = 40;
    subway_array[2] = 50;

    for(int i = 0; i < 3; i++) {
        printf("%d 번째 차량 인원은 %d \n", i + 1, subway_array[i]);
        printf("init array1[%d] %d \n", i + 1, init_array1[i]);
        printf("init array2[%d] %d \n", i + 1, init_array2[i]);
    }

    return 0;
}