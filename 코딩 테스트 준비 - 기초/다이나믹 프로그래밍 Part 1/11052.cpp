#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> p(n + 1); for (int i = 1; i < n + 1; i++) cin >> p[i];
    vector<int> dp(n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
        int max_num = INT_MIN;
        for (int j = 1; j < i + 1; j++) max_num = max(max_num, dp[i - j] + p[j]);
        dp[i] = max_num;
    }
    cout << dp[n];
    
    return 0;
}