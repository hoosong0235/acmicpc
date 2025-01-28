#include <bits/stdc++.h>
using namespace std;


int score = 0;
int n, t, x, y;
bool board[10][10];


void debug() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board[i][j]) cout << 'O';
            else cout << 'X';
        }
        cout << '\n';
    }
    cout << '\n';
}


void add_block1() { // square
    int i, j;
    for (i = x; i < 10; i++) if (board[i][y]) { i--; break; } // green
    if (i == 10) i--;
    board[i][y] = true;
    for (j = y; j < 10; j++) if (board[x][j]) { j--; break; } // blue
    if (j == 10) j--;
    board[x][j] = true;
}


void add_block2() { // horizontal rectangle
    int i, j;
    for (i = x; i < 10; i++) if (board[i][y] || board[i][y + 1]) { i--; break; } // green
    if (i == 10) i--;
    board[i][y] = true, board[i][y + 1] = true;
    for (j = y + 1; j < 10; j++) if (board[x][j]) { j--; break; } // blue
    if (j == 10) j--;
    board[x][j - 1] = true, board[x][j] = true;
}


void add_block3() { // vertical rectangle
    int i, j;
    for (i = x + 1; i < 10; i++) if (board[i][y]) { i--; break; } // green
    if (i == 10) i--;
    board[i - 1][y] = true, board[i][y] = true;
    for (j = y; j < 10; j++) if (board[x][j] || board[x + 1][j]) { j--; break; } // blue
    if (j == 10) j--;
    board[x][j] = true, board[x + 1][j] = true;
}


void score_block() {
    // green
    for (int i = 9; i >= 6; i--)
        if (board[i][0] && board[i][1] && board[i][2] && board[i][3]) {
            for (int ii = i; ii >= 5; ii--)
                for (int j = 0; j < 4; j++) {
                    board[ii][j] = board[ii - 1][j];
                    board[ii - 1][j] = false;
                }
            i++, score++;
        }
        
    // blue
    for (int j = 9; j >= 6; j--)
        if (board[0][j] && board[1][j] && board[2][j] && board[3][j]) {
            for (int jj = j; jj >= 5; jj--)
                for (int i = 0; i < 4; i++) {
                    board[i][jj] = board[i][jj - 1];
                    board[i][jj - 1] = false;
                }
            j++, score++;
        }
}


void remove_block() {
    // green
    int gcnt = 0;
    for (int i = 4; i <= 5; i++) {
        for (int j = 0; j < 4; j++)
            if (board[i][j]) {
                gcnt++; break;
            }
    }
    if (gcnt) {
        for (int i = 9; i >= 4 + gcnt; i--)
            for (int j = 0; j < 4; j++) {
                board[i][j] = board[i - gcnt][j];
                board[i - gcnt][j] = false;
            }
    }
    
    // blue
    int bcnt = 0;
    for (int j = 4; j <= 5; j++) {
        for (int i = 0; i < 4; i++)
            if (board[i][j]) {
                bcnt++; break;
            }
    }
    if (bcnt) {
        for (int j = 9; j >= 4 + bcnt; j--)
            for (int i = 0; i < 4; i++) {
                board[i][j] = board[i][j - bcnt];
                board[i][j - bcnt] = false;
            }
    }
}


int calc() {
    int cnt = 0;
    for (int i = 6; i <= 9; i++) // green
        for (int j = 0; j < 4; j++)
            if (board[i][j]) cnt++;
    for (int j = 6; j <= 9; j++) // blue    
        for (int i = 0; i < 4; i++)
            if (board[i][j]) cnt++;
    return cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        cin >> t >> x >> y;
        if (t == 1) add_block1();
        else if (t == 2) add_block2();
        else if (t == 3) add_block3();
        score_block();
        remove_block();
        // debug();
    }
    cout << score << '\n' << calc();
}