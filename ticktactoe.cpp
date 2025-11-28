#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}};

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

char checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2]) return board[i][0];
        if (board[0][i]==board[1][i] && board[1][i]==board[2][i]) return board[0][i];
    }
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2]) return board[0][0];
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0]) return board[0][2];
    return ' ';
}

bool isFull() {
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            if (board[i][j]!='X' && board[i][j]!='O')
                return false;
    return true;
}

void playerMove() {
    int move;
    cout << "Enter your move (1-9): ";
    cin >> move;
    if (move < 1 || move > 9) return;

    int r = (move-1)/3, c = (move-1)%3;
    if (board[r][c]=='X' || board[r][c]=='O') return;
    board[r][c] = 'X';
}

void aiMove() {
    // Simple rule-based (optimized DAA logic)
    // 1. If AI can win, take that move
    // 2. If player can win next, block
    // 3. Else take first empty

    // Check possible winning/blocking moves
    for (int k=0;k<2;k++) { // k=0 (AI win), k=1 (block player)
        char mark = (k==0)?'O':'X';
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                if (board[i][j]!='X' && board[i][j]!='O') {
                    char temp = board[i][j];
                    board[i][j] = mark;
                    if (checkWin()==mark) {
                        if (k==0) return; // AI wins
                        else { board[i][j]='O'; return; } // Block player
                    }
                    board[i][j]=temp;
                }
            }
        }
    }

    // Otherwise, take first empty cell
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            if (board[i][j]!='X' && board[i][j]!='O') {
                board[i][j]='O';
                return;
            }
}

int main() {
    cout << "\n--- Simple Tic Tac Toe (Optimized DAA) ---\n";
    displayBoard();

    while (true) {
        playerMove();
        displayBoard();

        if (checkWin()=='X') { cout << "You win!\n"; break; }
        if (isFull()) { cout << "Draw!\n"; break; }

        cout << "AI's move...\n";
        aiMove();
        displayBoard();

        if (checkWin()=='O') { cout << "AI wins!\n"; break; }
        if (isFull()) { cout << "Draw!\n"; break; }
    }
    return 0;
}
