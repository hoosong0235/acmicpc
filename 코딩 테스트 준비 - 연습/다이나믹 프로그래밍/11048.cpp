#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000
#define MAXM 1000


int n, m;
int a[MAXN + 1][MAXM + 1], dp[MAXN + 1][MAXM + 1];


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
    cout << dp[n][m];
}