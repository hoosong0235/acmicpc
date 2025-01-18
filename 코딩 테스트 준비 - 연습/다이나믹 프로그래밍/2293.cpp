#include <bits/stdc++.h>
using namespace std;
#define MAXK 10000


int n, k;
int dp[MAXK + 1];


int main() {
    cin >> n >> k;
    dp[0] = 1;
    while (n--) {
        int v; cin >> v;
        for (int i = v; i <= k; i++) dp[i] += dp[i - v];
    }
    cout << dp[k];
}