#include <bits/stdc++.h>
using namespace std;
#define MAXN 20
#define MAXM 400
#define MAXK 1000


int n, m, k;
set<pair<int, int>> board[MAXN][MAXN]; // { num, dir }
pair<int, int> poss[MAXM + 1]; // { x, y }
int priority[MAXM + 1][5][5];
pair<int, int> smell[MAXN][MAXN]; // { num, turn }
bool eaten[MAXM + 1];
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };


void incr_smell() {
    for (int num = 1; num <= m; num++) if (!eaten[num]) {
        pair<int, int> pos = poss[num];
        smell[pos.first][pos.second] = { num, k };
        // todo: how handle if there is no possible movement of the given shark?
        // -> maybe there is no such case since 1 <= k?
    }
}


void decr_smell() {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) smell[i][j].second--;
}


void move_shark() {
    for (int num = 1; num <= m; num++) if (!eaten[num]) {
        pair<int, int> pos = poss[num];
        int cx = pos.first, cy = pos.second;
        int cdir;
        for (pair<int, int> shark: board[cx][cy])
            if (shark.first == num) {
                cdir = shark.second;
                break;
            }
        
        bool is_smell = true;
        for (int i = 1; i <= 4; i++) {
            int ndir = priority[num][cdir][i];
            int nx = cx + dx[ndir], ny = cy + dy[ndir];
            if (!(0 <= nx && nx < n && 0 <= ny && ny < n)) continue;
            if (!(smell[nx][ny].second > 0)) {
                is_smell = false;
                break;
            }
        }
        
        for (int i = 1; i <= 4; i++) {
            int ndir = priority[num][cdir][i];
            int nx = cx + dx[ndir], ny = cy + dy[ndir];
            if (!(0 <= nx && nx < n && 0 <= ny && ny < n)) continue;
            if (is_smell && smell[nx][ny].first == num && smell[nx][ny].second > 0) {
                poss[num] = { nx, ny };
                board[cx][cy].erase({ num, cdir });
                board[nx][ny].insert({ num, ndir });
                break;
            } else if (!is_smell && !(smell[nx][ny].second > 0)) {
                poss[num] = { nx, ny };
                board[cx][cy].erase({ num, cdir });
                board[nx][ny].insert({ num, ndir });
                break;
            }
        }
    }
    
    for (int num = 1; num <= m; num++) if (!eaten[num]) {
        pair<int, int> pos = poss[num];
        int cx = pos.first, cy = pos.second;
        if (board[cx][cy].size() > 1)
            for (pair<int, int> shark: board[cx][cy])
                if (shark.first != num) {
                    // board[cx][cy].erase(shark) // potential index error
                    eaten[shark.first] = true;
                }
    }
}


bool check() {
    for (int num = 2; num <= m; num++) if (!eaten[num]) return false;
    return true;
}


int main() {
    // initialize
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        int num; cin >> num;
        if (num) poss[num] = { i, j };
        smell[i][j] = { 0, 0 }; // is dummy value necessary?
    }
    for (int num = 1; num <= m; num++) {
        int dir; cin >> dir;
        pair<int, int> pos = poss[num];
        board[pos.first][pos.second].insert({ num, dir });
    }
    for (int num = 1; num <= m; num++)
        for (int cdir = 1; cdir <= 4; cdir++)
            for (int ndir = 1; ndir <= 4; ndir++)
                cin >> priority[num][cdir][ndir];
                
    // solve
    int turn = 0;
    incr_smell();
    while (++turn <= 1000) {
        move_shark();
        decr_smell();
        incr_smell();
        if (check()) { cout << turn; return 0; }
    }
    
    cout << -1;
}