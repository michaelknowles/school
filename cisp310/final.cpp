
#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
using namespace std;

// Function Definitions 
void draw();                // Draws the gameboard
char getMove();                // Get the get key pressed move input
void move(char);            // Moves player charecter based on the input
void check4Event();            // checks to see if player landed on chest
void updateChestLocation(); // Sets a new locatino for the chest
void loseHealth(int);        // Subtracts health from the player
void gainHealth(int);        // adds health from the player
bool checkDeath();            // checks to see if the player still has any health

int randRange(int, int);    // finds a random number in a range

void chestFound();            // looks to see if a chest is found
void getRandomEvent();        // Randomly chooses an event
void eventFairy();            // Shows the fairy event
void eventSpider();            // showes the spider event

void gameover();            // shows game over screen


                            // The main map board
char map[26][22] = {
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '\n' },
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '\n' } };


// Global variables
int playerX = 2, playerY = 2,    // Initializing player starting point 
chestX, chestY;            // Chest points variables 

char player = 204, chest = 'O',  // Declaring the ASCII art of the player and chests
health = 10; // setting the health of the player

int main()
{

    char input = '1';            // just a variable to hold the move inputs 
                                // the '1' is just a placehold input

    updateChestLocation();        // sets the starting point of the chest


                                // the main game loop
                                // will loop until the player has no health
    while (true)
    {

        check4Event();            // first checks to see if there are any active events
        draw();                    // then draws the new state of the board

        if (checkDeath())        // checks to see if the player still is alive
            exit(0);                // if not then it breaks out of the main loop

        input = getMove();        // then gets the next move
        move(input);            // then updates player location
    }

    return 0;                    // end of main
}


// draws the board
void draw() {

    system("CLS");    // clears the console
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // gets the info to change the color of font


                                                       // nested loop that lops through the 2d Array of the board
    for (int i = 0; i < 26; i++) {

        for (int j = 0; j < 22; j++) {

            if (i == playerX && j == playerY) {            // checks to see if the player is at the current location that it is drawing
                SetConsoleTextAttribute(hConsole, 9);    // if it is it changes the font color 
                printf(" %c", player);                    // draws the player
                SetConsoleTextAttribute(hConsole, 15);    // then changes the font color back
            }
            else if (i == chestX && j == chestY) {        // checks to see if the ches is there
                SetConsoleTextAttribute(hConsole, 14);  // font color change
                printf(" %c", chest);                    // draws chest
                SetConsoleTextAttribute(hConsole, 15);    // change color back
            }
            else {
                printf(" %c", map[i][j]);                // else it prints the map normally 
            }

        }

    }

}

// updated the X and Y locations of the player
void move(char input) {
    _asm
    { 
        lea ecx, input
        mov eax, 100
        cmp [ecx], eax
        jne elseA
        cmp playerY, 19
        jge elseCant
        add playerY, 1
        jmp doneMove //or return when it becomes procedure or whatever

        elseA:
                mov eax, 97
                cmp [ecx], eax
                jne elseW
                cmp playerY, 1
                jle elseCant
                sub playerY, 1
                jmp doneMove //or return if it becomes a procedure

        elseW:
                mov eax, 119
                cmp [ecx], eax
                jne elseS
                cmp playerX, 1
                jle elseCant
                sub playerX, 1
                jmp doneMove //or return if it becomes a procedure

        elseS:
                mov eax, 115
                cmp [ecx], eax
                jne elseCant
                cmp playerX, 24
                jge elseCant
                add playerX, 1
                jmp doneMove

    elseCant:
                
    doneMove: 
            
    }
};


// checks to see if player has landed on a chest
void check4Event()
{
    _asm
    {
        mov eax, playerX
        mov ebx, chestX
        cmp eax, ebx
        jne notEqual
        mov ecx, playerY
        mov edx, chestY
        cmp ecx, edx
        je    isEqual
        jne notEqual
    isEqual:
        call chestFound
        call updateChestLocation
    notEqual:

    }
}

// function to look for key presses
char getMove() {
    char input = '1';
    input = _getche();        // when a player presses a key it is saved
    return input;            // and is return the key press
}

// updates chest with a new random location 
void updateChestLocation() {
    srand(time(NULL));            // seeds the random number genorator to make sure the number is as random as can be
    chestX = randRange(1, 23);    // sets X withen the bounds of X
    chestY = randRange(1, 20);    // sets Y withen the bounds of Y
};

// fins a random number in a range of numbers
int randRange(int low, int high)
{
    return rand() % (high - low) + low;
}

// subtracts health by whatever the amount that is passed to the function 
void loseHealth(int loss)
{
    _asm
    {
        lea ecx, health
        mov ebx, loss
         sub [ecx], ebx
        mov al, [ecx]
        mov health, al
    }
}

