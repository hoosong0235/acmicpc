#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, s, m; cin >> n >> s >> m;
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    
    dp[0][s] = true;
    for (int i = 1; i <= n; i++) {
        int d; cin >> d;
        for (int j = 0; j <= m; j++) if (dp[i - 1][j]) {
            if (j - d >= 0) dp[i][j - d] = true;
            if (j + d <= m) dp[i][j + d] = true;
        }
    }
    
    int max_num = -1;
    for (int j = 0; j <= m; j++) if (dp[n][j]) max_num = max(max_num, j);
    cout << max_num;
    
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
}