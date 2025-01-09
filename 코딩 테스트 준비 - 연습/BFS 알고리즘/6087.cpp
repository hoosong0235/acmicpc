#include <bits/stdc++.h>
using namespace std;
#define MAX 100


struct bfs {
    int d, x, y;
};


bool b = false;
int n, m, c1x, c1y, c2x, c2y;
char a[MAX][MAX];
bool vstd[MAX][MAX];
deque<bfs> q;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};


bool check(int x, int y) {
    if (!(0 <= x && x < n && 0 <= y && y < m)) return false;
    return a[x][y] != '*';
}


int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] == 'C') {
            if (b) c2x = i, c2y = j;
            else c1x = i, c1y = j, b = true;
        }
    }
    
    vstd[c1x][c1y] = true;
    q.push_back(bfs{0, c1x, c1y});
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        // cout << c.d << c.x << c.y << '\n';
        if (c.x == c2x && c.y == c2y) {
            cout << c.d - 1; return 0;
        }
        for (int d = 0; d < 4; d++) {
            int nd = c.d + 1, nx = c.x + dx[d], ny = c.y + dy[d];
            while (check(nx, ny)) {
                if (!vstd[nx][ny]) {
                    vstd[nx][ny] = true;
                    q.push_back(bfs{nd, nx, ny});
                }
                nx += dx[d], ny += dy[d];
            }
        }
    }
}