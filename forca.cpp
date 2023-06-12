#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>
#include <unistd.h>

using namespace std;

void clearScreen()
{
    system("clear");
}

string giveRandWord()
{
    string words[4] = {"pineapple", "florence", "strawberry", "computer"};
    int randIndex = rand() % 4;
    return words[randIndex];
}

void maskedWord(string word, int wordSize, string wordMask)
{
    clearScreen();
    cout << "\n\t---------------------------------------------------------\n";
    cout << "\t\t\t The word has " << wordSize << " letters\n";
    cout << "\t---------------------------------------------------------\n\n";
    int cont = 0;
    cout << "The word is: ";
    for (cont = 0; cont < wordSize; cont++)
    {
        cout << wordMask[cont];
    }
}

void showStatus(int life, string triedLetters, int correctLetters, int points)
{
    cout << "\n\n\n\t---------------------------------------------------------\n";
    cout << "\t\tPoints: " << points << "\n";
    cout << "\t\tYou have " << life << " more trys\n";
    cout << "\t\tYou have tried: " << triedLetters << "\n";
    cout << "\t\tYou got " << correctLetters << " letters right\n";

    cout << "\t---------------------------------------------------------\n\n";
}

void winScreen(string word, int points)
{
    clearScreen();
    cout << "\n\t---------------------------------------------------------\n";
    cout << "\t\t\tCongratulations, you got it :)\n";
    cout << "\t\t\tThe word was: " << word << "\n";
    cout << "\t\t\tYou got: " << points << " points\n";
    cout << "\t---------------------------------------------------------\n\n";
}

void defeatScreen(string word, int points)
{
    clearScreen();
    cout << "\n\t---------------------------------------------------------\n";
    cout << "\t\t\tBetter luck next time :(\n";
    cout << "\t\t\tThe word was: " << word << "\n";
    cout << "\t\t\tYou got: " << points << " points\n";
    cout << "\t---------------------------------------------------------\n\n";
}

void playAlone()
{
    clearScreen();

    string word = giveRandWord();
    string triedLetters;
    string playerBullseye;
    char letter;
    int wordSize = word.size();
    int life = 5;
    int cont = 0;
    int correctLetters = 0;
    int playerPoints = 0;

    for (cont = 0; cont < wordSize; cont++)
    {
        playerBullseye[cont] = '?';
    }

    while (life > 0 && correctLetters != wordSize)
    {
        maskedWord(word, wordSize, playerBullseye.data());
        showStatus(life, triedLetters, correctLetters, playerPoints);
        cout << "\nType a letter: ";
        cin >> letter;
        life--;
        bool found = triedLetters.find(letter);
        for (cont = 0; cont < wordSize; cont++)
        {
            if (word[cont] == letter && found != 0)
            {
                playerBullseye[cont] = letter;
                correctLetters++;
                life++;
                playerPoints += 2 * wordSize;
            }
        }
        triedLetters = triedLetters + letter;
    }

    if (wordSize == correctLetters)
    {
        winScreen(word, playerPoints);
    }

    if (life <= 0)
    {
        defeatScreen(word, playerPoints);
    }
}

void menu()
{
    clearScreen();
    int option = 0;
    int loaded = 0;
    cout << "\n\t---------------------------------------------------------\n";
    cout << "\t\t\t\t LOADING\n";
    cout << "\t---------------------------------------------------------\n\n";

    while (loaded < 80)
    {
        cout << "\u25B0";
        fflush(stdout);
        usleep(5000);
        loaded++;
    }

    clearScreen();

    while (option < 1 || option > 3)
    {
        cout << "\n\t---------------------------------------------------------\n";
        cout << "\t\t\t Welcome, let's play :)\n";
        cout << "\t---------------------------------------------------------\n\n";

        cout << "Welcome to the game";
        usleep(100000);
        cout << "\n1 - Play";
        usleep(100000);
        cout << "\n2 - About";
        usleep(100000);
        cout << "\n3 - Leave";
        usleep(100000);
        cout << "\nType your choice then press enter: ";
        cin >> option;
    }

    switch (option)
    {
    case 1:
        playAlone();
        break;
    case 2:
        cout << "What would you like to know";
        break;
    case 3:
        clearScreen();
        cout << "\n\t---------------------------------------------------------\n";
        cout << "\t\t\t\t See you later :)\n";
        cout << "\t---------------------------------------------------------\n\n";
        break;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    menu();
    return 0;
}
