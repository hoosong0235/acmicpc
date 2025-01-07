#include <bits/stdc++.h>
using namespace std;


struct bfs {
    int d, x, y;
};


int n;
bool visited[200][200];
deque<bfs> q;
const int dx[6] = {-2, -2, 0, 0, 2, 2};
const int dy[6] = {-1, 1, -2, 2, -1, 1};


int main() {
    int x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    visited[x1][y1] = true;
    q.push_back(bfs{0, x1, y1});
    while(!q.empty()) {
        bfs c = q.front(); q.pop_front();
        if (c.x == x2 && c.y == y2) {
            cout << c.d; return 0;
        }
        for (int d = 0; d < 6; d++) {
            int nx = c.x + dx[d], ny = c.y + dy[d];
            if (!(0 <= nx && nx < n && 0 <= ny && ny < n)) continue;
            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push_back(bfs{c.d + 1, nx, ny});
            }
        }
    }
    cout << -1; return 0;
}