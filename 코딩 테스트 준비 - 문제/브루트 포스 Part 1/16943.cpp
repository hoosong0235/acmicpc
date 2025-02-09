#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 9


ll a, b, n, max_num = -1;
vector<int> digits;
bool visited[N];
vector<int> c;


ll calc() {
    ll ans = 0;
    for (auto i: c) {
        ans *= 10;
        ans += i;
    }
    return ans;
}


void solve() {
    if (c.size() == n) {
        ll num = calc();
        if (pow(10, n - 1) <= num && num < b) max_num = max(max_num, num);
        return;
    }
    
    for (int i = 0; i < n; i++) if (!visited[i]) {
        visited[i] = true;
        c.push_back(digits[i]);
        solve();
        visited[i] = false;
        c.pop_back();
    }
}


int main() {
    cin >> a >> b;
    for (; a; a /= 10) digits.push_back(a % 10);
    n = digits.size();
    solve();
    cout << max_num;
}