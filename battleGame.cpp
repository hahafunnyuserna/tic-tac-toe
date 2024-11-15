#include "regularGame.cpp"

bool checkSwarmWin(char board[3][3], char player) 
{ 
	for (int i = 0; i < 3; i++)
    { 
		if ((board[i][0] == player) && (board[i][1] == player) 
			&& (board[i][2] == player))
        {
            return true;
        }

		if ((board[0][i] == player) && (board[1][i] == player)
			&& (board[2][i] == player))
        {
            return true;
        }
	} 

	if ((board[0][0] == player) && (board[1][1] == player) 
		&& (board[2][2] == player))
        {
            return true;
        }

	if ((board[0][2] == player) && (board[1][1] == player) 
		&& (board[2][0] == player))
    {
        return true;
    }

    if ((board[0][0] == player) && (board[0][2] == player) 
		&& (board[2][0] == player) && (board[2][2] == player))
    {
        return true;
    }
	return false; 
}

void battleGame()
{
    char archetypeOne;
    char archetypeTwo;
    int pyroActOne = 1;
    int pyroActTwo = 1;

    cout << "\n\n\n\n\n\n\n\n\nAvailable archetypes:\n[N] - Norm Jr. (The boring option)\n[P] - Pyromancer (Wipe out the entire board once per game)\n[S] - Swarm (Can win by filling in the corners of the board)\n";

    cout << "Please enter the archetype for player 1:\n";
    while ((!(cin >> archetypeOne)) || ((archetypeOne != 'N') && (archetypeOne != 'n') && (archetypeOne != 'P') && (archetypeOne != 'p') && (archetypeOne != 'S') && (archetypeOne != 's')))
    {
        cout << "ERROR: Please select a valid option.\n";
        cin.clear();
        cin.ignore(40, '\n');
    }
    if ((archetypeOne == 'N') || (archetypeOne == 'n'))
    {
        cout << "Archetype: Norm Jr.\n";
    }
    if ((archetypeOne == 'P') || (archetypeOne == 'p'))
    {
        cout << "Archetype: Pyromancer\n";
    }
    if ((archetypeOne == 'S') || (archetypeOne == 's'))
    {
        cout << "Archetype: Swarm\n";
    }

    cout << "Please enter the archetype for player 2:\n";
    while ((!(cin >> archetypeTwo)) || ((archetypeTwo != 'N') && (archetypeTwo != 'n') && (archetypeTwo != 'P') && (archetypeTwo != 'p') && (archetypeTwo != 'S') && (archetypeTwo != 's')))
    {
        cout << "ERROR: Please select a valid option.\n";
        cin.clear();
        cin.ignore(40, '\n');
    }
    if ((archetypeTwo == 'N') || (archetypeTwo == 'n'))
    {
        cout << "Archetype: Norm Jr.\n";
    }
    if ((archetypeTwo == 'P') || (archetypeTwo == 'p'))
    {
        cout << "Archetype: Pyromancer\n";
    }
    if ((archetypeTwo == 'S') || (archetypeTwo == 's'))
    {
        cout << "Archetype: Swarm\n";
    }


    cout << "Please input the character for player 1:\n";
    string playerOne;
    cin >> playerOne;
    if (playerOne.length() != 1)
    {
        while (true)
        {
            cout << "ERROR: Invalid length.\nPlease input the character for player 1:\n";
            cin >> playerOne;
            if (playerOne.length() == 1)
            {
                break;
            }
        }
    }
    
    cout << "Please input the character for player 2:\n";
    string playerTwo;
    cin >> playerTwo;
    if ((playerTwo.length() != 1) || (playerTwo == playerOne))
    {
        while (true)
        {
            if (playerTwo.length() != 1)
            {
                cout << "ERROR: Invalid length.\nPlease input the character for player 2:\n";
            } else if (playerTwo == playerOne)
            {
                cout << "ERROR: Marker is identical to player 1.\nPlease input the character for player 2:\n";
            }
            
            cin >> playerTwo;
            if ((playerTwo.length() == 1) && (playerTwo != playerOne))
            {
                break;
            }
        }
    }

    char board[3][3] = { { ' ', ' ', ' ' }, 
                        { ' ', ' ', ' ' }, 
                            { ' ', ' ', ' ' } }; 
    char player = playerOne[0];
    char archetype = archetypeOne;
    int pyroAct = pyroActOne;
    int row, col; 
    int turn;
    
    for (turn = 0; turn < 9; turn++)
    { 
        createBoard(board); 

        while (true)
        { 
            if (((archetype == 'P') || (archetype == 'p')) && (pyroAct == 1))
            {
                char actionChar;
                cout << "Player " << player << ", please select your action:\n[N]: Normal move\n[S]: Special ability\n";
                while ((!(cin >> actionChar)) || ((actionChar != 'N') && (actionChar != 'n') && (actionChar != 'S') && (actionChar != 's')))
                {
                    cout << "ERROR: Please select a valid option.\n";
                    cin.clear();
                    cin.ignore(40, '\n');
                }

                if ((actionChar == 'S') || (actionChar == 's'))
                {
                    cout << "Player " << player << " used Meteor!";
                    
                    board[0][0] = ' ';
                    board[1][0] = ' ';
                    board[2][0] = ' ';
                    board[0][1] = ' ';
                    board[1][1] = ' ';
                    board[2][1] = ' ';
                    board[0][2] = ' ';
                    board[1][2] = ' ';
                    board[2][2] = ' ';
                    
                    createBoard(board);
                    cout << "It's super effective!\n";
                    pyroAct--;
                }
            }
            
            cout << "Player " << player << ", enter a row (0-2) and column (0-2) to play:\n"; 

            while (!(cin >> row))
            {
                cout << "ERROR: Invalid move. Try again.\nPlayer " << player << ", enter a row (0-2) and column (0-2) to play:\n"; 
                cin.clear();
                cin.ignore(40, '\n');
                    
            }

            while (!(cin >> col))
            {
                cout << "ERROR: Invalid move. Try again.\nPlayer " << player << ", enter row (0-2) and column (0-2):\n"; 
                cin.clear();
                cin.ignore(40, '\n');
            }

            if (((row < 0) || (row > 2) || (col < 0) || (col > 2)))
            {
                cout << "ERROR: Invalid move. Try again.\n";
            } else if (board[row][col] != ' ') { 
                cout <<  "This space is already filled. Try again.\n";
            } else { 
                break;
            } 
        } 

        board[row][col] = player; 

        if ((archetype == 'S') || (archetype == 's'))
        {
            if (checkSwarmWin(board, player))
            {
                createBoard(board); 
                cout << "\n\nPlayer " << player << " wins!"; 
                break; 
            }
        }

        if (checkWin(board, player))
        { 
            createBoard(board); 
            cout << "\n\nPlayer " << player << " wins!"; 
            break; 
        } 

        player = (player == playerOne[0]) ? playerTwo[0] : playerOne[0]; 
        archetype = (archetype == archetypeOne) ? archetypeTwo : archetypeOne;
        pyroAct = (pyroAct == pyroActOne) ? pyroActTwo : pyroActOne ; 
    } 

    createBoard(board); 

    if (turn == 9 && !checkWin(board, playerOne[0]) && (!checkWin(board, playerTwo[0])))
    { 
        cout << "It's a draw!\n"; 
    } 
}