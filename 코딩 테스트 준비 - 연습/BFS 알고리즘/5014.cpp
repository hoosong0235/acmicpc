#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000


struct bfs {
    int d, i;
};


int f, s, g, u, d;
bool visited[MAX + 1];
deque<bfs> q;


int main() {
    cin >> f >> s >> g >> u >> d;
    visited[s] = true;
    q.push_back(bfs{0, s});
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        if (c.i == g) {
            cout << c.d; return 0;
        }
        int ni;
        ni = c.i + u;
        if (ni <= f) if (!visited[ni]) {
            visited[ni] = true;
            q.push_back(bfs{c.d + 1, ni});
        }
        ni = c.i - d;
        if (1 <= ni) if (!visited[ni]) {
            visited[ni] = true;
            q.push_back(bfs{c.d + 1, ni});
        }
    }
    cout << "use the stairs";
}