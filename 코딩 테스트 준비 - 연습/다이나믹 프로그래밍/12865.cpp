#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
#define MAXK 100000


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> ws(MAXN + 1), vs(MAXN + 1);
    vector<vector<int>> dp(MAXN + 1, vector<int>(MAXK + 1));
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> ws[i] >> vs[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (ws[i] <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - ws[i]] + vs[i]);
            else dp[i][j] = dp[i - 1][j];
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }
    cout << dp[n][k];
}