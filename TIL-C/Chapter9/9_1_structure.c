#include <stdio.h>

struct Info
{
    char * name;
    int year;
    int price;
    char * company;
};

int main(void) {
    struct Info info1;
    info1.name = "게임";
    info1.year = 2022;
    info1.price = 50;
    info1.company = "회사명";

    printf("-- 게임 출시 정보--\n");
    printf("게임 이름 : %s\n", info1.name);
    printf("발매 연도 : %d\n", info1.year);
    printf("게임 가격 : %d\n", info1.price);
    printf("제작 회사 : %s\n", info1.company);
    
    return 0;
}