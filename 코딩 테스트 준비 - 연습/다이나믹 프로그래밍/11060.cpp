#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


int n, a[MAX], dp[MAX];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = MAX;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) if (dp[i] != MAX) {
        for (int j = i + 1; j <= i + a[i]; j++) {
            dp[j] = min(dp[i] + 1, dp[j]);
        }
    }
    // for (int i = 0; i < n; i++) cout << dp[i] << ' ';
    cout << (dp[n - 1] != MAX ? dp[n - 1] : -1);
}