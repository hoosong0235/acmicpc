#include <bits/stdc++.h>
using namespace std;

#define N 100

int n, m;
vector<int> adj[N + 1];
bool visited[N + 1];

int calc() {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (visited[i])
            cnt++;
    return cnt;
}

void solve(int c) {
    if (visited[c])
        return;
    visited[c] = true;
    for (int n: adj[c])
        solve(n);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    solve(1);
    
    cout << calc() - 1;
}