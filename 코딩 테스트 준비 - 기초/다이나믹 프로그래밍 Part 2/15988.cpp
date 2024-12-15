#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int i, n, t; cin >> t;
    vector<int> dp(1000001, 0); dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for (i = 4; i < 1000001; i++) dp[i] = (((dp[i - 1] + dp[i - 2]) % 1000000009) + dp[i - 3]) % 1000000009;
    while (t--) {
        cin >> n; cout << dp[n] << '\n';
    }
    
    return 0;
}