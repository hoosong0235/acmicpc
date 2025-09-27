#include <bits/stdc++.h>
using namespace std;

#define M 1'000
#define N 1'000

struct bfs {
    int x, y, d;
};

int m, n, cnt = 0, ttl = 0;
queue<bfs> q;
bool visited[M][N];
int arr[M][N];

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            int k; cin >> k;
            if (k == 0 || k == 1) ttl++;
            if (k == 1) {
                q.push(bfs { i, j, 0 });
                visited[i][j] = true;
            }
            arr[i][j] = k;
        }
    
    while (!q.empty()) {
        bfs c = q.front(); q.pop();
        // cout << c.x << c.y << c.d << '\n';
        if (++cnt == ttl) {
            cout << c.d;
            return 0;
        }
        for (int d = 0; d < 4; d++) {
            int nx = c.x + dx[d], ny = c.y + dy[d];
            if (!(0 <= nx && nx < m && 0 <= ny && ny < n))
                continue;
            if (visited[nx][ny])
                continue;
            if (arr[nx][ny] == 0) {
                q.push(bfs { nx, ny, c.d + 1 });
                visited[nx][ny] = true;
            }
        }
    }
    
    cout << -1;
}