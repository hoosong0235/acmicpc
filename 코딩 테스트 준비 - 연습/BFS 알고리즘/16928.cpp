#include <bits/stdc++.h>
using namespace std;


struct bfs {
    int d, i;
};


int n, m;
set<int> visited;
deque<bfs> q;
map<int, int> ladder, snake;


int main() {
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ladder[x] = y;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        snake[x] = y;
    }
    
    visited.insert(1);
    q.push_back(bfs{0, 1});
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        if (c.i == 100) {
            cout << c.d; return 0;
        }
        for (int d = 1; d <= 6; d++) {
            int ni = c.i + d;
            if (ladder.count(ni)) ni = ladder[ni];
            else if (snake.count(ni)) ni = snake[ni];
            if (!visited.count(ni)) {
                visited.insert(ni);
                q.push_back(bfs{c.d + 1, ni});
            }
        }
    }
}