#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

int compCards[52];
int plCards[52];
int compCardCount = 26;
int plCardCount = 26;

void shuffleCards(int arr[])
{
    srand(time(0));
    int arrIndex;
    int temp;
    for (int i = 0; i < 52; i++)
    {
        arrIndex = rand() % 52;
        temp = arr[arrIndex];
        arr[arrIndex] = arr[i];
        arr[i] = temp;
    }
}

void cardApply(int card[])
{
    for (int i = 0; i < 52; i++)
    {
        switch (card[i])
        {
        case 1: case 2: case 3: case 4: card[i] = 2; break;
        case 5: case 6: case 7: case 8: card[i] = 3; break;
        case 9: case 10: case 11: case 12: card[i] = 4; break;
        case 13: case 14: case 15: case 16: card[i] = 5; break;
        case 17: case 18: case 19: case 20: card[i] = 6; break;
        case 21: case 22: case 23: case 24: card[i] = 7; break;
        case 25: case 26: case 27: case 28: card[i] = 8; break;
        case 29: case 30: case 31: case 32: card[i] = 9; break;
        case 33: case 34: case 35: case 36: card[i] = 10; break;
        case 37: case 38: case 39: case 40: card[i] = 11; break;
        case 41: case 42: case 43: case 44: card[i] = 12; break;
        case 45: case 46: case 47: case 48: card[i] = 13; break;
        case 49: case 50: case 51: case 52: card[i] = 14; break;
        }
    }
}

void war()
{
    cout << setw(13) << "WAR" << endl;
    cout << setw(32) << "Computer's cards are: ";

    for (int i = 1; i < 4; i++)
    {
        cout << compCards[i] << " ";
    }

    cout << endl;
    cout << setw(30) << "Player's cards are: ";

    for (int i = 1; i < 4; i++)
    {
        cout << plCards[i] << " ";
    }

    cout << endl;

    if (compCards[3] > plCards[3])
    {
        cout << setw(23) << "Computer Won!" << endl << endl;
        compCardCount += 4;
        plCardCount -= 4;
        
        cout << setw(27) << "The computer has " << compCardCount << " cards" << endl;
        cout << setw(19) << " You have " << plCardCount << " cards" << endl << endl;
    }
    else if (compCards[3] < plCards[3])
    {
        cout << setw(21) << "Player Won!" << endl << endl;
        plCardCount += 4;
        compCardCount -= 4;

        cout << setw(27) << "The computer has " << compCardCount << " cards" << endl;
        cout << setw(19) << " You have " << plCardCount << " cards" << endl << endl;
    }
    else
    {
        cout << setw(15) << "Draw!" << endl << endl;
        compCards[compCardCount - 1] = compCards[0];
        plCards[plCardCount - 1] = plCards[0];

        cout << setw(27) << "The computer has " << compCardCount << " cards" << endl;
        cout << setw(19) << " You have " << plCardCount << " cards" << endl << endl;
    }
}

void warSign()
{
    cout << "\n  ///         ///        ///       ///         ///////////\n";
    cout << "   ///      /////      ///      /// ///       ///       ///\n";
    cout << "    ///   /// ///    ///      ///   ///      /// /// ///\n";
    cout << "     //////     //////      /// /// ///     ///    ///\n";
    cout << "      ///        ///      ///       ///    ///      ///\n\n\n";
}

