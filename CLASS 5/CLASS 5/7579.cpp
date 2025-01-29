#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
#define MAXC 100
#define INF 99999999

int n, m, min_c = INT_MAX;
int ms[MAXN], cs[MAXN];
vector<vector<int>> dp(MAXN + 1, vector<int>(MAXC * MAXN + 1, INF));


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> ms[i];
    for (int i = 0; i < n; i++) cin >> cs[i];
    
    dp[0][0] = 0;
    dp[0][cs[0]] = ms[0];
    if (dp[0][cs[0]] >= m) min_c = min(min_c, cs[0]);
    for (int i = 1; i < n; i++) for (int j = 0; j < n * MAXC + 1; j++) if (dp[i - 1][j] != INF) {
        if (dp[i][j] == INF) dp[i][j] = dp[i - 1][j];
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        if (dp[i][j + cs[i]] == INF) dp[i][j + cs[i]] = dp[i - 1][j] + ms[i];
        dp[i][j + cs[i]] = max(dp[i][j + cs[i]], dp[i - 1][j] + ms[i]);
        if (dp[i][j + cs[i]] >= m) min_c = min(min_c, j + cs[i]);
    }
    
    cout << min_c;
}