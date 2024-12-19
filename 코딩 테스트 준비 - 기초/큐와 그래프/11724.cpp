#include <bits/stdc++.h>
using namespace std;


unordered_map<int, unordered_set<int>> es;
unordered_set<int> visited;


void dfs(int curr) {
    visited.insert(curr);
    for (int next: es[curr]) if (!visited.count(next)) dfs(next);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m, a, b; cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        es[a].insert(b);
        es[b].insert(a);
    }
    
    int cnt = 0;
    while (visited.size() < n) {
        int curr; for (curr = 1; curr <= n; curr++) if (!visited.count(curr)) break;
        dfs(curr);
        cnt++;
    }
    cout << cnt;
    
    return 0;
}