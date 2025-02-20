// 00:42:42
#include <bits/stdc++.h>
using namespace std;
#define N 10
#define H 30
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


int n, m, h, a, b, min_num = INT_MAX;
bool adj[N + 1][H + 1];


bool subcheck(int i) {
    int ci = i;
    int j = 0;
    while (++j <= h) {
        if (adj[i - 1][j]) i--;
        else if (adj[i][j]) i++;
    }
    return i == ci;
}


bool check() {
    for (int i = 1; i <= n; i++)
        if (!subcheck(i)) return false;
    return true;
}


void solve(int d, int ci, int cj) {
    if (d > 3) return;
    if (check()) { min_num = min(min_num, d); return; }
    
    for (int i = ci; i < n; i++)
        for (int j = (i == ci ? cj : 1); j <= h; j++)
            if (!adj[i - 1][j] && !adj[i][j] && !adj[i + 1][j]) {
                adj[i][j] = true;
                solve(d + 1, (j == h ? i + 1 : i), (j == h ? 1 : j + 1));
                adj[i][j] = false;
            }
}


void solve() {
    deque<tuple<int, int, int>> q;
    q.push_back({ 0, 1, 1 });
}


int main() {
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[b][a] = true;
    }
    
    solve(0, 1, 1);
    cout << (min_num != INT_MAX ? min_num : -1);
}