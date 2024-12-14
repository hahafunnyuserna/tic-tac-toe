#include "battleGame.cpp"
#include <fstream>

void gameSelection(int &one, int &two, int &draw)
{
    char menuInput;
    cout << "\nPlease select the option you want to play:\n[S] - Standard (Regular game, regular rules)\n[B] - Battle Toe (Play using archetypes with special abilities)\n";
    while ((!(cin >> menuInput)) || ((menuInput != 'S') && (menuInput != 's') && (menuInput != 'B') && (menuInput != 'b')))
    {
        cout << "ERROR: Please select a valid option.\n";
        cin.clear();
        cin.ignore(40, '\n');
    }

    if ((menuInput == 'S') || (menuInput == 's'))
    {
        standardGame(one, two, draw);
    }

    if ((menuInput == 'B') || (menuInput == 'b'))
    {
        battleGame(one, two, draw);
    }
}

bool repeatGame(int &one, int &two, int &draw)
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
    int oneVal = 0;
    int twoVal = 0;
    int drawVal = 0;

    bool repeat = true;
    cout << "Welcome!";
    while (true)
    {
    
        gameSelection(oneVal, twoVal, drawVal);
        if (repeatGame(oneVal, twoVal, drawVal) == false)
        {
            ofstream outfile ("gameReport.txt");
            outfile << "Total Games Played: " << (oneVal + twoVal + drawVal) << "\n\nPlayer 1 Wins: " << oneVal << "\nPlayer 2 Wins: " << twoVal << "\nDraws: " << drawVal;
            break;
        }
    }
    
}
