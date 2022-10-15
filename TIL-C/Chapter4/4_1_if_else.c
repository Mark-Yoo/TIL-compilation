#include <stdio.h>

int main(void) {
    int age;

    printf("How old are you? \n");
    scanf("%d", &age);

    if (age >= 8 && age <= 13) {
        printf("You must be an elementary student!");
    } else if (age >= 14 && age <= 16) {
        printf("You must be a middle school student!");
    } else if (age >= 17 && age <= 19) {
        printf("You must be a high school student!");
    } else {
        printf("You must be someone else!");
    }

    return 0;
}