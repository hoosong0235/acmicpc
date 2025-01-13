#include <bits/stdc++.h>
using namespace std;
#define MAX 2000


int n, m, s, e;
int a[MAX + 1];
bool dp[MAX + 1][MAX + 1];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= n; i++) dp[i][i] = true;
    for (int i = n; i >= 1; i--) for (int j = i + 1; j <= n; j++) if (a[i] == a[j] && (i + 1 == j || dp[i + 1][j - 1])) dp[i][j] = true;
    
    cin >> m;
    while (m--) {
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
    
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
}