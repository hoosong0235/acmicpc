#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k; cin >> n >> k;
    vector<vector<int>> dp(n + 1, vector<int>(k));
    for (int i = 0; i < n + 1; i++) dp[i][0] = 1;
    for (int j = 0; j < k; j++) dp[0][j] = 1;
    for (int i = 1; i < n + 1; i++) for (int j = 1; j < k; j++) dp[i][j] = (dp[i - 1][j] + dp[i][j- 1]) % 1000000000;
    cout << dp[n][k - 1];
    return 0;
}