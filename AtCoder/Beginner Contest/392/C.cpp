#include <bits/stdc++.h>
using namespace std;
#define N 300000


int n;
int p2b[N + 1], p2s[N + 1], b2p[N + 1];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int p = 1; p <= n; p++) cin >> p2s[p];
    for (int p = 1; p <= n; p++) {
        int b; cin >> b;
        p2b[p] = b, b2p[b] = p;
    }
    
    for (int b = 1; b <= n; b++) cout << p2b[p2s[b2p[b]]] << ' ';
}