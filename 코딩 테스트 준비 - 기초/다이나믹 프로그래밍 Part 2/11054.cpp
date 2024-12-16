#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int i, j, k, n; cin >> n;
    vector<int> a(n); for (i = 0; i < n; i++) cin >> a[i];
    vector<int> incr(n, 1); for (i = 0; i < n; i++) for (j = 0; j < i; j++) if (a[i] > a[j]) incr[i] = max(incr[i], incr[j] + 1);
    vector<int> decr(n, 1); for (i = n - 1; i >= 0; i--) for (j = i + 1; j < n; j++) if (a[i] > a[j]) decr[i] = max(decr[i], decr[j] + 1);
    vector<int> dp(n, 1); for (i = 0; i < n; i++) dp[i] = incr[i] + decr[i] - 1;
    cout << *max_element(dp.begin(), dp.end());
    
    return 0;
}