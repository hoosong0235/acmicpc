#include <bits/stdc++.h>
using namespace std;
#define N 1000
#define M 100


int n, m, k, a, b;
// Adjacency list representation
set<int> adj[N + 1];


// Topological sort
vector<int> sorted;
bool visited1[N + 1], visited2[N + 1];
void dfs(int s) {
    if (visited2[s]) { cout << 0; exit(0); }
    if (visited1[s]) return;
    visited1[s] = true;
    visited2[s] = true;
    for (auto u: adj[s]) dfs(u);
    visited2[s] = false;
    sorted.push_back(s);
}


int main() {
    // Input
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> k;
        cin >> a;
        for (int j = 1; j < k; j++) {
            cin >> b;
            adj[a].insert(b);
            a = b;
        }
    }
    
    for (int s = 1; s <= n; s++) dfs(s);
    reverse(sorted.begin(), sorted.end());
    for (auto s: sorted) cout << s << '\n';
}