#include <stdio.h>

struct Animal {
    char * name;
    int age;
};

int main(void) {
    struct Animal animals[3] = {
        { "호랑이", 3 },
        { "사자", 5 },
        { "하마", 8 }
    };

    for (int i = 0; i < 3; i++) {
        printf("이름 : %s, 나이 : %d\n", animals[i].name, animals[i].age);
    }

    return 0;
}