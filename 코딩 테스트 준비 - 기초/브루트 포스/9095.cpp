#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    if (n == 1) return 1;
    else if (n == 2) return 2;
    else if (n == 3) return 4;
    
    int sum = 0;
    for (int i: {1, 2, 3}) if (n - i > 0) sum += solve(n - i);
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << solve(n) << '\n';
    }
    
    return 0;
}