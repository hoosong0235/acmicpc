#include <bits/stdc++.h>
using namespace std;
#define MAX 50


struct bfs {
    int d, x, y;
};


int n, m, min_num = INT_MAX;
int a[MAX][MAX];
vector<pair<int, int>> cs;
vector<pair<int, int>> vs;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};


int calc() {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    deque<bfs> q;
    for (pair<int, int> v: vs) {
        visited[v.first][v.second] = true;
        q.push_back({0, v.first, v.second});
    }
    bfs c;
    while (!q.empty()) {
        c = q.front(); q.pop_front();
        for (int d = 0; d < 4; d++) {
            int nx = c.x + dx[d], ny = c.y + dy[d];
            if (!(0 <= nx && nx < n && 0 <= ny && ny < n)) continue;
            if (visited[nx][ny] || a[nx][ny] == 1) continue;
            visited[nx][ny] = true;
            q.push_back({c.d + 1, nx, ny});
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (!visited[i][j] && a[i][j] != 1) return INT_MAX;
    return c.d;
}


void solve(int d, int ii) {
    if (d == m) {
        min_num = min(min_num, calc()); return;
    }
    
    for (int i = ii; i < cs.size(); i++) {
        vs.push_back(cs[i]);
        solve(d + 1, i + 1);
        vs.pop_back();
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        if (a[i][j] == 2) cs.push_back({i, j});
    }
    
    solve(0, 0);
    cout << (min_num == INT_MAX ? -1 : min_num);
}