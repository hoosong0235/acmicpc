#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 20


int n, i;
ll dp[MAX + 1], ndp[MAX + 1];


int main() {
    cin >> n;
    cin >> i;
    dp[i]++;
    while (n-- > 2) {
        cin >> i;
        for (int j = 0; j <= MAX; j++) if (dp[j]) {
            if (0 <= j - i) ndp[j - i] += dp[j];
            if (j + i <= 20) ndp[j + i] += dp[j];
        }
        memcpy(dp, ndp, sizeof(ll) * (MAX + 1));
        memset(ndp, 0, sizeof(ll) * (MAX + 1));
        // for (int i = 0; i <= MAX; i++) cout << dp[i] << ' '; cout << '\n';
    }
    cin >> i;
    cout << dp[i];
}