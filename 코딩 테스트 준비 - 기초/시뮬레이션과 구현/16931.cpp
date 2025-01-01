#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];
    
    int cnt = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (v[i][j]) cnt += 2;
    for (int i = 0; i < n; i++) {
        int curr = 0;
        for (int j = 0; j < m; j++) {
            if (v[i][j] > curr) cnt += (v[i][j] - curr);
            curr = v[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int curr = 0;
        for (int j = m - 1; j >= 0; j--) {
            if (v[i][j] > curr) cnt += (v[i][j] - curr);
            curr = v[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (v[i][j] > curr) cnt += (v[i][j] - curr);
            curr = v[i][j];
        }
    }
    for (int j = 0; j < m; j++) {
        int curr = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (v[i][j] > curr) cnt += (v[i][j] - curr);
            curr = v[i][j];
        }
    }
    cout << cnt;
    
    return 0;
}