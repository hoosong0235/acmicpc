#include <bits/stdc++.h>
using namespace std;


int n, max_num = INT_MIN;
vector<int> w(10);


void solve(int num) {
    if (n == 2) {
        max_num = max(max_num, num); return;
    }
    
    for (int i = 1; i < n - 1; i++) {
        int m = w[i - 1] * w[i + 1], r = w[i];
        
        for (int j = i + 1; j < n; j++) w[j - 1] = w[j]; n--;
        solve(num + m);
        n++; for (int j = n - 1; j >= i + 1; j--) w[j] = w[j - 1]; w[i] = r;
    }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> w[i];
    
    solve(0);
    cout << max_num;
    
    return 0;
}