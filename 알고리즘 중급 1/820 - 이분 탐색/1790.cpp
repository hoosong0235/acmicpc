#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll n, k; cin >> n >> k;
    
    ll lo = 1, lonum = 1, hi = 10, hinum = 10, digit = 1;
    while (!(lo <= k && k < hi)) {
        lo = hi;
        hi += (digit + 1) * 9 * pow(10, digit);
        lonum = hinum;
        hinum += 9 * pow(10, digit);
        digit++;
    }
    
    ll num = lonum + (k - lo) / digit, index = (k - lo) % digit;
    if (num <= n) cout << to_string(num)[index];
    else cout << -1;
}