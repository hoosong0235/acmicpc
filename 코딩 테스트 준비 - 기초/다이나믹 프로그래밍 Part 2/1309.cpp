#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int i, j, n; cin >> n;
    vector<vector<int>> dp(3, vector<int>(n + 1, 0));
    for (i = 0; i < 3; i++) dp[i][1] = 1;
    for (j = 2; j < n + 1; j++) {
        dp[0][j] = (dp[1][j - 1] + dp[2][j - 1]) % 9901;
        dp[1][j] = (dp[0][j - 1] + dp[2][j - 1]) % 9901;
        dp[2][j] = ((dp[0][j - 1] + dp[1][j - 1]) % 9901 + dp[2][j - 1]) % 9901;
    }
    cout << ((dp[0][n] + dp[1][n]) % 9901 + dp[2][n]) % 9901;
    
    return 0;
}