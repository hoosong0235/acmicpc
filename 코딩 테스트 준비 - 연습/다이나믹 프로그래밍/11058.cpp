#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100


int n;
ll dp[MAXN + 1];


int main() {
    for (int i = 0; i <= MAXN; i++) {
        dp[i + 1] = max(dp[i + 1], dp[i] + 1);
        dp[i + 3] = max(dp[i + 3], dp[i] * 2);
        dp[i + 4] = max(dp[i + 4], dp[i] * 3);
        dp[i + 5] = max(dp[i + 5], dp[i] * 4);
    }

    cin >> n;
    cout << dp[n];
}