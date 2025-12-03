#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void shuffle(char *word, char *scrambled) {
    int len = strlen(word);
    strcpy(scrambled, word);

    for (int i = 0; i < len; i++) {
        int r = rand() % len;
        char temp = scrambled[i];
        scrambled[i] = scrambled[r];
        scrambled[r] = temp;
    }
}

int main() {
    char words[][20] = {"APPLE", "MANGO", "BANANA", "ORANGE", "GRAPES"};
    int totalWords = 5;

    char guess[20], scrambled[20];
    char playAgain;
    int index;

    do {
        system("cls"); // use "clear" on Linux/Mac
        srand(time(NULL));

        // pick random word
        index = rand() % totalWords;

        // scramble it
        shuffle(words[index], scrambled);

        printf("=======================================\n");
        printf("            WORD SCRAMBLE GAME\n");
        printf("=======================================\n");
        printf("Unscramble this word: %s\n", scrambled);
        printf("Your guess: ");
        scanf("%s", guess);

        // convert to uppercase
        for (int i = 0; guess[i]; i++) {
            if (guess[i] >= 'a' && guess[i] <= 'z')
                guess[i] -= 32;
        }

        if (strcmp(guess, words[index]) == 0) {
            printf("\n?? Correct! You unscrambled the word!\n");
        } else {
            printf("\n? Wrong! The correct word was: %s\n", words[index]);
        }

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThanks for playing!\n");
    return 0;
}
