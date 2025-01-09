#include <bits/stdc++.h>
using namespace std;


struct bfs {
    int d, x, y;
};


int n, cx, cy, levl = 2, expr = 0, cnt = 0;
int arr[20][20];
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};


bool comp(bfs a, bfs b) {
    return a.x != b.x ? a.x < b.x : a.y < b.y;
}


bfs solve(bfs c) {
    bool visited[20][20] = { false };
    deque<bfs> q;
    visited[c.x][c.y] = true;
    q.push_back(c);
    while (!q.empty()) {
        c = q.front(); q.pop_front();
        if (arr[c.x][c.y] && arr[c.x][c.y] < levl) return c;
        for (int d = 0; d < 4; d++) {
            int nx = c.x + dx[d], ny = c.y + dy[d];
            if (!(0 <= nx && nx < n && 0 <= ny && ny < n)) continue;
            if (!visited[nx][ny] && ((arr[nx][ny] && arr[nx][ny] <= levl) || !arr[nx][ny])) {
                visited[nx][ny] = true;
                q.push_back(bfs{c.d + 1, nx, ny});
            }
        }
        // for (bfs tmp: q) cout << tmp.d << tmp.x << tmp.y << ' '; cout << '\n';
        if (!q.empty()) if (c.d != q.front().d) sort(q.begin(), q.end(), comp);
        // for (bfs tmp: q) cout << tmp.d << tmp.x << tmp.y << ' '; cout << '\n';
    }
    cout << cnt;
    exit(0);
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> arr[i][j];
        if (arr[i][j] == 9) cx = i, cy = j, arr[i][j] = 0;
    }
    bfs curr = bfs{0, cx, cy}, next;
    while (1) {
        next = solve(curr);
        // cout << "next.d: " << next.d << ", next.x: " << next.x << ", next.y: " << next.y << '\n';
        cnt += next.d, expr++, arr[next.x][next.y] = 0;
        // for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) cout << arr[i][j] << ' '; cout << '\n'; }
        if (expr == levl) expr = 0, levl++;
        curr = bfs{0, next.x, next.y};
    }
}