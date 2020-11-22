#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

char square[10] = { 'o','1','2','3','4','5','6','7','8','9' };
int compCards[52];
int plCards[52];
int compCardCount = 26;
int plCardCount = 26;

void shuffle(int arr[]) {
    srand(time(NULL));
    int n;
    int temp;
    for (int i = 0; i < 52; i++) {
        n = rand() % 52;
        temp = arr[n];
        arr[n] = arr[i];
        arr[i] = temp;
    }
}

void show(int arr[]) {
    for (int i = 0; i < 52; i++) {
        switch (arr[i]) {
        case 1: case 2: case 3: case 4: arr[i] = 2; break;
        case 5: case 6: case 7: case 8: arr[i] = 3; break;
        case 9: case 10: case 11: case 12: arr[i] = 4; break;
        case 13: case 14: case 15: case 16: arr[i] = 5; break;
        case 17: case 18: case 19: case 20: arr[i] = 6; break;
        case 21: case 22: case 23: case 24: arr[i] = 7; break;
        case 25: case 26: case 27: case 28: arr[i] = 8; break;
        case 29: case 30: case 31: case 32: arr[i] = 9; break;
        case 33: case 34: case 35: case 36: arr[i] = 10; break;
        case 37: case 38: case 39: case 40: arr[i] = 11; break;
        case 41: case 42: case 43: case 44: arr[i] = 12; break;
        case 45: case 46: case 47: case 48: arr[i] = 13; break;
        case 49: case 50: case 51: case 52: arr[i] = 14; break;
        }
    }
}

void war() {
    cout << "WAR" << endl;
    cout << "Computer's cards are: ";
    for (int i = 1; i < 4; i++) {
        cout << compCards[i] << " ";
    }
    cout << endl;
    cout << "Player's cards are: ";
    for (int i = 1; i < 4; i++) {
        cout << plCards[i] << " ";
    }
    if (compCards[3] > plCards[3]) {
        cout << "Computer Won";
        compCardCount += 4;
        plCardCount -= 4;
    }
}

void cardWar() {
    int deck[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
                14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
                27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
                40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52 };

    shuffle(deck);
    show(deck);

    cout << "  ///         ///        ///       ///         ///////////\n";
    cout << "   ///      /////      ///      /// ///       ///       ///\n";
    cout << "    ///   /// ///    ///      ///   ///      /// /// ///\n";
    cout << "     //////     //////      /// /// ///     ///    ///\n";
    cout << "      ///        ///      ///       ///    ///      ///\n\n";


    for (int i = 0; i < 52; i++) {
        i < 26 ? compCards[i] = deck[i] : plCards[i - 26] = deck[i];
    }

    do {
        cout << "The computer's card is: " << compCards[0] << endl;
        cout << "The players's card is: " << plCards[0] << endl;
        if (compCards[0] > plCards[0]) {
            cout << "The computer won!" << endl << endl;
            compCardCount++;
            plCardCount--;
            compCards[compCardCount - 1] = plCards[0];
            compCards[compCardCount - 2] = compCards[0];
        }
        else if (compCards[0] < plCards[0]) {
            cout << "The player won!" << endl << endl;
            plCardCount++;
            compCardCount--;
            plCards[compCardCount - 1] = compCards[0];
            plCards[plCardCount - 2] = plCards[0];
        }
        else {
            war();
        }
        for (int i = 0; i < compCardCount - 3; i++) {
            compCards[i] = compCards[i + 1];
        }
        for (int i = 0; i < plCardCount - 3; i++) {
            plCards[i] = plCards[i + 1];
        }

        cin.get();
        cin.ignore();
    } while (compCardCount != 0 && plCardCount != 0);
    compCardCount == 0 ? cout << "Player is the big winner" << endl : cout << "Computer is the big winner" << endl;
}

void board()
{
    system("cls");

    cout << "  ///////////  ///     ///////      ///////////       ///         ///////      ///////////   //////      /////////\n";
    cout << "     ///      ///   ////               ///         /// ///    ////                ///     ///     ///   ///\n";
    cout << "    ///      ///  ///                 ///        ///   ///  ///                  ///    ///       ///  /////////\n";
    cout << "   ///      ///   ////               ///       /// /// ///  ////                ///      ///    ///   ///\n";
    cout << "  ///      ///      ///////         ///      ///       ///    ///////          ///        //////     /////////\n\n";

    cout << "  Player 1 (X) - Player 2 (O)" << endl;

    cout << "       _____ _____ _____" << endl;
    cout << "      |     |     |     |" << endl;
    cout << "      |  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << "  |" << endl;
    cout << "      |_____|_____|_____|" << endl;
    cout << "      |     |     |     |" << endl;
    cout << "      |  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << "  |" << endl;
    cout << "      |_____|_____|_____|" << endl;
    cout << "      |     |     |     |" << endl;
    cout << "      |  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << "  |" << endl;
    cout << "      |_____|_____|_____|" << endl << endl;
}

int checkWin()
{
    if (square[1] == square[2] && square[2] == square[3]) return 1;
    else if (square[4] == square[5] && square[5] == square[6]) return 1;
    else if (square[7] == square[8] && square[8] == square[9]) return 1;
    else if (square[1] == square[4] && square[4] == square[7]) return 1;
    else if (square[2] == square[5] && square[5] == square[8]) return 1;
    else if (square[3] == square[6] && square[6] == square[9]) return 1;
    else if (square[1] == square[5] && square[5] == square[9]) return 1;
    else if (square[3] == square[5] && square[5] == square[7]) return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
          && square[4] != '4' && square[5] != '5' && square[6] != '6'
          && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else return -1;
}

void ticTacToe() {
    int player = 1, choice, returnValue;
    char mark;

    do
    {
        board();

        player = (player % 2) ? 1 : 2;
        cout << "  Player " << player << ": ";

        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1') square[1] = mark;
        else if (choice == 2 && square[2] == '2') square[2] = mark;
        else if (choice == 3 && square[3] == '3') square[3] = mark;
        else if (choice == 4 && square[4] == '4') square[4] = mark;
        else if (choice == 5 && square[5] == '5') square[5] = mark;
        else if (choice == 6 && square[6] == '6') square[6] = mark;
        else if (choice == 7 && square[7] == '7') square[7] = mark;
        else if (choice == 8 && square[8] == '8') square[8] = mark;
        else if (choice == 9 && square[9] == '9') square[9] = mark;
        else
        {
            cout << "  Invalid move ";

            player--;

            cin.get();
            cin.ignore();
        }

        returnValue = checkWin();

        player++;

    } while (returnValue == -1);

    board();

    if (returnValue == 1) cout << "-->      Player " << --player << " win! ";
    else cout << "-->        Game draw";

    cin.ignore();
    cin.get();
}

int main()
{
    int choice;
    cin >> choice;
    if (choice == 1) ticTacToe();
    else if (choice == 2) cardWar();
}