#include <bits/stdc++.h>
using namespace std;
#define N 1000


int n, m;
bool a[N + 1];


int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int j; cin >> j; a[j] = true;
    }
    
    cout << n - m << '\n';
    for (int i = 1; i <= n; i++) if (!a[i]) cout << i << ' ';
}