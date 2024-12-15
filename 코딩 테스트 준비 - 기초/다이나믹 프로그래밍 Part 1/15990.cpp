#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    vector<vector<int>> dp(4, vector<int>(1e5 + 1, 0));
    dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 1;
    dp[2][2] = 1; dp[2][3] = 1;
    dp[3][3] = 1;
    int i = 4;
    while (t--) {
        int n; cin >> n;
        for (; i < n + 1; i++) {
            dp[1][i] = (dp[2][i - 1] + dp[3][i - 1]) % 1000000009;
            dp[2][i] = (dp[1][i - 2] + dp[3][i - 2]) % 1000000009;
            dp[3][i] = (dp[1][i - 3] + dp[2][i - 3]) % 1000000009;
        }
        cout << ((dp[1][n] + dp[2][n]) % 1000000009 + dp[3][n]) % 1000000009 << '\n';
    }
    
    return 0;
}