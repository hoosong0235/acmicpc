#include <bits/stdc++.h>
using namespace std;
#define MAXN 200000
#define MAXX 1000000000
#define ll long long


int n, c;
ll xs[MAXN];


bool check(int d) {
    int ci = 0, ni;
    for (int i = 0; i < c - 1; i++) {
        ni = lower_bound(xs, xs + n, xs[ci] + d) - xs;
        if (ni == n) return false;
        ci = ni;
    }
    return true;
}


ll bs(ll lo, ll hi) {
    ll mid = (lo + hi) / 2;
    if (lo > hi) return mid;
    if (check(mid)) return bs(mid + 1, hi);
    else return bs(lo, mid - 1);
}


int main() {
    cin >> n >> c;
    ll max_num = LONG_LONG_MIN;
    for (int i = 0; i < n; i++) {
        cin >> xs[i]; max_num = max(max_num, xs[i]);
    }
    sort(xs, xs + n);
    cout << bs(0, max_num);
}