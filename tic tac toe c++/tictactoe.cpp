#include <iostream>
#include <string>
#include <vector>
using namespace std;

int check_board(vector <int> board) {
    if (board[0]==board[1]&&board[1]==board[2]) {
        return board[0];
    } else if (board[3]==board[4]&&board[4]==board[5]) {
        return board[3];
    } else if (board[6]==board[7]&&board[7]==board[8]) {
        return board[6];
    } else if (board[0]==board[3]&&board[3]==board[6]) {
        return board[0];
    } else if (board[1]==board[4]&&board[4]==board[7]) {
        return board[1];
    } else if (board[2]==board[5]&&board[5]==board[8]) {
        return board[2];
    } else if (board[0]==board[4]&&board[4]==board[8]) {
        return board[0];
    } else if (board[2]==board[4]&&board[4]==board[6]) {
        return board[2];
    } else {
        return 0;
    }
}


void print_board(vector <int> board) {
    for (int i = 0;i < 5;i++) {
        if (i == 0) {
            cout << board[0] << " | " << board[1] << " | " << board[2];
        } else if (i == 1) {
            cout << "\n---------\n";
        } else if (i == 2) {
            cout << board[3] << " | " << board[4] << " | " << board[5];
        } else if (i == 3) {
            cout << "\n---------\n";
        } else if (i == 4) {
            cout << board[6] << " | " << board[7] << " | " << board[8];
        }
    }
}

void print_board_start() {
    for (int i = 0;i < 5;i++) {
        if (i == 0) {
            cout << "1" << " | " << "2" << " | " << "3";
        } else if (i == 1) {
            cout << "\n---------\n";
        } else if (i == 2) {
            cout << "4" << " | " << "5" << " | " << "6";
        } else if (i == 3) {
            cout << "\n---------\n";
        } else if (i == 4) {
            cout << "7" << " | " << "8" << " | " << "9";
        }
    }
}

int main() {
    vector <int> board = {0,0,0,0,0,0,0,0,0};
    int player = 1;
    int move = 0;
    int check = 0;
    int zero = 9;
    print_board_start();
    cout << "\n\nWelcome to tic-tac-toe! Input the number shown on the board above to place your mark (1 for player 1 and 2 for player 2)!\n\n";
    print_board(board);
    while (true) {
        if (zero == 0) {
            cout << "\nDraw!";
            break;
        }
        cout << "\n\nPlayer " << player << " move: ";
        cin >> move;
        cout << "\n";
        if (move > 9) {
            cout << "\nEnter a value on the board (1 to 9)";
            continue;
        }
        if (board[move-1] != 0) {
            cout << "\nCannot place on the same place previously used";
            continue;
        }
        board[move-1] = player;
        print_board(board);
        check = check_board(board);
        if (check == 1 || check == 2) {
            cout << "\nCongratulations! Player " << check << " won!";
            break;
        }  else {
            if (player == 1) {
                player += 1;
                zero -= 1;
            } else if (player == 2) {
                player -= 1;
                zero -= 1;
            }
        }
    }
}