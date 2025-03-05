// 00:38:15
#include <bits/stdc++.h>
using namespace std;
#define N 50
#define M 50


struct bfs {
    int x, y, d, dir;
};


int n, m, min_num = INT_MAX;
char a[N][M];
deque<bfs> q;
bool visited[N][M][4];
const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { -1, 0, 1, 0 };


void solve(bfs b) {
    deque<bfs> q;
    bool visited[N][M][4] = { };
    
    q.push_back(b);
    visited[b.x][b.y][b.dir] = true;
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        if (!(b.x == c.x && b.y == c.y) && a[c.x][c.y] == 'C') {
            min_num = min(min_num, c.d);
            return;
        }
        for (int d = 0; d < 4; d++)
            if (d != c.dir) {
                int nx = c.x + dx[d], ny = c.y + dy[d];
                if (nx < 0 || n <= nx || ny < 0 || m <= ny)
                    continue;
                if (!visited[nx][ny][d] && a[nx][ny] != '#') {
                    q.push_back(bfs { nx, ny, c.d + 1, d });
                    visited[nx][ny][d] = true;
                }
            }
    }
}


int main() {
    cin >> n >> m;
    int sx, sy;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
            if (a[i][j] == 'S')
                sx = i, sy = j;
        }
    }
    
    q.push_back(bfs { sx, sy, 0, -1 });
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        if (a[c.x][c.y] == 'C')
            solve(c);
        for (int d = 0; d < 4; d++)
            if (d != c.dir) {
                int nx = c.x + dx[d], ny = c.y + dy[d];
                if (nx < 0 || n <= nx || ny < 0 || m <= ny)
                    continue;
                if (!visited[nx][ny][d] && a[nx][ny] != '#') {
                    q.push_back(bfs { nx, ny, c.d + 1, d });
                    visited[nx][ny][d] = true;
                }
            }
    }
    
    cout << (min_num != INT_MAX ? min_num : -1);
}
