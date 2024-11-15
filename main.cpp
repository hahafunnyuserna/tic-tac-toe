#include "battleGame.cpp"

void gameSelection()
{
    char menuInput;
    cout << "\nPlease select the option you want to play:\n[S] - Standard (Regular game, regular rules)\n[B] - Battle Toe (Play using archetypes with special abilities)\n";
    while ((!(cin >> menuInput)) || ((menuInput != 'S') && (menuInput != 's') && (menuInput != 'B') && (menuInput != 'b')))
    {
        cout << "ERROR: Please select a valid option.\n";
        cin.clear();
        cin.ignore(40, '\n');
    }

    if ((menuInput == 'S')|| (menuInput == 's'))
    {
        standardGame();
    }

    if ((menuInput == 'B')|| (menuInput == 'b'))
    {
        battleGame();
    }
}

bool repeatGame()
{
    char repeatInput;
    bool repeat;
    cout << "Do you want to play again? [Y/N]\n";
    while ((!(cin >> repeatInput)) || ((repeatInput != 'Y') && (repeatInput != 'y') && (repeatInput != 'N') && (repeatInput != 'n')))
    {
        cout << "ERROR: Please select a valid option.\n";
        cin.clear();
        cin.ignore(40, '\n');
    }

    if ((repeatInput == 'Y') || (repeatInput == 'y'))
    {
        repeat = true;
        cin.clear();
        cin.ignore(40, '\n');
    }
        if ((repeatInput == 'N') || (repeatInput == 'n'))
    {
        cout << "Goodbye.\n";
        repeat = false;
        cin.clear();
        cin.ignore(40, '\n');
    }

    return repeat;
}

int main(void) 
{ 
    bool repeat = true;
    cout << "Welcome!";
    while (true)
    {
        gameSelection();
        if (repeatGame() == false)
        {
            break;
        }
    }
    
}
