#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int i, j, n; cin >> n;
    if (!n) {
        cout << 1; return 0;
    } else if (n % 2) {
        cout << 0; return 0;
    } else {
        n /= 2;
    }
    vector<int> dp(n + 1, 0);
    dp[1] = 3;
    for (i = 2; i < n + 1; i++) {
        dp[i] += dp[i - 1] * 3;
        for (j = 1; j < i - 1; j++) dp[i] += dp[j] * 2;
        dp[i] += 2;
    }
    cout << dp[n];
    
    return 0;
}