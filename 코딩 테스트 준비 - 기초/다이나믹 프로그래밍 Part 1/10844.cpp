#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<vector<int>> dp(10, vector<int>(n + 1, 0));
    for (int i = 1; i < 10; i++) dp[i][1] = 1;
    for (int j = 2; j < n + 1; j++) for (int i = 0; i < 10; i++) {
        if (i) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % 1000000000;
        if (i != 9) dp[i][j] = (dp[i][j] + dp[i + 1][j - 1]) % 1000000000;
    }
    int sum = 0;
    for (int i = 0; i < 10; i++) sum = (sum + dp[i][n]) % 1000000000;
    cout << sum;
    
    return 0;
}