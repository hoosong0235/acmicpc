#include <bits/stdc++.h>
using namespace std;
#define MAX 10000

struct bfs {
    int d, i;
};


int n, si, ei;
vector<bool> ps(MAX, true);


int solve() {
    bool visited[MAX] = { false };
    deque<bfs> q;
    visited[si] = true;
    q.push_back(bfs{0, si});
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        // cout << c.i << ' ';
        if (c.i == ei) return c.d;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == 3 && j == 0) continue;
                int ni = c.i - c.i / (int) pow(10, i) % 10 * pow(10, i) + j * pow(10, i);
                if (ps[ni] && !visited[ni]) {
                    visited[ni] = true;
                    q.push_back(bfs{c.d + 1, ni});
                }
            }
        }
    }
    return -1;
}


int main() {
    for (int i = 2; i < sqrt(MAX); i++) {
        for (int j = i; i * j < MAX; j++) {
            ps[i * j] = false;
        }
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> si >> ei;
        cout << solve() << '\n';
    }
}