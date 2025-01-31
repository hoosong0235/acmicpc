#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    vector<ll> dp;
    dp.push_back(1);
    for (ll i = 1; dp[i - 1] * i > 0; i++) dp.push_back(dp[i - 1] * i);
    
    ll x; cin >> x;
    for (ll i = 1; i < dp.size(); i++) if (dp[i] == x) cout << i;
}