#include <stdio.h>

struct Info {
    char * name;
    int year;
    int price;
    char * company;
    struct Info * subInfo;
};

int main(void) {
    typedef struct Info helpfulInfo;
    helpfulInfo info1;
    info1.name = "Mark";
    info1.year = 2022;
    return 0;
}