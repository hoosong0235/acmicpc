#include <bits/stdc++.h>
using namespace std;


int n, m, r;
vector<vector<int>> C(300, vector<int>(300)), N(300, vector<int>(300));


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> C[i][j];
    
    for (int k = 0; k < min(n, m) / 2; k++) {
        int num = 2 * ((n - 1 - 2 * k) + (m - 1 - 2 * k));
        for (int l = 0; l < r % num; l++) {
            for (int j = (m - 1) - k; j > k; j--) N[k][j - 1] = C[k][j];
            for (int i = k; i < (n - 1) - k; i++) N[i + 1][k] = C[i][k];
            for (int j = k; j < (m - 1) - k; j++) N[(n - 1) - k][j + 1] = C[(n - 1) - k][j];
            for (int i = (n - 1) - k; i > k; i--) N[i - 1][(m - 1) - k] = C[i][(m - 1) - k];
            
            for (int j = (m - 1) - k; j > k; j--) C[k][j] = N[k][j];
            for (int i = k; i < (n - 1) - k; i++) C[i][k] = N[i][k];
            for (int j = k; j < (m - 1) - k; j++) C[(n - 1) - k][j] = N[(n - 1) - k][j];
            for (int i = (n - 1) - k; i > k; i--) C[i][(m - 1) - k] = N[i][(m - 1) - k];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << C[i][j] << ' ';
        cout << '\n';
    }
    
    return 0;
}