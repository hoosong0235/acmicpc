// 00:24:00 + 00:18:00
#include <bits/stdc++.h>
using namespace std;
#define N 10


struct bfs {
    int x, y, d, t; // t=0 knight, k=1 bishop, k=2 rook.
};


int n;
int min_num;
int a[N][N];
pair<int, int> xy[N * N + 1];
const int kdx[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
const int kdy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int bdx[4] = { -1, 1, -1, 1 } ;
const int bdy[4] = { -1, -1, 1, 1 };
const int rdx[4] = { 0, -1, 0, 1 };
const int rdy[4] = { -1, 0, 1, 0 };


vector<bool> solve(int s, vector<bool> v) {
    deque<bfs> q;
    bool visited[N][N][3] = { };
    auto [sx, sy] = xy[s];
    auto [ex, ey] = xy[s + 1];

    if (v[0])
        q.push_back(bfs { sx, sy, 0, 0 }), visited[sx][sy][0] = true;
    if (v[1])
        q.push_back(bfs { sx, sy, 0, 1 }), visited[sx][sy][1] = true;
    if (v[2])
        q.push_back(bfs { sx, sy, 0, 2 }), visited[sx][sy][2] = true;

    int min_d = INT_MAX;
    vector<bool> w(3, false);
    while (!q.empty()) {
        bfs c = q.front();
        q.pop_front();
        if (min_d < c.d)
            break;
        if (c.x == ex && c.y == ey) {
            min_d = c.d;
            w[c.t] = true;
        }

        switch (c.t) {
            case 0: // knight.
                for (int d = 0; d < 8; d++) {
                    int nx = c.x + kdx[d], ny = c.y + kdy[d];
                    if (nx < 0 || n <= nx || ny < 0 || n <= ny)
                        continue;
                    if (!visited[nx][ny][0]) {
                        q.push_back(bfs { nx, ny, c.d + 1, 0 });
                        visited[nx][ny][0] = true;
                    }
                }
                if (!visited[c.x][c.y][1]) {
                    q.push_back(bfs { c.x, c.y, c.d + 1, 1 });
                    visited[c.x][c.y][1] = true;
                }
                if (!visited[c.x][c.y][2]) {
                    q.push_back(bfs { c.x, c.y, c.d + 1, 2 });
                    visited[c.x][c.y][2] = true;
                }
                break;
            case 1: // bishop.
                for (int d = 0; d < 4; d++) {
                    int nx = c.x + bdx[d], ny = c.y + bdy[d];
                    while (0 <= nx && nx < n && 0 <= ny && ny < n) {
                        if (!visited[nx][ny][1]) {
                            q.push_back(bfs { nx, ny, c.d + 1, 1 });
                            visited[nx][ny][1] = true;
                        }
                        nx += bdx[d], ny += bdy[d];
                    }
                }
                if (!visited[c.x][c.y][0]) {
                    q.push_back(bfs { c.x, c.y, c.d + 1, 0 });
                    visited[c.x][c.y][0] = true;
                }
                if (!visited[c.x][c.y][2]) {
                    q.push_back(bfs { c.x, c.y, c.d + 1, 2 });
                    visited[c.x][c.y][2] = true;
                }
                break;
            case 2: // rook.
                for (int d = 0; d < 4; d++) {
                    int nx = c.x + rdx[d], ny = c.y + rdy[d];
                    while (0 <= nx && nx < n && 0 <= ny && ny < n) {
                        if (!visited[nx][ny][2]) {
                            q.push_back(bfs { nx, ny, c.d + 1, 2 });
                            visited[nx][ny][2] = true;
                        }
                        nx += rdx[d], ny += rdy[d];
                    }
                }
                if (!visited[c.x][c.y][0]) {
                    q.push_back(bfs { c.x, c.y, c.d + 1, 0 });
                    visited[c.x][c.y][0] = true;
                }
                if (!visited[c.x][c.y][1]) {
                    q.push_back(bfs { c.x, c.y, c.d + 1, 1 });
                    visited[c.x][c.y][1] = true;
                }
                break;
            default:
                break;
        }
    }

    min_num += min_d;
    return w;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            xy[a[i][j]] = { i, j };
        }

    vector<bool> v(3, true);
    for (int s = 1; s < n * n; s++)
        v = solve(s, v);

    cout << min_num;
}


// 이동할 수 있는 각 칸마다 이동해서 한 번씩,
// 그리고 현재 칸에서 변화해서 한 번씩,
// visited[N][N][3] = { };

// 처음에는 3개의 bfs를 넣고,
// 그 다음 모듈에는 그 전에 몇 가지 종류의 기물로 최솟값에 도달할 수 있었는지를 봐야 하는데,
// 그러려면 모듈에서 반환하는 값에 어떤어떤 기물들이 포함되어 있는지를 반환해주어야 함.
// 즉, num 에 depth 를 계속 누적하며
// parameter와 return 값은 vector<bool>(3);