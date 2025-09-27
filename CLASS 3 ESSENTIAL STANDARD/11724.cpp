#include <bits/stdc++.h>
using namespace std;

#define N 1'000
#define M 1'000'000

int n, m, cnt = 0;
vector<int> adj[N + 1];
bool visited[N + 1];

void dfs(int c) {
    visited[c] = true;
    for (auto n: adj[c])
        if (!visited[n])
            dfs(n);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            cnt++, dfs(i);
    
    cout << cnt;
}