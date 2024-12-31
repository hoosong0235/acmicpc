#include <bits/stdc++.h>
using namespace std;


int n;
vector<int> a(11);
vector<int> ops(4);
int max_num = INT_MIN, min_num = INT_MAX;


void solve(int d, int num) {
    if (d == n - 1) {
        max_num = max(max_num, num);
        min_num = min(min_num, num);
        return;
    }
    
    for (int i = 0; i < 4; i++) if (ops[i]) {
        ops[i]--;
        if (i == 0) solve(d + 1, num + a[d + 1]);
        else if (i == 1) solve(d + 1, num - a[d + 1]);
        else if (i == 2) solve(d + 1, num * a[d + 1]);
        else solve(d + 1, num / a[d + 1]);
        ops[i]++;
    }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < 4; i++) cin >> ops[i];
    solve(0, a[0]);
    cout << max_num << '\n' << min_num;
    return 0;
}