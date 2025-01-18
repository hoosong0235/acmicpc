#include <bits/stdc++.h>
using namespace std;
#define MAXN 50
#define MAXM 1000


int n, s, m;
int ds[MAXN + 1], dp[MAXM + 1];


int main() {
    cin >> n >> s >> m;
    for (int i = 1; i <= n; i++) cin >> ds[i];
    
    dp[s]++;
    for (int i = 1; i <= n; i++) {
        set<int> njs;
        for (int j = 0; j <= m; j++)
            if (dp[j]) {
                if (0 <= j - ds[i]) njs.insert(j - ds[i]);
                if (j + ds[i] <= m) njs.insert(j + ds[i]);
                dp[j]--;
            }
        if (njs.empty()) { cout << -1; return 0; }
        for (int nj: njs) dp[nj]++;
    }
    
    for (int i = m; i >= 0; i--)
        if (dp[i]) { cout << i; return 0; }
}