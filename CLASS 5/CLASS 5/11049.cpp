#include <bits/stdc++.h>
using namespace std;
#define N 500
#define ll long long


int n;
ll rs[N], cs[N], dp[N][N];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> rs[i] >> cs[i];
    for (int i = 0; i < n - 1; i++) dp[i][i + 1] = rs[i] * cs[i] * cs[i + 1];
    for (int i = n - 3; i >= 0; i--) for (int j = i + 2; j < n; j++) {
        for (int k = i; k < j; k++) {
            if (!dp[i][j]) dp[i][j] = dp[i][k] + dp[k + 1][j] + rs[i] * cs[k] * cs[j];
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + rs[i] * cs[k] * cs[j]);
        }
    }
    cout << dp[0][n - 1];
}