#include <bits/stdc++.h>
using namespace std;
#define N 16


int n, a[N][N];
const int dx[3] = { 0, 1, 1 };
const int dy[3] = { 1, 1, 0 };
deque<tuple<int, int, int>> q;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    
    int cnt = 0;
    q.push_back({ 0, 1, 0 });
    while (!q.empty()) {
        tuple<int, int, int> c = q.front(); q.pop_front();
        int cx = get<0>(c), cy = get<1>(c), cd = get<2>(c);
        // cout << cx << cy << cd << '\n';
        if (cx == n - 1 && cy == n - 1) cnt++;
        for (int d = 0; d < 3; d++) if (abs(cd - d) < 2) {
            int nx = cx + dx[d], ny = cy + dy[d];
            if (!(0 <= nx && nx < n && 0 <= ny && ny < n)) continue;
            if (a[nx][ny]) continue;
            if (d == 1 && (a[nx - 1][ny] || a[nx][ny - 1])) continue;
            q.push_back({ nx, ny, d });
        }
    }
    cout << cnt;
}