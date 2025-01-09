#include <bits/stdc++.h>
using namespace std;


struct bfs {
    int d, x, y;
};


char arr[8][8];
const int dx[9] = {-1, -1, 0, 1, 1, 1, 0, -1, 0};
const int dy[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
deque<bfs> q;


bool check(int d, int x, int y) {
    if (!(0 <= x && x < 8 && 0 <= y && y < 8)) return false;
    if (!(0 <= x - (d - 1))) return true;
    if (!(0 <= x - d)) {
        return arr[x - (d - 1)][y] != '#';
    } else {
        return arr[x - (d - 1)][y] != '#' && arr[x - d][y] != '#';
    }
    
}


int main() {
    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) cin >> arr[i][j];
    q.push_back(bfs{0, 7, 0});
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        if (c.x == 0 && c.y == 7) {
            cout << 1; return 0;
        }
        for (int d = 0; d < 9; d++) {
            int nd = c.d + 1, nx = c.x + dx[d], ny = c.y + dy[d];
            if (check(nd, nx, ny)) {
                q.push_back(bfs{nd, nx, ny});
            }
        }
    }
    cout << 0;
}