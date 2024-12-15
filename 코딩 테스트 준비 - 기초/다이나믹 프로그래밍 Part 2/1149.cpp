#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int i, j, n; cin >> n;
    vector<vector<int>> price(3, vector<int>(n + 1));
    for (j = 1; j < n + 1; j++) for (i = 0; i < 3; i++) cin >> price[i][j];
    vector<vector<int>> dp(3, vector<int>(n + 1, 0));
    for (i = 0; i < 3; i++) dp[i][1] = price[i][1];
    for (j = 2; j < n + 1; j++) {
        dp[0][j] = min(dp[1][j - 1], dp[2][j - 1]) + price[0][j];
        dp[1][j] = min(dp[0][j - 1], dp[2][j - 1]) + price[1][j];
        dp[2][j] = min(dp[0][j - 1], dp[1][j - 1]) + price[2][j];
    }
    cout << min({dp[0][n], dp[1][n], dp[2][n]});
    
    return 0;
}