#include <bits/stdc++.h>
using namespace std;

#define N 1'000'000

struct bfs {
    int i, d;
};

deque<bfs> q;
bool visited[N + 1];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x; cin >> x;
    
    q.push_back(bfs { x, 0 });
    visited[x] = true;
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        if (c.i == 1) {
            cout << c.d;
            return 0;
        }
        
        int ni, nd = c.d + 1;
        if (!(c.i % 3)) {
            ni = c.i / 3;
            if (!visited[ni]) {
                q.push_back(bfs { ni, nd });
                visited[ni] = true;
            }
        }
        if (!(c.i % 2)) {
            ni = c.i / 2;
            if (!visited[ni]) {
                q.push_back(bfs { ni, nd });
                visited[ni] = true;
            }
        }
        if (c.i - 1 > 0) {
            ni = c.i - 1;
            if (!visited[ni]) {
                q.push_back(bfs { ni, nd });
                visited[ni] = true;
            }
        }
    }
}