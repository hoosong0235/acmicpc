#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000
#define ll long long


int n, k;
int a[MAXN + 1], s[MAXN + 1];
map<int, int> m;


int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) s[i] = (s[i - 1] + a[i]) % k;
    
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!s[i]) cnt++;
        cnt += m[s[i]];
        m[s[i]]++;
    }
    cout << cnt;
}