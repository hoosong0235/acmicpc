#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000
#define MAXM 1000000


int n, m;
int a[MAXN];
int b[MAXM];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    
    int ap = 0, bp = 0;
    while (ap != n || bp != m) {
        if (ap == n) cout << b[bp++] << ' ';
        else if (bp == m) cout << a[ap++] << ' ';
        else if (a[ap] > b[bp]) cout << b[bp++] << ' ';
        else cout << a[ap++] << ' ';
    }
}