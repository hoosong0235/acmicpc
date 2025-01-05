#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m; cin >> n >> m;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    
    int start = 0, end = 0, sum = a[0], min_num = INT_MAX;
    while (end < n) {
        if (sum < m) {
            sum += a[++end];
            if (end == n && sum == m) min_num = min(min_num, end - start + 1);
        } else {
            min_num = min(min_num, end - start + 1);
            sum -= a[start++];
        }
    }
    cout << (min_num == INT_MAX ? 0 : min_num);
    
    return 0;
}