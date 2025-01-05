#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m; cin >> n >> m;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    
    int start = 0, end = 0, sum = a[0], cnt = 0;
    while (end < n) {
        if (sum < m) {
            sum += a[++end];
            if (end == n && sum == m) cnt++;
        } else if (sum == m) {
            cnt++;
            sum -= a[start++];
        } else {
            sum -= a[start++];
        }
    }
    cout << cnt;
    
    return 0;
}