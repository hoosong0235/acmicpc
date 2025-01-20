#include <bits/stdc++.h>
using namespace std;
#define MAXN 500000


int n, m, j;
int ns[MAXN];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> ns[i];
    sort(ns, ns + n);
    cin >> m;
    while (m--) {
        cin >> j;
        cout << upper_bound(ns, ns + n, j) - lower_bound(ns, ns + n, j) << ' ';
    }
}