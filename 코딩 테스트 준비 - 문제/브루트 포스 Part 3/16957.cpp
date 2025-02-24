// 00:30:45
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define R 500
#define C 500


int r, c, a[R][C], b[R][C], e[R][C];
const int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int rev[8] = { 4, 5, 6, 7, 0, 1, 2, 3 };


void debug() {
    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++)
    //         cout << a[i][j] << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';
    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++)
    //         cout << b[i][j] << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            cout << e[i][j] << ' ';
        cout << '\n';
    }
}


int dir(int x, int y) {
    int min_d = 8, min_num = a[x][y];
    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (!(0 <= nx && nx < r && 0 <= ny && ny < c))
            continue;
        if (a[nx][ny] < min_num)
            min_d = d, min_num = a[nx][ny];
    }
    return min_d;
}


void solve(int x, int y) {
    int num = 0;
    deque<pair<int, int>> q;
    bool visited[R][C] = { };
    q.push_back({ x, y });
    visited[x][y] = true;
    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop_front();
        num++;
        for (int d = 0; d < 8; d++) {
            int nx = p.first + dx[d], ny = p.second + dy[d];
            if (!(0 <= nx && nx < r && 0 <= ny && ny < c)) continue;
            if (rev[d] == b[nx][ny] && !visited[nx][ny]) {
                q.push_back({ nx, ny });
                visited[nx][ny] = true;
            }
        }
    }
    e[x][y] += num;
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];
    
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            b[i][j] = dir(i, j);
            
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (b[i][j] == 8)
                solve(i, j);
    
    debug();
}