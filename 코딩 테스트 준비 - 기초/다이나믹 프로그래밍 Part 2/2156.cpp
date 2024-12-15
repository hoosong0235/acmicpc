#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int i, j, n; cin >> n;
    vector<int> a(n + 1, 0);
    for (i = 1; i < n + 1; i++) cin >> a[i];
    if (n == 1) {
        cout << a[n]; return 0;
    }
    vector<vector<int>> dp(4, vector<int>(n + 1, 0));
    dp[1][2] = a[2];
    dp[2][2] = a[1] + a[2];
    dp[3][2] = a[1];
    for (j = 3; j < n + 1; j++) {
        dp[0][j] = dp[3][j - 1];
        dp[1][j] = a[j] + max(dp[0][j - 1], dp[3][j - 1]);
        dp[2][j] = a[j] + dp[1][j - 1];
        dp[3][j] = max(dp[1][j - 1], dp[2][j - 1]);
    }
    cout << max({dp[0][n], dp[1][n], dp[2][n], dp[3][n]});
    
    return 0;
}