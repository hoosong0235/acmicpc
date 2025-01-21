#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000


int n, m, a, b, c;
int tree[2 * MAXN];


int query(int a, int b) {
    a += n, b += n;
    int ans = INT_MAX;
    while (a <= b) {
        if (a % 2 == 1) ans = min(ans, tree[a++]);
        if (b % 2 == 0) ans = min(ans, tree[b--]);
        a /= 2, b /= 2;
    }
    return ans;
}


void update(int k, int x) {
    k += n;
    tree[k] = x;
    for (k /= 2; k >= 1; k /= 2) tree[k] = min(tree[2 * k], tree[2 * k + 1]);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = n; i < 2 * n; i++) cin >> tree[i];
    for (int i = n - 1; i >= 1; i--) tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 1) update(b - 1, c);
        else cout << query(b - 1, c - 1) << '\n';
    }
}