#include <bits/stdc++.h>
using namespace std;
#define MAX 5000
#define ll long long


int t, l;
ll dp[MAX + 1];


int main() {
    dp[0] = 1;
    for (int i = 1; i <= MAX; i++)
        for (int j = 0; j <= i - 1; j++)
            dp[i] = (dp[i] + dp[j] * dp[i - j - 1]) % 1000000007;
    
    cin >> t;
    while (t--) {
        cin >> l;
        cout << (l % 2 ? 0 : dp[l / 2]) << '\n';
    }
}