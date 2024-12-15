#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> dp(n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
        int min_num = dp[i - 1] + 1;
        for (int j = 1; (int) pow(j, 2) <= i; j++) min_num = min(min_num, dp[i - (int) pow(j, 2)] + 1);
        dp[i] = min_num;
    }
    cout << dp[n];
    return 0;
}