#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int i, j, n; cin >> n;
    vector<int> a(n); for (i = 0; i < n; i++) cin >> a[i];
    vector<int> dp(n); for (i = 0; i < n; i++) dp[i] = a[i];
    for (i = 0; i < n; i++) for (j = 0; j < i; j++) if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + a[i]);
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}