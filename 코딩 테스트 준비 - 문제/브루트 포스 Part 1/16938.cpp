#include <bits/stdc++.h>
using namespace std;
#define N 15
#define ll long long


int n, l, r, x;
int a[N + 1];
vector<int> c;
ll cnt;


bool check() {
    int min_num = *min_element(c.begin(), c.end()),
        max_num = *max_element(c.begin(), c.end()),
        sum_num = accumulate(c.begin(), c.end(), 0);
    return x <= max_num - min_num && l <= sum_num && sum_num <= r;
}


void solve(int ci) {
    if (!c.empty() && check()) cnt++;
    
    for (int i = ci; i <= n; i++) {
        c.push_back(a[i]);
        solve(i + 1);
        c.pop_back();
    }
}


int main() {
    cin >> n >> l >> r >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    solve(1);
    cout << cnt;
}