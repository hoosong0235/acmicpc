// 00:34:30
#include <bits/stdc++.h>
using namespace std;
#define N 50
#define M 1000


int n, a[N], adds[M + 1], muls[M + 1], max_mul = 0;


struct bfs {
    int i, add, mul;
};


void debug() {
    for (int i = 0; i <= M; i++)
        cout << adds[i] << ' ';
    cout << '\n';
    for (int i = 0; i <= M; i++)
        cout << muls[i] << ' ';
    cout << '\n';
}


void solve() {
    deque<bfs> q;
    bool visited[M + 1] = { };
    
    q.push_back(bfs { 0, 0, 0 });
    visited[0] = true;
    
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        adds[c.i] = c.add, muls[c.i] = c.mul;
        
        if (c.i * 2 <= M && !visited[c.i * 2]) {
            q.push_back(bfs { c.i * 2, c.add, c.mul + 1 });
            visited[c.i * 2] = true;
        }
        
        if (c.i + 1 <= M && !visited[c.i + 1]) {
            q.push_back(bfs { c.i + 1, c.add + 1, c.mul });
            visited[c.i + 1] = true;
        }
    }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    solve();

    int sum_add = 0;
    for (int i = 0; i < n; i++) {
        sum_add += adds[a[i]];
        max_mul = max(max_mul, muls[a[i]]);
    }
    
    cout << sum_add + max_mul;
}