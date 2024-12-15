#include <bits/stdc++.h>
using namespace std;


vector<int> a(1001);
vector<int> dp(1001, 1);
vector<int> prevs(1001, 0);


void print(int i) {
    if (!i) return;
    print(prevs[i]);
    cout << a[i] << ' ';
}

int main() {
    int n; cin >> n;
    for (int i = 1; i < n + 1; i ++) cin >> a[i];
    for (int i = 1; i < n + 1; i++) for (int j = 1; j < i; j++) if (a[j] < a[i]) if (dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        prevs[i] = j;
    }
    
    cout << *max_element(dp.begin(), dp.end()) << '\n';
    int i = max_element(dp.begin(), dp.end()) - dp.begin();
    if (i) print(i); else cout << a[1];
    
    return 0;
}