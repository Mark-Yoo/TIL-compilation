#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int randomNum;

    srand(time(NULL));
    randomNum = rand() % 10 + 1;
    printf("%d", randomNum);

    return 0;
}