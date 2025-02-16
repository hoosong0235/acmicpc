// 01:39:36
#include <bits/stdc++.h>
using namespace std;
#define N 20


int n, x, y, d1, d2;
int a[N + 1][N + 1];
const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { -1, 0, 1, 0 };


int calc() {
    int ps[5] = { };
    bool visited[N + 1][N + 1] = { };
    bool border[N + 1][N + 1][4] = { };
    
    for (int i = 0; i <= d1; i++) {
        int r = x + i, c = y - i;
        if (!visited[r][c]) {
            border[r][c][0] = true;
            border[r][c][1] = true;
        }
    }
    for (int i = 0; i <= d2; i++) {
        int r = x + i, c = y + i;
        if (!visited[r][c]) {
            border[r][c][2] = true;
            border[r][c][1] = true;
        }
    }
    for (int i = 0; i <= d2; i++) {
        int r = x + d1 + i, c = y - d1 + i;
        if (!visited[r][c]) {
            border[r][c][0] = true;
            border[r][c][3] = true;
        }
    }
    for (int i = 0; i <= d1; i++) {
        int r = x + d2 + i, c = y + d2 - i;
        if (!visited[r][c]) {
            border[r][c][2] = true;
            border[r][c][3] = true;
        }
    }
    
    // if (x == 1 && y == 2 && d1 == 1 && d2 == 7) {
    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 1; j <= n; j++) {
    //             for (int d = 0; d < 4; d++) cout << border[i][j][d];
    //             cout << ' ';
    //         }
    //         cout << '\n';
    //     }
    // }
    
    deque<pair<int, int>> q;
    q.push_back({ x + d1, y });
    visited[x + d1][y] = true, ps[4] += a[x + d1][y];
    while (!q.empty()) {
        pair<int, int> c = q.front(); q.pop_front();
        int cx = c.first, cy = c.second;
        for (int d = 0; d < 4; d++) {
            if (border[cx][cy][d]) continue;
            int nx = cx + dx[d], ny = cy + dy[d];
            if (!(1 <= nx && nx <= n && 1 <= ny && ny <= n)) continue;
            if (!visited[nx][ny]) {
                visited[nx][ny] = true, ps[4] += a[nx][ny];
                q.push_back({ nx, ny });
            }
        }
    }
    
    // if (x == 1 && y == 2 && d1 == 1 && d2 == 7) {
    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 1; j <= n; j++) cout << visited[i][j] << ' ';
    //         cout << '\n';
    //     }
    // }
    
    for (int r = 1; r < x + d1; r++) for (int c = 1; c <= y; c++)
        if (!visited[r][c]) ps[0] += a[r][c];
    for (int r = 1; r <= x + d2; r++) for (int c = y + 1; c <= n; c++)
        if (!visited[r][c]) ps[1] += a[r][c];
    for (int r = x + d1; r <= n; r++) for (int c = 1; c < y - d1 + d2; c++)
        if (!visited[r][c]) ps[2] += a[r][c];
    for (int r = x + d2 + 1; r <= n; r++) for (int c = y - d1 + d2; c <= n; c++)
        if (!visited[r][c]) ps[3] += a[r][c];
        
    return *max_element(ps, ps + 5) - *min_element(ps, ps + 5);
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
            
    int min_num = INT_MAX;
    for (x = 1; x <= n; x++) for (y = 1; y <= n; y++)
        for (d1 = 1; d1 <= n; d1++) for (d2 = 1; d2 <= n; d2++)
            if (x + d1 + d2 <= n && 1 <= y - d1 && y + d2 <= n) {
                min_num = min(min_num, calc());
            }
    cout << min_num;
}