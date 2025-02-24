// 00:45:00
#include <bits/stdc++.h>
using namespace std;
#define N 5


struct bfs {
    int x, y, z, d;
};


int a[N][N][N], b[N][N][N], c[N][N][N], min_num = INT_MAX, cp = 0;
bool cvisited[5];
const int dx[6] = { -1, 1, 0, 0, 0, 0 };
const int dy[6] = { 0, 0, -1, 1, 0, 0 };
const int dz[6] = { 0, 0, 0, 0, -1, 1 };


int subcalc() {
    if (!c[0][0][0] || !c[N - 1][N - 1][N - 1])
        return INT_MAX;

    deque<bfs> q;
    bool visited[N][N][N] = { };
    q.push_back(bfs { 0, 0, 0, 0 });
    visited[0][0][0] = true;
    while (!q.empty()) {
        bfs curr = q.front(); q.pop_front();
        if (curr.x == N - 1 && curr.y == N - 1 && curr.z == N - 1)
            return curr.d;
        for (int d = 0; d < 6; d++) {
            int nx = curr.x + dx[d], ny = curr.y + dy[d], nz = curr.z + dz[d];
            if (!(0 <= nx && nx < N && 0 <= ny && ny < N && 0 <= nz && nz < N))
                continue;
            if (c[nx][ny][nz] && !visited[nx][ny][nz]) {
                q.push_back(bfs { nx, ny, nz, curr.d + 1 });
                visited[nx][ny][nz] = true;
            }
        }
    }
    return INT_MAX;
}


void calc(int d) {
    if (d == N) {
        min_num = min(min_num, subcalc());
        return;
    }
    
    for (int i = 0; i < N; i++) 
        if (!cvisited[i]) {
            cvisited[i] = true;
            memcpy(c[cp++], b[i], sizeof(int) * N * N);
            calc(d + 1);
            cp--;
            cvisited[i] = false;
        }
}


void rotate(int d, int k) {
    int tmp[N][N] = { };
    memcpy(tmp, a[d], sizeof(int) * N * N);
    while (k--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                b[d][j][N - 1 - i] = tmp[i][j];
            }
        }
        memcpy(tmp, b[d], sizeof(int) * N * N);
    }
}


void solve(int d) {
    if (d == N) {
        calc(0);
        return;
    }

    for (int k = 1; k <= 4; k++) {
        rotate(d, k);
        solve(d + 1);
    }
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                cin >> a[i][j][k];

    solve(0);

    cout << (min_num != INT_MAX ? min_num : -1);
}