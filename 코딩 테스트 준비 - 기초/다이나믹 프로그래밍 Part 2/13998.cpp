#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int i, n; cin >> n;
    vector<int> a(n); for (i = 0; i < n; i++) cin >> a[i];
    vector<int> incr(n); incr[0] = max(0, a[0]); for (i = 1; i < n; i++) incr[i] = max(0, incr[i - 1] + a[i]);
    vector<int> decr(n); decr[n - 1] = max(0, a[n - 1]); for (i = n - 2; i >= 0; i--) decr[i] = max(0, decr[i + 1] + a[i]);
    int max_num = *max_element(incr.begin(), incr.end());
    max_num = max(max_num, max(decr[1], incr[n - 2]));
    for (i = 1; i < n - 1; i++) max_num = max(max_num, incr[i - 1] + decr[i + 1]);
    cout << (max_num ? max_num : *max_element(a.begin(), a.end()));
    
    return 0;
}