#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int x = 1;                       // player position (0 to 2)
    int step = 0;                    // obstacle vertical movement
    int obstaclePos = rand() % 3;    // obstacle lane
    int score = 0;                   // NEW
    int lives = 3;                   // NEW
    int speed = 120;                 // NEW (initial speed)

    while (1) {

        // ---- INPUT ----
        if (_kbhit()) {
            char ch = getch();

            if (ch == 75 && x > 0)        // LEFT arrow
                x--;

            if (ch == 77 && x < 2)        // RIGHT arrow
                x++;
        }

        // ---- DRAW ----
        system("cls");
        printf("Score: %d   Lives: %d\n", score, lives);   // NEW
        printf("|--- --- ---|\n");

        for (int i = 0; i < 10; i++) {
            if (i == step) {

                if (obstaclePos == 0)
                    printf("| %c        |\n", 1);

                else if (obstaclePos == 1)
                    printf("|     %c    |\n", 1);

                else if (obstaclePos == 2)
                    printf("|        %c |\n", 1);

            } else {
                printf("|           |\n");
            }
        }

        // ---- PLAYER ----
        if (x == 0)
            printf("| %c        |\n", 6);
        else if (x == 1)
            printf("|     %c    |\n", 6);
        else if (x == 2)
            printf("|        %c |\n", 6);

        // ---- COLLISION ----
        if (step == 10 && x == obstaclePos) {
            lives--;     // NEW

            if (lives == 0) {
            	system("cls");
            	printf("Score %d Lives: %d\n\n",score,lives);
                printf("\nGAME OVER!\n");
                Sleep(1200);
                break;   // end game only after all lives lost
            }

            // if still alive, reset obstacle only
            printf("\nYou were hit! Lives left: %d\n", lives);
            Sleep(800);
            step = 0;
            obstaclePos = rand() % 3;
        }

        Sleep(speed);        // NEW (speed-based sleep)

        // Move obstacle down
        step++;

        // Reset when reaches bottom
        if (step > 10) {
            step = 0;
            obstaclePos = rand() % 3; // new lane
            score++;                 // NEW

            // speed increases (sleep decreases)
            if (speed > 40)          // don't go too fast
                speed -= 5;          // NEW
        }
    }

    return 0;
}

