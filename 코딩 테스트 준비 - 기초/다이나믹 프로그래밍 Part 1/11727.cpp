#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> dp(n + 1, 1);
    for (int i = 2; i < n + 1; i++) dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
    cout << dp[n] % 10007;
    
    return 0;
}