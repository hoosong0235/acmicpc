// 00:33:40
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define N 10'000


int n;
int ts[N + 1];
vector<int> adj[N + 1];
int dp[N + 1];


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t, p; cin >> t >> p;
        ts[i] = t;
        while (p--) {
            int j; cin >> j;
            adj[i].push_back(j);
        }
    }
    
    dp[1] = ts[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = ts[i];
        for (auto j: adj[i])
            dp[i] = max(dp[i], dp[j] + ts[i]);
    }
    
    cout << *max_element(dp + 1, dp + N + 1);
}