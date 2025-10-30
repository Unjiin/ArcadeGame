#include "gameMenu.h"
#include "utilities.h"
#include "games.h"
#include <stdio.h>
#include <stdlib.h>
void startGameMenu(int* isExit, int* difficulty, int* exp) {
    int userInput;
    int isBack = 0;
    system("clear");
    while (1) {
        // очищение
        printf("\
+------------------+\n\
|     GAME MENU    |\n\
| ---------------- |\n\
| 1. Lucky Game    |\n\
| 2. Find Pairs    |\n\
| 3. Back          |\n\
| 0. Exit          |\n\
+------------------+\n\
Your choose: ");
        scanf("%d", &userInput);
        while (userInput < 0 || userInput > 2) {
            printf("Unexpected number\n");
            scanf("%d", &userInput);
        }
        switch (userInput) {
            case 1: {
                int status = startLuckyGame(difficulty);
                if (status) {
                    printf("You win!!\n\n");
                    *exp += 10;
                } else {
                    printf("You lose :(\n\n");
                    *exp -= 10;
                }
                break;
            }
            case 2: {
                int status = startFindPairsGame(difficulty);
                if (status) {
                    printf("You win!!\n\n");
                    *exp += 10;
                } else {
                    printf("You lose :(\n\n");
                    *exp -= 10;
                }
                break;
            }
            case 3:
                isBack = 1;
                break;
            case 0:
                *isExit = 1;
                break;
            default:
                printf("Unexpected number\n");
        }
        if (*isExit || isBack) break;
    }
}
int startSettings(int* difficulty) {
    int userInput;
    system("clear");
    printf("\
+------------------------------+\n\
|   SETTINGS                   |\n\
| ---------------------------- |\n\
| Current difficulty: %s|\n\
| 0. Easy                      |\n\
| 1. Medium                    |\n\
| 2. Hard                      |\n\
+------------------------------+\n\
Write difficulty: ", namesOfDifficulty[*difficulty]);
    scanf("%d", &userInput);
    while (userInput < 0 || userInput > 2) {
        printf("Unexpected number\n");
        scanf("%d", &userInput);
    }
    *difficulty = userInput;
    system("clear");
    printf("\
+------------------------------+\n\
|   SUCCESS                    |\n\
| ---------------------------- |\n\
| New difficulty: %s    |\n\
+------------------------------+\n\n", namesOfDifficulty[*difficulty]);
    return 1;

}