void cardWar()
{
    int deck[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52 };

    shuffleCards(deck);
    cardApply(deck);

    for (int i = 0; i < 52; i++)
    {
        i < 26 ? compCards[i] = deck[i] : plCards[i - 26] = deck[i];
    }

    for (int i = 0; i < 13; i++)
    {
        warSign();

        cout << setw(30) << "RULES\n\n\n";
        cout << "1. At the start you and the computer have 26 cards.\n\n";
        cout << "2. The game lasts 13 rounds.\n\n";
        cout << "3. Every round you and the computer reveal your cards\n   and whoever's card is bigger takes both cards.\n\n";
        cout << "4. In case of equal card, the game starts a war,\n   and you and the computer reveal your net three\n   cards and whoever's last card is bigger takes\n   it's 4 cards and the opponents 4 cards.\n\n";
        cout << "5. In case last cards are also equal, no one\n   takes any cards and the game continues.\n   The final winner is the one with more cards.\n\n\n";

        cout << setw(45) << "!!! You just have to press Enter !!!\n\n\n";
        cout << "Round " << i + 1;
        i < 9 ? cout << "   " : cout << "  ";

        cout << "The computer's card is: ";

        switch (compCards[0])
        {
        case 11: cout << 'J' << endl; break;
        case 12: cout << 'Q' << endl; break;
        case 13: cout << 'K' << endl; break;
        case 14: cout << 'A' << endl; break;
        default: cout << compCards[0] << endl;
        }

        cout << setw(33) << "The players's card is: ";

        switch (plCards[0])
        {
        case 11: cout << 'J' << endl; break;
        case 12: cout << 'Q' << endl; break;
        case 13: cout << 'K' << endl; break;
        case 14: cout << 'A' << endl; break;
        default: cout << plCards[0] << endl;
        }

        if (compCards[0] > plCards[0])
        {
            cout << setw(27) << "The computer won!" << endl << endl;

            compCards[compCardCount - 1] = compCards[0];
            compCards[compCardCount] = plCards[0];

            compCardCount++;
            plCardCount--;

            cout << setw(27) << "The computer has " << compCardCount << " cards" << endl;
            cout << setw(19) << " You have " << plCardCount << " cards" << endl << endl;
            if (i + 1 >= 2)
            {
                cout << "\n\nPress Enter 2 times to continue";
            }
            else
            {
                cout << "\n\nPress Enter to continue";
            }
        }
        else if (compCards[0] < plCards[0])
        {
            cout << setw(25) << "The player won!" << endl << endl;

            plCards[plCardCount - 1] = compCards[0];
            plCards[plCardCount] = plCards[0];

            compCardCount--;
            plCardCount++;

            cout << setw(27) << "The computer has " << compCardCount << " cards" << endl;
            cout << setw(19) << "You have " << plCardCount << " cards" << endl << endl;
            if (i + 1 >= 2)
            {
                cout << "\n\nPress Enter 2 times to continue";
            }
            else
            {
                cout << "\n\nPress Enter to continue";
            }
        }
        else
        {
            war();
            if (i + 1 >= 2)
            {
                cout << "\n\nPress Enter 2 times to continue";
            }
            else
            {
                cout << "\n\nPress Enter to continue";
            }
        }

        for (int i = 0; i < compCardCount - 1; i++)
        {
            compCards[i] = compCards[i + 1];
        }
        for (int i = 0; i < plCardCount - 1; i++)
        {
            plCards[i] = plCards[i + 1];
        }

        cin.get();
        cin.ignore();

        if (i < 12) system("cls");
    }

    if (compCardCount > plCardCount)
    {
        cout << setw(40) << "THE COMPUTER IS THE BIG WINNER!\n\n";
        cout << setw(34) << "Press Enter 2 times to exit";

    }
    else if (compCardCount < plCardCount)
    {
        cout << setw(30) << "YOU ARE THE BIG WINNER!\n\n";
        cout << setw(32) << "Press Enter 2 times to exit";
    }
    else
    {
        cout << setw(27) << "The game is a tie\n\n";
        cout << setw(35) << "Press Enter 2 times to exit";
    }

    compCardCount = 26;
    plCardCount = 26;

    cin.get();
    cin.ignore();
}

char ticTacToeBoard[10] = { 'o','1','2','3','4','5','6','7','8','9' };

void TicTacToeDrawBoard()
{
    system("cls");

    cout << "\n  ///////////  ///     ///////      ///////////       ///         ///////      ///////////   //////      /////////\n";
    cout << "     ///      ///   ////               ///         /// ///    ////                ///     ///     ///   ///\n";
    cout << "    ///      ///  ///                 ///        ///   ///  ///                  ///    ///       ///  /////////\n";
    cout << "   ///      ///   ////               ///       /// /// ///  ////                ///      ///    ///   ///\n";
    cout << "  ///      ///      ///////         ///      ///       ///    ///////          ///        //////     /////////\n\n";
    cout << "       _____ _____ _____" << endl;
    cout << "      |     |     |     |" << "                                 RULES" << endl;
    cout << "      |  " << ticTacToeBoard[1] << "  |  " << ticTacToeBoard[2] << "  |  " << ticTacToeBoard[3] << "  |" << endl;
    cout << "      |_____|_____|_____|" << "       1. The game is played on a grid which is 3 squares by 3 squares." << endl;
    cout << "      |     |     |     |" << endl;
    cout << "      |  " << ticTacToeBoard[4] << "  |  " << ticTacToeBoard[5] << "  |  " << ticTacToeBoard[6] << "  |" << "       2. The first player to get 3 of their marks in a row (up, down" << endl;
    cout << "      |_____|_____|_____|" << "          across, or diagonally) is the winner." << endl;
    cout << "      |     |     |     |" << endl;
    cout << "      |  " << ticTacToeBoard[7] << "  |  " << ticTacToeBoard[8] << "  |  " << ticTacToeBoard[9] << "  |" << "       3. When all 9 squares are full (if the game hasn't finished)," << endl;
    cout << "      |_____|_____|_____|" << "          the game is a tie." << endl << endl << endl;
}

