#include "utilities.h"
#include "games.h"
#include <stdio.h>
#include <stdlib.h>
int startLuckyGame(int* difficulty) {
    int userNumber, computerNumber;
    computerNumber = 1 + rand() % difficultyValues[*difficulty]; // [1, 10]
    system("clear");
    // printf("%d\n\n", computerNumber);
    printf("\
+------------------------------+\n\
|   CHOOSE NUMBER              |\n\
| ---------------------------- |\n\
| Current difficulty: %s|\n\
| Choose number from 0 from %d |\n\
+------------------------------+\n\
Your choose: ", namesOfDifficulty[*difficulty], difficultyValues[*difficulty]);
    scanf("%d", &userNumber);
    system("clear");
    return userNumber == computerNumber;

}
void insert_int(int arr[], int size, int index, int value) {
    for (int i = size-1; i > index; i--) {
        arr[i] = arr[i-1];
    }
    arr[index] = value;
}
int startFindPairsGame(int* difficulty) {
    int userInput;
    int health = 5;
    int length = 5*(*difficulty + 1);
    int countCards = 0;
    int* cards = (int*)malloc(sizeof(int) * (length*2));
    int* cardsStatus = (int*)calloc((length*2), sizeof(int));
    for (int i = 0; i < length; i++) {
        cards[i] = i + 1;
        cards[i + length] = i + 1;
    }
    for (int i = length * 2 - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
    // for (int i = 0; i < length*2; i++) {
    //     int random = rand() % length - 1;
    //     insert_int(cards, length*2, random, i+1);
    // }
    for (int i = 0; i < length * 2; i++) {
    printf("cardsStatus[%d] = %d\n", i, cardsStatus[i]);
}
    while (countCards != length*2 && health) {
        system("clear");
        int hasPairs = countCards % 2;
        if (countCards > 0) {
            if (!hasPairs) {
                int* counter = (int*)calloc(length, sizeof(int));
                for (int i = 0; i < length*2; i++) {
                    if (cardsStatus[i]) {
                        int val = cards[i] - 1;
                        counter[val] ^= 1;
                        // if (counter[i] != 0) counter[i] = 0;
                        // else counter[i] = 1;
                    }
                }
                int valOfCounter = 0;
                for (int i = 0; i < length; i++) {
                    valOfCounter += counter[i];
                }
                if (valOfCounter > 0) {
                    printf("\
+------------------+\n\
|      UNLUCK      |\n\
+------------------+\n");
                    health--;
                    if (health <= 0) break;
                    for (int i = 0; i < length; i++) {
                        if (counter[i]) {
                            for (int j = 0; j < length*2; j++) {
                                if (cards[j] == i+1) {
                                    cardsStatus[j] = 0;
                                }
                            }
                        }
                    }
                } else {
                    printf("\
+------------------+\n\
|      GREAT       |\n\
+------------------+\n");
                }
            free(counter);
            } else {
                printf("\
+--------------------------------+\n\
|      CHOOSE ANOUTHER ONE       |\n\
+--------------------------------+\n");
            
            }
        }
        printf("\
+------------------+\n\
|   CHOOSE CARD    |\n\
|   HEALTH: %d      |\n\
+------------------+\n", health);
        for (int i = 0; i <= 5*(*difficulty + 1); i += 5) {
            int isOpen[] = {
                cardsStatus[i] ? cards[i] : 0,
                cardsStatus[i+1] ? cards[i+1] : 0,
                cardsStatus[i+2] ? cards[i+2] : 0,
                cardsStatus[i+3] ? cards[i+3] : 0,
                cardsStatus[i+4] ? cards[i+4] : 0,
            };
            printf("\
+-------+ +-------+ +-------+ +-------+ +-------+\n\
|       | |       | |       | |       | |       |\n\
|   %s  | |   %s  | |   %s  | |   %s  | |   %s  |\n\
|       | |       | |       | |       | |       |\n\
| T. %s | | T. %s | | T. %s | | T. %s | | T. %s |\n\
| N. %s | | N. %s | | N. %s | | N. %s | | N. %s |\n\
+-------+ +-------+ +-------+ +-------+ +-------+\n", 
        normailizeNumbers[isOpen[0]], normailizeNumbers[isOpen[1]], normailizeNumbers[isOpen[2]], normailizeNumbers[isOpen[3]], normailizeNumbers[isOpen[4]],
        normailizeNumbers[cards[i+0]], normailizeNumbers[cards[i+1]], normailizeNumbers[cards[i+2]], normailizeNumbers[cards[i+3]], normailizeNumbers[cards[i+4]],
        normailizeNumbers[i], normailizeNumbers[i+1], normailizeNumbers[i+2], normailizeNumbers[i+3], normailizeNumbers[i+4]);
        }
        scanf("%d", &userInput);
        while (userInput < 0 || userInput >= length*2 || cardsStatus[userInput]) {
            printf("Unexpected number\n");
            scanf("%d", &userInput);
        }
        cardsStatus[userInput] = 1;
        countCards = 0;
        for (int i = 0; i < length*2; i++) {
            countCards += cardsStatus[i];
        }
        if (countCards == length*2) {
            system("clear");
            return 1;
        }
    }
    free(cards);
    free(cardsStatus);
    system("clear");
    return 0;
}