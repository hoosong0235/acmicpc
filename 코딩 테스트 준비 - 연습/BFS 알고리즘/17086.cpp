#include <bits/stdc++.h>
using namespace std;
#define MAX 50


struct bfs {
    int d, x, y;
};


int n, m;
int a[MAX][MAX];
const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};


int solve(int x, int y) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    deque<bfs> q;
    visited[x][y] = true;
    q.push_back(bfs{0, x, y});
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        if (a[c.x][c.y]) return c.d;
        for (int d = 0; d < 8; d++) {
            int nx = c.x + dx[d], ny = c.y + dy[d];
            if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;
            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push_back(bfs{c.d + 1, nx, ny});
            }
        }
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    int max_num = INT_MIN;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) max_num = max(max_num, solve(i, j));
    cout << max_num;
}