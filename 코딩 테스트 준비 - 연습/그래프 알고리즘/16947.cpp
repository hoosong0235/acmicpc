#include <bits/stdc++.h>
using namespace std;


struct s {
    int d, i;
};


int n;
vector<vector<bool>> graph(3001, vector<bool>(3001, false));

// dfs
bool b = false;
vector<int> parent(3001, 0);
vector<bool> dfs_visited(3001, false);

// cycle
int top, bottom;
vector<int> cycle;

// bfs
deque<s> q;
vector<bool> bfs_visited(3001, false);
vector<int> dist(3001, 0);


void dfs(int ci) {
    for (int j = 1; j <= n; j++) if (graph[ci][j]) {
        if (dfs_visited[j] && parent[ci] != j) {
            b = true, top = j, bottom = ci; return;
        }
        
        if (!dfs_visited[j]) {
            parent[j] = ci;
            dfs_visited[j] = true;
            dfs(j);
            if (b) return;
        }
    }
}


int bfs() {
    while (!q.empty()) {
        s c = q.front(); q.pop_front();
        dist[c.i] = c.d;
        
        for (int j = 1; j <= n; j++) if (graph[c.i][j] && !bfs_visited[j]) {
            bfs_visited[j] = true;
            q.push_back(s{c.d + 1, j});
        }
    }
    
    return 0;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int k = 0; k < n; k++) {
        int i, j; cin >> i >> j;
        graph[i][j] = true;
        graph[j][i] = true;
    }
    
    dfs_visited[1] = true;
    dfs(1);
    for (int i = bottom; i != top; i = parent[i]) cycle.push_back(i); cycle.push_back(top);
    
    for (int i: cycle) {
        bfs_visited[i] = true;
        q.push_back(s{0, i});
    }
    bfs();
    
    for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
}