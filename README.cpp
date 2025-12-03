##"#Modified game version of Lane Dodge Game"
#Requirements
Windows operating system 
C compiler that supports conio.h and windows.h 
Basic command‑line / terminal to compile and run the program 
#Game Logic
Three vertical lanes 
player stays at the bottom row.
An obstacle falls from the top in one of the lanes.
Use the Left Arrow key to move one lane to the left and the Right Arrow key to move one lane to the right.
If the obstacle and the player are in the same lane when the obstacle reaches the player’s row, there is collision detected and the live count decrease by 1
Else obstacle resets to the top in a new random lane , score count is increased by 1 and speed decreses by 5 hence maiking sleep time shorter 
#Features
#Libraries used
stdio.h	(Input/output)
conio.h	(Keyboard input)
windows. 
stdlib.h
time.h	
#Functions used
srand(time(0))	Sets a starting point for random numbers so they change every time you run the game.
rand() % 3	Chooses a random number between 0 and 2 to decide which lane the obstacle will appear in.
_kbhit()	Checks if a key is pressed on the keyboard.
getch()	Reads which key is pressed (used to move the player).
system("cls")	Clears the console screen to redraw the game, making movement visible.
printf()	Prints the player, obstacles, and game messages to the screen.
Sleep(120)	Pauses the game for 120 milliseconds so the blocks fall at a playable speed.
#Variables used
int x – Stores the current lane of the player (0 = left, 1 = middle, 2 = right).
int step – Stores the vertical row index of the falling obstacle, from top to bottom.
int obstaclePos – Stores which lane (0, 1 or 2) the current obstacle is falling in.
int score =0 initially before the game started the count is 0 
int lives =3 here in this game palyer has only 3 lives 
int speed =120 intial speed