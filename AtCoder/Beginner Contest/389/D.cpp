#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll r;


bool check(ll x, ll y) {
    return (x + 0.5) * (x + 0.5) + (y + 0.5) * (y + 0.5) <= r * r;
}


int main() {
    cin >> r;
    ll cnt = 0;
    int cy = r;
    for (int x = 1; x < r; x++) {
        for (int y = cy; !check(x, y); y--, cy--) { }
        cnt += cy;
    }
    cout << cnt * 4 + (r - 1) * 4 + 1;
}