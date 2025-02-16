// 00:13:58
#include <bits/stdc++.h>
using namespace std;
#define N 32
#define ll long long


int n, a[N + 1][N + 1];
ll dp[N + 1][N + 1][3];


void debug() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << dp[i][j][0] << dp[i][j][1] << dp[i][j][2] << ' ';
        cout << '\n';
    }
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
    
    a[1][2] = 1, dp[1][2][0] = 1;
    for (int i = 1; i <= n; i++) for (int j = 2; j <= n; j++) if (!a[i][j]) {
        dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
        if (!a[i - 1][j] && !a[i][j - 1])
            dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
        dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];
    }
    // debug();
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
}