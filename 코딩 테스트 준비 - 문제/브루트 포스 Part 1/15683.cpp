#include <bits/stdc++.h>
using namespace std;
#define N 8
#define M 8
#define WALL 6


int n, m, min_num = INT_MAX;
int a[N][M];
int visited[N][M];
const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { -1, 0, 1, 0 };
vector<pair<int, int>> cctvs;
const vector<int> twos[2] = {{ 0, 2 }, { 1, 3 }};
const vector<int> threes[4] = {{ 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 0 }};
const vector<int> fours[4] = {{ 0, 1, 2 }, { 1, 2, 3 }, { 2, 3, 0 }, { 3, 0, 1 }};


void debug() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << visited[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}


int calc() {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!a[i][j] && !visited[i][j])
                cnt++;
    return cnt;
}


void watch(int x, int y, vector<int> ds, bool rev=false) {
    for (auto d: ds) {
        int nx = x + dx[d], ny = y + dy[d];
        while (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] != WALL) {
            if (rev) visited[nx][ny]--;
            else visited[nx][ny]++;
            nx += dx[d], ny += dy[d];
        }
    }
}


void solve(int depth) {
    if (depth == cctvs.size()) {
        min_num = min(min_num, calc());
        return;
    }
    
    auto &[x, y] = cctvs[depth];
    switch (a[x][y]) {
        case 1:
            for (int d = 0; d < 4; d++) {
                watch(x, y, { d });
                solve(depth + 1);
                watch(x, y, { d }, true);
            }
            break;
        case 2:
            for (auto v: twos) {
                watch(x, y, v);
                solve(depth + 1);
                watch(x, y, v, true);
            }
            break;
        case 3:
            for (auto v: threes) {
                watch(x, y, v);
                solve(depth + 1);
                watch(x, y, v, true);
            }
            break;
        case 4:
            for (auto v: fours) {
                watch(x, y, v);
                solve(depth + 1);
                watch(x, y, v, true);
            }
            break;
        case 5:
            watch(x, y, { 0, 1, 2, 3 });
            solve(depth + 1);
            watch(x, y, { 0, 1, 2, 3 }, true);
            break;
        default:
            break;
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] && a[i][j] != WALL) cctvs.push_back({ i, j });
    }
    solve(0);
    cout << min_num;
}