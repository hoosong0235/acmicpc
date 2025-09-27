#include <bits/stdc++.h>
using namespace std;

#define N 50
#define M 50
#define K 2500

int t, m, n, k, cnt;
bool b[N][M];
bool visited[N][M];

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

void solve(int cx, int cy) {
    visited[cx][cy] = true;
    for (int d = 0; d < 4; d++) {
        int nx = cx + dx[d], ny = cy + dy[d];
        if (!(0 <= nx && nx < m && 0 <= ny && ny < n)) continue;
        if (b[nx][ny] && !visited[nx][ny])
            solve(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> t;
    while (t--) {
        memset(b, false, sizeof(b));
        memset(visited, false, sizeof(visited));
        cin >> m >> n >> k;
        while (k--) {
            int x, y; cin >> x >> y;
            b[x][y] = true;
        }
        
        cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (b[i][j] && !visited[i][j]) {
                    cnt++;
                    solve(i, j);
                }
        cout << cnt << '\n';
    }
}