#include <bits/stdc++.h>
using namespace std;


struct bfs {
    int d, x, y, b;
};


const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int arr[1001][1001];
bool visited[1001][1001][2];
deque<bfs> q;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= m; j++) arr[i][j] = s[j - 1] - '0';
    }
    
    visited[1][1][1] = true;
    q.push_back(bfs{1, 1, 1, 1});
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        if (c.x == n && c.y == m) {
            cout << c.d; return 0;
        }
        for (int d = 0; d < 4; d++) {
            int nx = c.x + dx[d], ny = c.y + dy[d];
            if (!(1 <= nx && nx <= n && 1 <= ny && ny <= m)) continue;
            if (arr[nx][ny] && c.b && !visited[nx][ny][c.b - 1]) {
                visited[nx][ny][c.b - 1] = true;
                q.push_back(bfs{c.d + 1, nx, ny, c.b - 1});
            } else if (!arr[nx][ny] && !visited[nx][ny][c.b]) {
                visited[nx][ny][c.b] = true;
                q.push_back(bfs{c.d + 1, nx, ny, c.b});
            }
        }
    }
    cout << -1;
}