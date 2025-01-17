#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000
#define MAXM 1000000


int n, m, s, e;
int a[MAXN + 1];
bool dp[MAXN + 1][MAXN + 1];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= n; i++) dp[i][i] = true;
    for (int i = 1; i < n; i++) dp[i][i + 1] = a[i] == a[i + 1];
    for (int i = n - 2; i >= 1; i--) {
        for (int j = i + 2; j <= n; j++) {
            dp[i][j] = dp[i + 1][j - 1] && a[i] == a[j];
        }
    }
    
    cin >> m;
    while (m--) {
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
}