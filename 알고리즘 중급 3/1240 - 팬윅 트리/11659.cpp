#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000


int n, m, a, b;
int tree[2 * MAXN];


int query(int a, int b) {
    a += n, b += n;
    int s = 0;
    while (a <= b) {
        if (a % 2 == 1) s += tree[a++];
        if (b % 2 == 0) s += tree[b--];
        a /= 2, b /= 2;
    }
    return s;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = n; i < 2 * n; i++) cin >> tree[i];
    for (int i = n - 1; i >= 1; i--) tree[i] = tree[2 * i] + tree[2 * i + 1];
    while (m--) {
        cin >> a >> b;
        cout << query(a - 1, b - 1) << '\n';
    }
}