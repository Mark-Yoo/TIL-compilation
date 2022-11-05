#include <stdio.h>

struct Info {
    char * name;
    int year;
    int price;
    char * company;
    struct Info * subInfo;
};

typedef struct {
    char * name;
    int year;
    int price;
    char * company;
    struct Info * subInfo;
} INFO_STRUCT;

int main(void) {
    typedef struct Info helpfulInfo;
    helpfulInfo info1;
    info1.name = "Mark";
    info1.year = 2022;

    INFO_STRUCT info2;
    info2.name = "Julie";
    info2.year = 2022;
    return 0;
}