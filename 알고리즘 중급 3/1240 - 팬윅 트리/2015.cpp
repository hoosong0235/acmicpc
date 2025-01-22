#include <bits/stdc++.h>
using namespace std;
#define MAXN 200000
#define ll long long


int n, k;
int a[MAXN + 1], s[MAXN + 1];
map<ll, int> m;


int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == k) cnt++;
        cnt += m[s[i] - k];
        m[s[i]]++;
    }
    cout << cnt;
}