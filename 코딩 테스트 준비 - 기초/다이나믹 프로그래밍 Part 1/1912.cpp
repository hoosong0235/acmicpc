#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> a(n + 1, 0); for (int i = 1; i < n + 1; i++) cin >> a[i];
    vector<int> s(n + 1, 0); for (int i = 1; i < n + 1; i++) s[i] = s[i - 1] + a[i];
    int j = 0;
    vector<int> dp(n + 1, 0); for (int i = 1; i < n + 1; i++) {
        dp[i] = max(dp[i - 1], s[i] - s[j]);
        if (s[i] - s[j] < 0) j = i;
    }
    cout << (dp[n] ? dp[n] : *max_element(a.begin() + 1, a.end()));
    return 0;
}