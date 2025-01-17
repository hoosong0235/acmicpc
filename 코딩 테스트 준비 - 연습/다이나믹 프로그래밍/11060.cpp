#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000


int n;
int a[MAXN], dp[MAXN];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    dp[0] = 1;
    for (int i = 0; i < n; i++) if (dp[i]) {
        for (int d = 1; d <= a[i]; d++) {
            if (dp[i + d]) dp[i + d] = min(dp[i + d], dp[i] + 1);
            else dp[i + d] = dp[i] + 1;
        }
    }
    cout << (dp[n - 1] ? dp[n - 1] - 1 : -1);
}