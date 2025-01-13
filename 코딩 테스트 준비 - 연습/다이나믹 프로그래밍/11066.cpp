#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        vector<int> a(k);
        for (int i = 0; i < k; i++) cin >> a[i];
        vector<int> s(k);
        s[0] = a[0]; for (int i = 1; i < k; i++) s[i] = s[i - 1] + a[i];
        vector<vector<int>> dp(k, vector<int>(k));
        for (int i = 0; i < k - 1; i++) dp[i][i + 1] = a[i] + a[i + 1];
        for (int i = k - 2; i >= 0; i--) for (int j = i + 2; j < k; j++) {
            dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
            for (int m = i + 1; m < j - 1; m++) dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
            dp[i][j] += s[j] - (i < 0 ? 0 : s[i - 1]);
        }
        // for (int i = 0; i < k; i++) { for (int j = 0; j < k; j++) cout << dp[i][j] << ' '; cout << '\n'; }
        cout << dp[0][k - 1] << '\n';
    }
}