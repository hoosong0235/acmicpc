#include <bits/stdc++.h>
using namespace std;


int n;
map<int, set<int>> es;
set<int> visited_dfs;
deque<int> queue_bfs;
set<int> visited_bfs;


void dfs(int prev) {
    cout << prev << ' ';
    for (int i: es[prev]) if (!visited_dfs.count(i)) {
        visited_dfs.insert(i);
        dfs(i);
    }
}

void bfs(int start) {
    cout << start << ' ';
    queue_bfs.push_back(start);
    visited_bfs.insert(start);
    while (!queue_bfs.empty()) {
        int prev = queue_bfs.front();
        queue_bfs.pop_front();
        for (int i: es[prev]) if (!visited_bfs.count(i)) {
            cout << i << ' ';
            queue_bfs.push_back(i);
            visited_bfs.insert(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int a, b, m, v; cin >> n >> m >> v;
    while (m--) {
        cin >> a >> b;
        es[a].insert(b);
        es[b].insert(a);
    }
    
    visited_dfs.insert(v);
    dfs(v);
    cout << '\n';
    bfs(v);
    
    return 0;
}