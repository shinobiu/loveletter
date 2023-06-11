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

string maskedWord(string word, int wordSize)
{
    int cont = 0;

    string maskedWord;

    cout << "The word is: ";

    while (cont < wordSize)
    {
        usleep(30000);
        cout << " _ ";
        fflush(stdout);
        cont++;
    }

    return maskedWord;
}

void showStatus(int life, string triedLetters)
{
    cout << "\n\n\n\t---------------------------------------------------------\n";
    cout << "\t\tYou have " << life << " more trys\n";
    cout << "\t\tYou have tried: " << triedLetters << " those letters\n";
    cout << "\t---------------------------------------------------------\n\n";
}

void playAlone()
{
    clearScreen();

    string word = giveRandWord();
    char letter;
    string triedLetters;

    int wordSize = word.size();

    int life = 5;

    while (life > 0)
    {
        cout << "\n\t---------------------------------------------------------\n";
        cout << "\t\t\t\t Good Luck :)\n";
        cout << "\t---------------------------------------------------------\n\n";
        maskedWord(word, wordSize);
        showStatus(life, triedLetters);
        cout << "\nType a letter: ";
        cin >> letter;
        triedLetters = triedLetters + letter + " ";
        life--;
        clearScreen();
    }

    if (life == 0)
    {
        cout << "\n\t---------------------------------------------------------\n";
        cout << "\t\t\tBetter luck next time :)\n";
        cout << "\t\t\tThe word was: " << word << "\n";
        cout << "\t---------------------------------------------------------\n\n";
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
