#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define DEBUG
#include "gameMenu.h"
void startMainMenu() {
    int userInput;
    int isExit = 0;
    int difficulty = 0;
    int exp = 0;
    system("clear");
    while (1) {
        // очищение
        printf("\
+------------------+\n\
|     MAIN MENU    |\n\
| ---------------- |\n\
| 1. Play          |\n\
| 2. Settings      |\n\
| 0. Exit          |\n\
+------------------+\n\
Your choose: ");
        scanf("%d", &userInput);
        while (userInput < 0 || userInput > 2) {
            printf("Unexpected number\n");
            scanf("%d", &userInput);
        }
        switch (userInput) {
            case 1:
                startGameMenu(&isExit, &difficulty, &exp);
                system("clear");
                break;
            case 2:
                startSettings(&difficulty);
                break;
            case 0:
                isExit = 1;
                break;
            default:
                printf("Unexpected number\n");
        }
        if (isExit) {
            printf("\
+-----------------+\n\
|   TOTAL         |\n\
| --------------- |\n\
| Experience: %d |\n\
+-----------------+\n\n", exp);
            break;
        };
    }
}

int main() {
    srand(time(0));
    startMainMenu();

    return 0;
}