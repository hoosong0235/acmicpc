#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
#define ll long long


int t, n;
vector<ll> dp(MAX + 1);


int main() {
    for (int i = 0; i <= MAX; i++) dp[i] = 1;
    for (int i = 2; i <= MAX; i++) dp[i] = dp[i - 2] + dp[i];
    for (int i = 3; i <= MAX; i++) dp[i] = dp[i - 3] + dp[i];
    
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}
