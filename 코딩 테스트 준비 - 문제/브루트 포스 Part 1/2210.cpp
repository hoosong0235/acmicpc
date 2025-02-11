// 00:08:34
#include <bits/stdc++.h>
using namespace std;


int a[5][5];
set<int> s;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
int x, y, c;


void solve(int depth) {
    if (depth == 6) {
        s.insert(c);
        return;
    }
    
    int cx = x, cy = y;
    
    c *= 10;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (!(0 <= nx && nx < 5 && 0 <= ny && ny < 5)) continue;
        x = nx, y = ny, c += a[nx][ny];
        solve(depth + 1);
        x = cx, y = cy, c -= a[nx][ny];
    }
    c /= 10;
}


int main() {
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) cin >> a[i][j];
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) {
        x = i, y = j;
        solve(0);
    }
    cout << s.size();
}