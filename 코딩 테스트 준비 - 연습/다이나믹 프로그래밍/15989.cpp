#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000


int t, n;
int dp[MAXN + 1];


int main() {
    dp[0] = 1;
    for (int i = 1; i <= 3; i++)
        for (int j = i; j <= MAXN; j++)
            dp[j] += dp[j - i];
    
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}