// adds health by whatever the amount that is passed to the function 
void gainHealth(int gain) 
{
    _asm
    {
        lea ecx, health
        mov ebx, gain
        add [ecx], ebx
        mov al, [ecx]
        mov health, al
    }
}
int answer = 0;
// checks to see if player still has health
bool checkDeath()
{
    _asm
    {
        lea eax, health
        mov ebx, 0
        cmp [eax], ebx
        jg    elseFalse
        call gameover
        mov answer, 1
        jmp doneMove
    elseFalse:
            mov answer, 0 

    doneMove:

    }

    return answer;
}

// displays the chest found screen
void chestFound() {
    system("CLS");        // clears console 
    cout << "You found a chest!" << endl    // outputs chest
        << R"(
*******************************************************************************
          |                   |                  |                     |
 _________|________________.=""_;=.______________|_____________________|_______
|                   |  ,-"_,=""     `"=.|                  |
|___________________|__"=._o`"-._        `"=.______________|___________________
          |                `"=._o`"=._      _`"=._                     |
 _________|_____________________:=._o "=._."_.-="'"=.__________________|_______
|                   |    __.--" , ; `"=._o." ,-"""-._ ".   |
|___________________|_._"  ,. .` ` `` ,  `"-._"-._   ". '__|___________________
          |           |o`"=._` , "` `; .". ,  "-._"-._; ;              |
 _________|___________| ;`-.o`"=._; ." ` '`."\` . "-._ /_______________|_______
|                   | |o;    `"-.o`"=._``  '` " ,__.--o;   |
|___________________|_| ;     (#) `-.o `"=.`_.--"_o.-; ;___|___________________
____/______/______/___|o;._    "      `".o|o_.--"    ;o;____/______/______/____
/______/______/______/_"=._o--._        ; | ;        ; ;/______/______/______/_
____/______/______/______/__"=._o--._   ;o|o;     _._;o;____/______/______/____
/______/______/______/______/____"=._o._; | ;_.--"o.--"_/______/______/______/_
____/______/______/______/______/_____"=.o|o_.--""___/______/______/______/____
/______/______/______/______/______/______/______/______/______/______/_______/
*******************************************************************************
        )" << endl << endl;

    system("PAUSE");
    getRandomEvent();
}

// randomly chooses an event
void getRandomEvent() {

    if ((rand() % 3) == 2) {
        eventFairy();        // it has a 1 in 3 chance to be a fairy
    }
    else {
        eventSpider();
    }

};


// displayes the spider event
void eventSpider() {
    system("CLS");        // clears console
    loseHealth(10);        // subtracts 10 health
    cout << "It was a TRAP!!!!!" << endl  // displayes Spider event
        << "You have been ATTACKED!" << endl
        << "You lose 10 HP!" << endl
        << R"(
================================
        /\  .-"""-.  /\
       //\\/  ,,,  \//\\
       |/\| ,;;;;;, |/\|
       //\\\;-"""-;///\\
      //  \/   .   \/  \\
     (| ,-_| \ | / |_-, |)
       //`__\.-.-./__`\\
      // /.-(() ())-.\ \\
     (\ |)   '---'   (| /)
      ` (|           |) `
        \)           (/
================================
        )" << endl << endl;

    system("PAUSE");
}

// displays fairy event
void eventFairy() {
    system("CLS");
    gainHealth(10);        //adds 10 health to the player
    cout << "You found a Magical Fairy that healed you 10 HP!" << endl
        << R"(
======================================
 __       __          .--.
(  ""--__(  ""-_    ,' .-.\        *
 "-_ __  ""--__ "-_(  (^_^))      /
    (  """--___""--__" )-'(      /
     "-__      ""---/ ,(., )__o-/,  
         """----___(.'.   /--"--'
                   ("-_"/(    /
                    \   \ \
                     `.  \ |
                       \  \/
                       ||  \
                     ,-'/`. \
                     ) /   ) \  
                     |/    `-.\
                              `\
======================================
        )" << endl << endl;

    system("PAUSE");
}

// displays game over event
void gameover() {

    system("CLS");
    cout << "You have lost all health!" << endl
        << R"(
********************************************************************************
     (  ____ \  ___  )       )  ____ \  (  ___  )\     /|  ____ \  ____ ) )
     | (    \/ (   ) | () () | (    \/  | (   ) | )   ( | (    \/ (    )| |
     | |     | (___) | || || | (__      | |   | | |   | | (__   | (____)| |
     | | ____|  ___  | |(_)| |  __)     | |   | | (   ) )  __)  |     __) |
     | | \_  ) (   ) | |   | | (        | |   | |\ \_/ /| (     | (\ (  (_)
     | (___) | )   ( | )   ( | (____/\  | (___) | \   / | (____/\ ) \ \___ 
     (_______)/     \|/     \|_______/  (_______)  \_/  (_______//   \__/_)
********************************************************************************
        )" << endl;

    system("PAUSE");
}
//FinalProjectWip.cpp
//Displaying FinalProjectWip.cpp.

