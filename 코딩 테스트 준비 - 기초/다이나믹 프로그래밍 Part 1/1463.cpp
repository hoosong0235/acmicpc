#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> dp(n + 1, 0);
    for (int i = 2; i < n + 1; i++) {
        int min_num = dp[i - 1] + 1;
        if (!(i % 2)) min_num = min(min_num, dp[i / 2] + 1);
        if (!(i % 3)) min_num = min(min_num, dp[i / 3] + 1);
        dp[i] = min_num;
    }
    cout << dp[n];
    
    return 0;
}