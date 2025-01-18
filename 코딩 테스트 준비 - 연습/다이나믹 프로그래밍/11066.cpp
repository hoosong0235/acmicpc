#include <bits/stdc++.h>
using namespace std;
#define MAXK 500


int main() {
    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        int a[MAXK + 1] = { 0 }, s[MAXK + 1] = { 0 };
        for (int i = 1; i <= k; i++) cin >> a[i];
        for (int i = 1; i <= k; i++) s[i] = s[i - 1] + a[i];
        
        int dp[MAXK + 1][MAXK + 1] = { 0 };
        for (int i = 1; i < k; i++) dp[i][i + 1] = a[i] + a[i + 1];
        
        for (int i = k - 2; i >= 1; i--) {
            for (int j = i + 2; j <= k; j++) {
                int min_num = INT_MAX;
                for (int m = i; m < j; m++)
                    min_num = min(min_num, dp[i][m] + dp[m + 1][j]);
                dp[i][j] = min_num + (s[j] - s[i - 1]);
            }
        }
        
        // for (int i = 0; i <= k; i++) {
        //     for (int j = 0; j <= k; j++) cout << dp[i][j] << ' ';
        //     cout << '\n';
        // }
        
        cout << dp[1][k] << '\n';
    }
}