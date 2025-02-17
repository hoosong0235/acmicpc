// 약 00:15:00
#include <bits/stdc++.h>
using namespace std;
#define N 20
#define M 20


int n, m, a[N][M], max_num = 0;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };


int calc() {
    deque<pair<int, int>> q;
    bool visited[N][M] = { };
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == 2)
                if (!visited[i][j]) {
                    q.push_back({ i, j });
                    visited[i][j] = true;
                    bool flag = true;
                    int subcnt = 0;
                    while (!q.empty()) {
                        pair<int, int> c = q.front(); q.pop_front();
                        int cx = c.first, cy = c.second; subcnt++;
                        for (int d = 0; d < 4; d++) {
                            int nx = cx + dx[d], ny = cy + dy[d];
                            if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;
                            if (a[cx][cy] == 0) flag = false;
                            if (a[nx][ny] == 1) continue;
                            if (!visited[nx][ny]) {
                                q.push_back({ nx, ny });
                                visited[nx][ny] = true;
                            }
                        } 
                    }
                    if (flag) cnt += subcnt;
                }
    return cnt;
}


void solve(int depth, int ij) {
    if (depth == 2) {
        max_num = max(max_num, calc());
        return;
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (ij < i * n + j)
                if (a[i][j] == 0) {
                    a[i][j] = 1;
                    solve(depth + 1, i * n + j);
                    a[i][j] = 0;
                }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    
    solve(0, -1);
    cout << max_num;
}