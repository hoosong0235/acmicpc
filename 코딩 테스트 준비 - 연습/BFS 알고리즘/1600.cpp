#include <bits/stdc++.h>
using namespace std;
#define MAX 200


struct bfs {
    int d, x, y, k;
};


int k, w, h;
int a[MAX][MAX];
bool visited[31][MAX][MAX];
deque<bfs> q;
const pair<int, int> hms[8] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
const pair<int, int> mms[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};


int main() {
    cin >> k >> w >> h;
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> a[i][j];
    
    visited[k][0][0] = true;
    q.push_back(bfs{0, 0, 0, k});
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        if (c.x == h - 1 && c.y == w - 1) {
            cout << c.d; return 0;
        }
        for (pair<int, int> mm: mms) {
            int nx = c.x + mm.first, ny = c.y + mm.second;
            if (!(0 <= nx && nx < h && 0 <= ny && ny < w)) continue;
            if (a[nx][ny] || visited[c.k][nx][ny]) continue;
            visited[c.k][nx][ny] = true;
            q.push_back(bfs{c.d + 1, nx, ny, c.k});
        }
        if (c.k) for (pair<int, int> hm: hms) {
            int nx = c.x + hm.first, ny = c.y + hm.second;
            if (!(0 <= nx && nx < h && 0 <= ny && ny < w)) continue;
            if (a[nx][ny] || visited[c.k - 1][nx][ny]) continue;
            visited[c.k - 1][nx][ny] = true;
            q.push_back(bfs{c.d + 1, nx, ny, c.k - 1});
        }
    }
    cout << -1;
}