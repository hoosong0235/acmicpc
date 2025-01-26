#include <bits/stdc++.h>
using namespace std;
#define MAXN 12
#define MAXK 10
#define WHITE 0
#define RED 1
#define BLUE 2
#define RIGHT 1
#define LEFT 2
#define TOP 3
#define BOTTOM 4


int n, k;
int board[MAXN][MAXN];
vector<pair<int, int>> pieces[MAXN][MAXN]; // {num, dir}
pair<int, int> poss[MAXK]; // {x, y}
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };
int revdir[5] = { 0, LEFT, RIGHT, BOTTOM, TOP };


void white(int i, int x, int y, int nx, int ny) {
    int s = pieces[x][y].size();
    for (int j = i; j < s; j++) {
        poss[pieces[x][y][j].first] = { nx, ny };
        pieces[nx][ny].push_back(pieces[x][y][j]);
    }
    for (int j = i; j < s; j++) pieces[x][y].pop_back();
}


void red(int i, int x, int y, int nx, int ny) {
    int s = pieces[x][y].size();
    for (int j = s - 1; j >= i; j--) {
        poss[pieces[x][y][j].first] = { nx, ny };
        pieces[nx][ny].push_back(pieces[x][y][j]);
    }
    for (int j = s - 1; j >= i; j--) pieces[x][y].pop_back();
}


bool check() {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (pieces[i][j].size() >= 4) return true;
    return false;
}


void debug() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (pieces[i][j].empty()) cout << '-' << '\t';
            else { for (pair<int, int> piece: pieces[i][j]) cout << piece.first; cout << '\t'; }
        }
        cout << '\n';
    }
    cout << '\n';
}


int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> board[i][j];
    for (int num = 0; num < k; num++) {
        int x, y, dir; cin >> x >> y >> dir;
        pieces[x - 1][y - 1].push_back({ num, dir });
        poss[num] = { x - 1, y - 1 };
    }
    
    // debug();
    if (check()) { cout << 0; return 0; }
    
    int turn = 0;
    while (++turn <= 1000) {
        for (int num = 0; num < k; num++) {
            pair<int, int> pos = poss[num];
            int x = pos.first, y = pos.second;
            int s = pieces[x][y].size();
            
            int i; for (i = 0; i < s; i++) if (pieces[x][y][i].first == num) break;
            int dir = pieces[x][y][i].second;
            int nx = x + dx[dir], ny = y + dy[dir];
            if (!(0 <= nx && nx < n && 0 <= ny && ny < n)) {
                pieces[x][y][i].second = revdir[dir];
                dir = pieces[x][y][i].second;
                nx = x + dx[dir], ny = y + dy[dir];
                if (board[nx][ny] != BLUE) {
                    if (board[nx][ny] == WHITE) white(i, x, y, nx, ny);
                    else if (board[nx][ny] == RED) red(i, x, y, nx, ny);
                }
            } else if (board[nx][ny] == BLUE) {
                pieces[x][y][i].second = revdir[dir];
                dir = pieces[x][y][i].second;
                nx = x + dx[dir], ny = y + dy[dir];
                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    if (board[nx][ny] == WHITE) white(i, x, y, nx, ny);
                    else if (board[nx][ny] == RED) red(i, x, y, nx, ny);
                }
            } else if (board[nx][ny] == RED) {
                red(i, x, y, nx, ny);
            } else {
                white(i, x, y, nx, ny);
            }
            if (check()) { cout << turn; return 0; }
        }
        // debug();
    }
    
    cout << -1;
}