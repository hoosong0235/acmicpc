#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n, k; cin >> n >> k;
    vector<ll> dp(k + 1); dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        for (int i = v; i <= k; i++) dp[i] = dp[i - v] + dp[i];
    }
    cout << dp[k];
}
