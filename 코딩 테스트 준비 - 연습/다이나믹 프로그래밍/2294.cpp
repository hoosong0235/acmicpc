#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
#define MAXK 10000


int n, k;
int dp[MAXK + 1];


int main() {
    dp[0] = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int v; cin >> v;
        for (int j = v; j <= k; j++) if (dp[j - v]) {
            if (dp[j]) dp[j] = min(dp[j], dp[j - v] + 1);
            else dp[j] = dp[j - v] + 1;
        }
    }
    cout << (dp[k] ? dp[k] - 1 : -1);
}