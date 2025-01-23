#include <bits/stdc++.h>
using namespace std;
#define MAXN 12
#define MAXK 10


struct piece {
    int k, d;
};


int turn = 0;
int n, k;
int x, y, d;
int a[MAXN][MAXN];
pair<int, int> poss[MAXK];
vector<piece> ps[MAXN][MAXN];
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };
int d2rev[5] = { 0, 2, 1, 4, 3 };
char d2eng[5] = { '-', 'R', 'L', 'T', 'B' };
char c2eng[3] = { 'w', 'r', 'b' };


void debug() {
    // return;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << c2eng[a[i][j]];
            for (piece p: ps[i][j]) cout << p.k + 1 << d2eng[p.d] << ' ';
            cout << '\t';
        }
        cout << '\n';
    }
    cout << '\n';
}


void white(int ci, int cj, int ni, int nj) {
    for (int k = 0; k < ps[ci][cj].size(); k++) {
        ps[ni][nj].push_back(ps[ci][cj][k]);
        poss[ps[ci][cj][k].k] = { ni, nj };
    }
    ps[ci][cj].clear();
}


void red(int ci, int cj, int ni, int nj) {
    for (int k = ps[ci][cj].size() - 1; k >= 0; k--) {
        ps[ni][nj].push_back(ps[ci][cj][k]);
        poss[ps[ci][cj][k].k] = { ni, nj };
    }
    ps[ci][cj].clear();
}


bool check() {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (ps[i][j].size() >= 4) return true;
    return false;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    for (int i = 0; i < k; i++) {
        cin >> x >> y >> d;
        poss[i] = { x - 1, y - 1 };
        ps[x - 1][y - 1].push_back(piece { i, d });
    }
    // debug();
    if (check()) { cout << 0; return 0; }
    while (turn++ < 1000) {
        for (int i = 0; i < k; i++) {
            pair<int, int> pos = poss[i];
            x = pos.first, y = pos.second;
            int k = ps[x][y][0].k;
            if (k != i) continue;
            int d = ps[x][y][0].d;
            int nx = x + dx[d], ny = y + dy[d];
            if (!(0 <= nx && nx < n && 0 <= ny && ny < n)) {
                ps[x][y][0].d = d2rev[ps[x][y][0].d];
                d = ps[x][y][0].d;
                nx = x + dx[d], ny = y + dy[d];
                if (a[nx][ny] == 0) white(x, y, nx, ny);
                else if (a[nx][ny] == 1) red(x, y, nx, ny);
            } else if (a[nx][ny] == 2) {
                ps[x][y][0].d = d2rev[ps[x][y][0].d];
                d = ps[x][y][0].d;
                nx = x + dx[d], ny = y + dy[d];
                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    if (a[nx][ny] == 0) white(x, y, nx, ny);
                    else if (a[nx][ny] == 1) red(x, y, nx, ny);
                }
            } else if (a[nx][ny] == 1) {
                red(x, y, nx, ny);
            } else {
                white(x, y, nx, ny);
            }
        }
        // debug();
        if (check()) break;
    }
    cout << (turn <= 1000 ? turn : -1);
}