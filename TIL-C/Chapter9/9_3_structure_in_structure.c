#include <stdio.h>

struct Info {
    char * name;
    int year;
    int price;
    char * company;
    struct Info * otherInfo;
};

int main(void) {
    struct Info product1;
    product1.name = "제품1";
    product1.year = 2022;
    product1.price = 50;
    product1.company = "제품회사1";
    
    struct Info product2 = { "제품2", 2020, 30, "제품회사2" };
    product1.otherInfo = &product2;

    return 0;
}