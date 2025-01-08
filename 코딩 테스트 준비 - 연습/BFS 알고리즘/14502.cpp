#include <bits/stdc++.h>
using namespace std;


int n, m, min_num = INT_MAX;
int arr[8][8];
vector<pair<int, int>> zs;
vector<pair<int, int>> os;
vector<pair<int, int>> ts;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};


int calc() {
    int cnt = 0;
    bool visited[8][8] = { false };
    deque<pair<int, int>> q;
    for (pair<int, int> t: ts) {
        cnt++;
        visited[t.first][t.second] = true;
        q.push_back(t);
    }
    while (!q.empty()) {
        pair<int, int> c = q.front(); q.pop_front();
        for (int d = 0; d < 4; d++) {
            int nx = c.first + dx[d], ny = c.second + dy[d];
            if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;
            if (arr[nx][ny] == 0 && !visited[nx][ny]) {
                cnt++;
                visited[nx][ny] = true;
                q.push_back({nx, ny});
            }
        }
    }
    return cnt;
}


void solve(int d, int ii) {
    if (d == 3) {
        min_num = min(min_num, calc()); return;
    }
    
    for (int i = ii; i < zs.size(); i++) {
        pair<int, int> z = zs[i];
        arr[z.first][z.second] = 1;
        solve(d + 1, i + 1);
        arr[z.first][z.second] = 0;
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> arr[i][j];
        if (arr[i][j] == 0) zs.push_back({i, j});
        else if (arr[i][j] == 1) os.push_back({i, j});
        else ts.push_back({i, j});
    }
    solve(0, 0);
    cout << n * m - (os.size() + 3 + min_num);
}