#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<vector<int>> C(300, vector<int>(300)), N(300, vector<int>(300));


void f() {
    int n2 = n / 2, m2 = m / 2;
    for (int i = 0; i < n2; i++) for (int j = i; j < (m - i) - 1; j++) N[i][j] = C[i][j + 1];
    for (int i = n2; i < n; i++) for (int j = m - (n - i); j > (n - i) - 1; j--) N[i][j] = C[i][j - 1];
    for (int j = 0; j < m2; j++) for (int i = j + 1; i < (n - j); i++) N[i][j] = C[i - 1][j];
    for (int j = m2; j < m; j++) for (int i = n - (m - j) - 1; i > (m - j) - 2; i--) N[i][j] = C[i + 1][j];
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int r; cin >> n >> m >> r;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> C[i][j];
    for (int i = 0; i < r; i++) {
        f();
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) C[i][j] = N[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << C[i][j] << ' ';
        cout << '\n';
    }
    
    return 0;
}