int checkTicTacToeWin()
{
    if (ticTacToeBoard[1] == ticTacToeBoard[2] && ticTacToeBoard[2] == ticTacToeBoard[3]) return 1;
    else if (ticTacToeBoard[4] == ticTacToeBoard[5] && ticTacToeBoard[5] == ticTacToeBoard[6]) return 1;
    else if (ticTacToeBoard[7] == ticTacToeBoard[8] && ticTacToeBoard[8] == ticTacToeBoard[9]) return 1;
    else if (ticTacToeBoard[1] == ticTacToeBoard[4] && ticTacToeBoard[4] == ticTacToeBoard[7]) return 1;
    else if (ticTacToeBoard[2] == ticTacToeBoard[5] && ticTacToeBoard[5] == ticTacToeBoard[8]) return 1;
    else if (ticTacToeBoard[3] == ticTacToeBoard[6] && ticTacToeBoard[6] == ticTacToeBoard[9]) return 1;
    else if (ticTacToeBoard[1] == ticTacToeBoard[5] && ticTacToeBoard[5] == ticTacToeBoard[9]) return 1;
    else if (ticTacToeBoard[3] == ticTacToeBoard[5] && ticTacToeBoard[5] == ticTacToeBoard[7]) return 1;
    else if (ticTacToeBoard[1] != '1' && ticTacToeBoard[2] != '2' && ticTacToeBoard[3] != '3'
        && ticTacToeBoard[4] != '4' && ticTacToeBoard[5] != '5' && ticTacToeBoard[6] != '6'
        && ticTacToeBoard[7] != '7' && ticTacToeBoard[8] != '8' && ticTacToeBoard[9] != '9') return 0;
    else return -1;
}

