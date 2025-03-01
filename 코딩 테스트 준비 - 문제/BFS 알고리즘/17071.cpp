// 00:35:25
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define N 500'000
#define K 500'000


int n, k;
deque<pair<int, int>> q;
bool visited[2][N + 1];


int calc(int t) {
    return k + t * (t + 1) / 2;
}


int main() {
    cin >> n >> k;
    q.push_back({ n, 0 });
    visited[0 % 2][n] = true;
    while (!q.empty()) {
        pair<int, int> c = q.front(); q.pop_front();
        int cn = c.first, ct = c.second;
        int ck = calc(ct), nt = ct + 1;
        if (ck > K) break;
        if (visited[ct % 2][ck]) { cout << ct; return 0; }
        for (auto nn: { cn - 1, cn + 1, cn * 2 })
            if (0 <= nn && nn <= N && !visited[nt % 2][nn]) {
                q.push_back({ nn, nt });
                visited[nt % 2][nn] = true;
            }
    }
    cout << -1;
}