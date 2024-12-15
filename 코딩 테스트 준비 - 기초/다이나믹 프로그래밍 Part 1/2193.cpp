#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<vector<long long>> dp(2, vector<long long>(n + 1, 0));
    dp[1][1] = 1;
    for (int j = 2; j < n + 1; j++) {
        dp[0][j] = dp[0][j - 1] + dp[1][j - 1];
        dp[1][j] = dp[0][j - 1];
    }
    cout << dp[0][n] + dp[1][n];
    
    return 0;
}