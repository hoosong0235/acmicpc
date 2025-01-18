#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
#define MAXK 100000


int n, k;
int weights[MAXN + 1], vs[MAXN + 1], dp[MAXK + 1];


int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> weights[i] >> vs[i];
    
    for (int i = 1; i <= n; i++)
        for (int j = k; j >= 1; j--)
            if (j - weights[i] >= 0)
                dp[j] = max(dp[j], dp[j - weights[i]] + vs[i]);
                
    cout << dp[k];
}