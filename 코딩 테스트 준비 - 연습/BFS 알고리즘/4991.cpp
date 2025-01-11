#include <bits/stdc++.h>
using namespace std;
#define MAX 20


struct bfs {
    int d, x, y;
};


int h, w, min_num;
char a[MAX][MAX];
int dist[10][10];
pair<int, int> o;
vector<pair<int, int>> xs;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool vstd[10];


int calc(pair<int, int> begin, pair<int, int> end) {
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    deque<bfs> q;
    visited[begin.first][begin.second] = true;
    q.push_back(bfs{0, begin.first, begin.second});
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        if (c.x == end.first && c.y == end.second) return c.d;
        for (int d = 0; d < 4; d++) {
            int nx = c.x + dx[d], ny = c.y + dy[d];
            if (!(0 <= nx && nx < h && 0 <= ny && ny < w)) continue;
            if (a[nx][ny] != 'x' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push_back(bfs{c.d + 1, nx, ny});
            }
        }
    }
    return INT_MAX;
}


void solve(int d, int prev, int num) {
    if (d == xs.size()) {
        min_num = min(min_num, num); return;
    }
    for (int i = 0; i < xs.size(); i++) {
        if (prev != -1) if (dist[prev][i] == INT_MAX) continue;
        if (!vstd[i]) {
            vstd[i] = true;
            if (prev == -1) solve(d + 1, i, num + calc(o, xs[i]));
            else solve(d + 1, i, num + dist[prev][i]);
            vstd[i] = false;
        }
    }
}


int main() {
    while (true) {
        min_num = INT_MAX;
        xs.clear();
        
        cin >> w >> h;
        if (!w && !h) return 0;
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'o') o = {i, j};
            else if (a[i][j] == '*') xs.push_back({i, j});
        }
        
        for (int i = 0; i < xs.size(); i++) for (int j = 0; j < xs.size(); j++) {
            int tmp = calc(xs[i], xs[j]);
            dist[i][j] = tmp, dist[j][i] = tmp;
        }
        
        solve(0, -1, 0);
        cout << (min_num == INT_MAX ? -1 : min_num) << '\n';
    }
}