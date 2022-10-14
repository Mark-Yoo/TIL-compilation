#include <stdio.h>

int main(void) {
    char name[256];
    printf("Input your name\n");
    scanf("%s", name);

    int age;
    printf("Input your age\n");
    scanf("%d", &age);

    float weight;
    printf("Input your weight (don't lie)\n");
    scanf("%f", &weight);

    float height;
    printf("Input your height (DON'T LIE)\n");
    scanf("%f", &height);

    char crime[256];
    printf("What are you here for?\n");
    scanf("%s", crime);

    printf("\n\n --- Criminal Profile --- \n\n");
    printf("name : %s\n", name);
    printf("age : %d\n", age);
    printf("weight : %.2f\n", weight);
    printf("height : %.1f\n", height);
    printf("What are you here for? %s\n", crime);

    return 0;
}