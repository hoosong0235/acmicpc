#include <bits/stdc++.h>
using namespace std;
#define MAX 50


int a[MAX][MAX];
int rss[MAX][MAX]; // room sizes
int rns[MAX][MAX]; // room numbers
int n, m, rs, rn = 0, max_rs = INT_MIN, max_num = INT_MIN;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
bool visited[MAX][MAX];
deque<pair<int, int>> q, r;


int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (!visited[i][j]) {
        rs = 0;
        rs++;
        rns[i][j] = rn;
        visited[i][j] = true;
        q.push_back({i, j});
        r.push_back({i, j});
        while (!q.empty()) {
            pair<int, int> c = q.front(); q.pop_front();
            for (int d = 0; d < 4; d++) if (~a[c.first][c.second] & 1 << d) {
                int nx = c.first + dx[d], ny = c.second + dy[d];
                if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;
                if (visited[nx][ny]) continue;
                rs++;
                rns[nx][ny] = rn;
                visited[nx][ny] = true;
                q.push_back({nx, ny});
                r.push_back({nx, ny});
            }
        }
        max_rs = max(max_rs, rs);
        while (!r.empty()) {
            pair<int, int> c = r.front(); r.pop_front();
            rss[c.first][c.second] = rs;
        }
        rn++;
    }
    for (int i = 0; i < n - 1; i++) for (int j = 0; j < m; j++) if (rns[i][j] != rns[i + 1][j]) max_num = max(max_num, rss[i][j] + rss[i + 1][j]);
    for (int j = 0; j < m - 1; j++) for (int i = 0; i < n; i++) if (rns[i][j] != rns[i][j + 1]) max_num = max(max_num, rss[i][j] + rss[i][j + 1]);
    cout << rn << '\n' << max_rs << '\n' << max_num;
}