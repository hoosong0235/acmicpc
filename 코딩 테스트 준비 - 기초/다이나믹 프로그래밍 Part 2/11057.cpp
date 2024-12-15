#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int i, j, k, n; cin >> n;
    vector<vector<int>> dp(10, vector<int>(n + 1, 0));
    for (i = 0; i < 10; i++) dp[i][1] = 1;
    for (j = 2; j < n + 1; j++) for (i = 0; i < 10; i++) for (k = 0; k <= i; k++) {
        dp[i][j] = (dp[i][j] + dp[k][j - 1]) % 10007;
    }
    int ans = 0; for (i = 0; i < 10; i++) ans = (ans + dp[i][n]) % 10007; cout << ans;
    
    return 0;
}