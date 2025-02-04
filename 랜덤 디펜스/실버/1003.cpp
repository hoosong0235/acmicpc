#include <bits/stdc++.h>
using namespace std;
#define N 40


int t, n;
int dp[2][N + 1];


int main() {
    dp[0][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
        dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
    }
    
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[0][n] << ' ' << dp[1][n] << '\n';
    }
}