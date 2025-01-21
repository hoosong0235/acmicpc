#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000
#define ll long long


int n, m, k, a, b;
ll c;
ll tree[2 * MAXN];


ll query(int a, int b) {
    a += n, b += n;
    ll s = 0;
    while (a <= b) {
        if (a % 2 == 1) s += tree[a++];
        if (b % 2 == 0) s += tree[b--];
        a /= 2, b /= 2;
    }
    return s;
}


void update(int k, ll x) {
    k += n;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2) tree[k] = tree[2 * k] + tree[2 * k + 1];
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = n; i < 2 * n; i++) cin >> tree[i];
    for (int i = n - 1; i >= 1; i--) tree[i] = tree[2 * i] + tree[2 * i + 1];
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) update(b - 1, c);
        else cout << query(b - 1, c - 1) << '\n';
    }
}