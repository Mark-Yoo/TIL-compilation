#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int chanceCount = 5;
    int answer = 0;
    
    srand(time(NULL));
    answer = rand() % 100 + 1;

    while (1) {
        int yourNum = 0;
        printf("Guess your lucky number in beteen 1 to 100! \n");
        scanf("%d", &yourNum);

        if (yourNum == answer) {
            printf("You are correct! Hope this is your lucky day!\n");
            break;
        } else {
            chanceCount--;
            printf("You are wrong! Try again! You, now have %d chance(s)\n", chanceCount);
            
            if (yourNum > answer) {
                printf("Answer is lower than your last answer\n\n");
            } else if (yourNum < answer) {
                printf("Answer is highter than your last answer\n\n");
            }
        }

        if (chanceCount == 0) {
            printf("The answer was %d\n", answer);
            printf("You've used all of your chances! Better luck next time!\n");
            printf("Game Over\n");
            break;
        }
    }

    return 0;
}