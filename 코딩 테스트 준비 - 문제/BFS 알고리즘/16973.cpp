// editorial
// 00:39:25
#include <bits/stdc++.h>
using namespace std;
#define N 1000
#define M 1000


struct bfs {
    int x, y, d;
};


int a[N + 1][M + 1];
deque<bfs> q;
bool visited[N + 1][M + 1];
int n, m, h, w, sr, sc, fr, fc;
const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { -1, 0, 1, 0 };


bool check(int nx, int ny, int d) {
    switch (d) {
        case 0:
            for (int i = nx; i < nx + h; i++)
                if (a[i][ny])
                    return false;
            break;
        case 1:
            for (int j = ny; j < ny + w; j++)
                if (a[nx][j])
                    return false;
            break;
        case 2:
            for (int i = nx; i < nx + h; i++)
                if (a[i][ny + w - 1])
                    return false;
            break;
        case 3:
            for (int j = ny; j < ny + w; j++)
                if (a[nx + h - 1][j])
                    return false;
            break;
        default:
            break;
    }
    
    return true;
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    cin >> h >> w >> sr >> sc >> fr >> fc;
    
    q.push_back(bfs { sr, sc, 0 });
    visited[sr][sc] = true;
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        if (c.x == fr && c.y == fc) {
            cout << c.d;
            return 0;
        }
        for (int d = 0; d < 4; d++) {
            int nx = c.x + dx[d], ny = c.y + dy[d];
            if (nx < 1 || n < nx + h - 1 || ny < 1 || m < ny + w - 1) continue;
            if (!check(nx, ny, d)) continue;
            if (!visited[nx][ny]) {
                q.push_back(bfs { nx, ny, c.d + 1 });
                visited[nx][ny] = true;
            }
        }
    }
    
    cout << -1;
}
