#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
#define MAXK 10000


int main() {
    int n, k; cin >> n >> k;
    int dp[MAXN + 1][MAXK + 1];
    for (int i = 1; i <= n; i++) {
        int v; cin >> v;
        for (int j = 1; j <= k; j++) {
            if (j == v) {
                dp[i][j] = 1;
            } else if (j > v && dp[i][j - v]) {
                dp[i][j] = dp[i - 1][j] ? min(dp[i - 1][j], dp[i][j - v] + 1) : dp[i][j - v] + 1;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= k; j++) cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    cout << (dp[n][k] ? dp[n][k] : -1);
}