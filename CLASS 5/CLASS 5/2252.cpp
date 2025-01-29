#include <bits/stdc++.h>
using namespace std;
#define V 32000
#define E 100000


int v, e, a, b;
vector<int> sorted;
// Adjacency list representation
vector<int> adj[V + 1];


// Depth-first search
bool visited[V + 1];
void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto u: adj[s]) dfs(u);
    sorted.push_back(s);
}


int main() {
    cin >> v >> e;
    while (e--) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    // Topological sorting
    for (int i = 1; i <= v; i++) dfs(i);
    reverse(sorted.begin(), sorted.end());
    
    for (auto i: sorted) cout << i << ' ';
}