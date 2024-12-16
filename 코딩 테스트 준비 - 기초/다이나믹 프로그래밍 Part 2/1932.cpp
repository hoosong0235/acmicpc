#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int i, j, n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (i = 0; i < n; i++) for (j = 0; j <= i; j++) cin >> a[i][j];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = a[0][0];
    for (i = 1; i < n; i++) for (j = 0; j <= i; j++) dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end());
    
    return 0;
}