#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void clearScreen()
{
    system("clear");
}

void menu()
{
    int option = 0;

    while (option < 1 || option > 3)
    {
        clearScreen();
        cout << "Welcome to the game";
        cout << "\n1 - Play";
        cout << "\n2 - About";
        cout << "\n3 - Leave";
        cout << "\nType your choice then press enter: ";

        cin >> option;
    }

    switch (option)
    {
    case 1:
        cout << "The game has began";
        break;
    case 2:
        cout << "What would you like to know";
        break;
    case 3:
        cout << "See ya bitch";
        break;
    }
}

int main()
{
    menu();
    return 0;
}
