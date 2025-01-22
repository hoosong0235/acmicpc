#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        cout << (l == 1 && r == 1 ? 1 : r - l) << '\n';
    }
}