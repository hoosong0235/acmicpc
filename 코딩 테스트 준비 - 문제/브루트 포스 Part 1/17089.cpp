// 00:21:48
#include <bits/stdc++.h>
using namespace std;
#define N 4'000
#define M 4'000


int n, m, a, b;
set<int> adj[N + 1];


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        adj[a].insert(b), adj[b].insert(a);
    }
    
    int min_num = INT_MAX;
    for (int i = 1; i <= n; i++)
        for (int j: adj[i])
            for (int k: adj[j]) if (i != k && adj[i].find(k) != adj[i].end()) {
                int num = adj[i].size() + adj[j].size() + adj[k].size() - 6;
                min_num = min(min_num, num);
            }
    cout << (min_num != INT_MAX ? min_num : -1);
}