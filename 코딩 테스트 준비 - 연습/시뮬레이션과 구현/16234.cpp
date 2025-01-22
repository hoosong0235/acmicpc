#include <bits/stdc++.h>
using namespace std;
#define MAXN 50


bool b;
int n, l, r, c;
int a[MAXN][MAXN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[MAXN][MAXN];
set<pair<int, int>> ss[MAXN * MAXN];


void debug() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << a[i][j] << ' ';
        cout << '\n';
    }
}


void dfs(int ci, int cj) {
    visited[ci][cj] = true;
    ss[c].insert({ci, cj});
    for (int d = 0; d < 4; d++) {
        int ni = ci + dx[d], nj = cj + dy[d];
        if (!(0 <= ni && ni < n && 0 <= nj && nj < n)) continue;
        if (visited[ni][nj]) continue;
        int diff = abs(a[ci][cj] - a[ni][nj]);
        if (l <= diff && diff <= r) dfs(ni, nj);
    }
}


int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    int cnt = 0;
    while (true) {
        // debug();
        c = 0;
        memset(visited, false, sizeof(bool) * MAXN * MAXN);
        for (int i = 0; i < n * n; i++) ss[i].clear();
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (!visited[i][j]) {
            dfs(i, j);
            c++;
        }
        for (int i = 0; i < c; i++) {
            int s = 0;
            for (pair<int, int> p: ss[i]) s += a[p.first][p.second];
            for (pair<int, int> p: ss[i]) a[p.first][p.second] = s / ss[i].size();
        }
        if (c == n * n) break;
        cnt++;
    }
    cout << cnt;
}