char computerChoice() {
    srand(time(NULL));

    char possibleChoice[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    int temp = rand() % 9;
    char compChoice = possibleChoice[temp];

    return compChoice;
}

void ticTacToeVsComp()
{
    int player = 1, winValue;
    char playerMark, numberChoice;

    do
    {
        TicTacToeDrawBoard();

        player = (player % 2) ? 1 : 2;

        if (player == 1)
        {
            cout << "  Enter a number: ";
            cin >> numberChoice;
        }
        else if (player == 2)
        {
            do
            {
                numberChoice = computerChoice();
            } while (ticTacToeBoard[(int)numberChoice] == numberChoice);
        }

        playerMark = (player == 1) ? 'X' : 'O';

        if (numberChoice == '1' && ticTacToeBoard[1] == '1') ticTacToeBoard[1] = playerMark;
        else if (numberChoice == '2' && ticTacToeBoard[2] == '2') ticTacToeBoard[2] = playerMark;
        else if (numberChoice == '3' && ticTacToeBoard[3] == '3') ticTacToeBoard[3] = playerMark;
        else if (numberChoice == '4' && ticTacToeBoard[4] == '4') ticTacToeBoard[4] = playerMark;
        else if (numberChoice == '5' && ticTacToeBoard[5] == '5') ticTacToeBoard[5] = playerMark;
        else if (numberChoice == '6' && ticTacToeBoard[6] == '6') ticTacToeBoard[6] = playerMark;
        else if (numberChoice == '7' && ticTacToeBoard[7] == '7') ticTacToeBoard[7] = playerMark;
        else if (numberChoice == '8' && ticTacToeBoard[8] == '8') ticTacToeBoard[8] = playerMark;
        else if (numberChoice == '9' && ticTacToeBoard[9] == '9') ticTacToeBoard[9] = playerMark;
        else
        {
            cout << "  Invalid move ";
            player--;

            cin.get();
            cin.ignore();
        }

        winValue = checkTicTacToeWin();
        player++;
    } while (winValue == -1);

    TicTacToeDrawBoard();

    if (winValue == 1)
    {
        (player == 2) ? cout << "-->      You win!" : cout << "-->      Computer wins!";
    }
    else cout << "-->           Tie";

    ticTacToeBoard[0] = 'o';
    ticTacToeBoard[1] = '1';
    ticTacToeBoard[2] = '2';
    ticTacToeBoard[3] = '3';
    ticTacToeBoard[4] = '4';
    ticTacToeBoard[5] = '5';
    ticTacToeBoard[6] = '6';
    ticTacToeBoard[7] = '7';
    ticTacToeBoard[8] = '8';
    ticTacToeBoard[9] = '9';

    cin.ignore();
    cin.get();
}

void ticTacToeVsPl()
{
    int player = 1, winValue;
    char playerMark, numberChoice;
    do
    {
        TicTacToeDrawBoard();
        player = (player % 2) ? 1 : 2;
        cout << "  Player " << player << ": ";
        cin >> numberChoice;
        playerMark = (player == 1) ? 'X' : 'O';
        if (numberChoice == '1' && ticTacToeBoard[1] == '1') ticTacToeBoard[1] = playerMark;
        else if (numberChoice == '2' && ticTacToeBoard[2] == '2') ticTacToeBoard[2] = playerMark;
        else if (numberChoice == '3' && ticTacToeBoard[3] == '3') ticTacToeBoard[3] = playerMark;
        else if (numberChoice == '4' && ticTacToeBoard[4] == '4') ticTacToeBoard[4] = playerMark;
        else if (numberChoice == '5' && ticTacToeBoard[5] == '5') ticTacToeBoard[5] = playerMark;
        else if (numberChoice == '6' && ticTacToeBoard[6] == '6') ticTacToeBoard[6] = playerMark;
        else if (numberChoice == '7' && ticTacToeBoard[7] == '7') ticTacToeBoard[7] = playerMark;
        else if (numberChoice == '8' && ticTacToeBoard[8] == '8') ticTacToeBoard[8] = playerMark;
        else if (numberChoice == '9' && ticTacToeBoard[9] == '9') ticTacToeBoard[9] = playerMark;
        else
        {
            cout << "  Invalid move ";
            player--;
            cin.get();
            cin.ignore();
        }
        winValue = checkTicTacToeWin();
        player++;
    } while (winValue == -1);

    TicTacToeDrawBoard();

    if (winValue == 1)
    {
        (player == 2) ? cout << "-->      You win!" : cout << "-->      Computer wins!";
    }
    else
    {
        cout << "-->           Tie";
    }

    cin.get();
    cin.ignore();

    ticTacToeBoard[0] = 'o';
    ticTacToeBoard[1] = '1';
    ticTacToeBoard[2] = '2';
    ticTacToeBoard[3] = '3';
    ticTacToeBoard[4] = '4';
    ticTacToeBoard[5] = '5';
    ticTacToeBoard[6] = '6';
    ticTacToeBoard[7] = '7';
    ticTacToeBoard[8] = '8';
    ticTacToeBoard[9] = '9';
}

int mathGame() {
    char plChoice;

    cout << "\n      /////         /////   ///////////   /////       ///   ///       ///\n";
    cout << "     /// ///     /// ///   ///           /// ///     ///   ///       ///\n";
    cout << "    ///  ///   ///  ///   ///////////   ///   ///   ///   ///       ///\n";
    cout << "   ///   /// ///   ///   ///           ///     /// ///   ///       ///\n";
    cout << "  ///    ////     ///   ///////////   ///       /////   /////////////\n\n";
    cout << setw(47) << "Choose an option\n\n\n";
    cout << setw(34) << "(1) Tic Tac Toe (vs Computer)" << setw(38) << "(2) Tic Tac Toe(vs Other Player)\n\n";
    cout << setw(34) << "(3) Card War" << setw(13) << "(4) Quit\n";

    while (true)
    {
        cin >> plChoice;
        system("cls");

        if (plChoice == '1') ticTacToeVsComp();
        else if (plChoice == '2') ticTacToeVsPl();
        else if (plChoice == '3') cardWar();
        else if (plChoice == '4') return 0;
        else
        {
            cout << "Invalid choice ";
            cin.get();
            cin.ignore();
        }

        system("cls");

        cout << "\n      /////         /////   ///////////   /////       ///   ///       ///\n";
        cout << "     /// ///     /// ///   ///           /// ///     ///   ///       ///\n";
        cout << "    ///  ///   ///  ///   ///////////   ///   ///   ///   ///       ///\n";
        cout << "   ///   /// ///   ///   ///           ///     /// ///   ///       ///\n";
        cout << "  ///    ////     ///   ///////////   ///       /////   /////////////\n\n";
        cout << setw(49) << "Choose a new option\n\n\n";
        cout << setw(34) << "(1) Tic Tac Toe (vs Computer)" << setw(38) << "(2) Tic Tac Toe(vs Other Player)\n\n";
        cout << setw(34) << "(3) Card War" << setw(13) << "(4) Quit\n";
    }
}

int main()
{
    mathGame();
}