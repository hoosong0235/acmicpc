#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> a(n + 1); for (int i = 1; i < n + 1; i ++) cin >> a[i];
    vector<int> dp(n + 1, 1);
    for (int i = 1; i < n + 1; i++) for (int j = 1; j < i; j++) if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
    cout << *max_element(dp.begin(), dp.end());
    
    return 0;
}