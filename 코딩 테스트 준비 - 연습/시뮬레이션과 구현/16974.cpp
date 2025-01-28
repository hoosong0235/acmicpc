#include <bits/stdc++.h>
using namespace std;
#define MAX 50
#define ll long long


int n;
ll x;
ll bs[MAX + 1];
ll ps[MAX + 1];


ll solve(ll cn, ll cx) {
    if (cx == 1) return 0;
    else if (cx < 1 + bs[cn - 1]) return solve(cn - 1, cx - 1);
    else if (cx == 1 + bs[cn - 1]) return ps[cn - 1];
    else if (cx == 2 + bs[cn - 1]) return ps[cn - 1] + 1;
    else if (cx < 2 + bs[cn - 1] * 2) return ps[cn - 1] + 1 + solve(cn - 1, cx - 2 - bs[cn - 1]);
    else if (cx == 2 + bs[cn - 1] * 2) return ps[cn - 1] * 2 + 1;
    else if (cx == bs[cn]) return ps[cn];
    else return 0;
}


int main() {
    cin >> n >> x;
    ps[0] = 1, bs[0] = 1;
    for (int i = 1; i <= MAX; i++) ps[i] = ps[i - 1] * 2 + 1, bs[i] = bs[i - 1] * 2 + 3;
    // for (int i = 0; i <= MAX; i++) cout << ps[i] << ' '; cout << '\n';
    // for (int i = 0; i <= MAX; i++) cout << bs[i] << ' ';
    cout << solve(n, x);
}