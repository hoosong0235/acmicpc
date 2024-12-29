#include <bits/stdc++.h>
using namespace std;


int idx(int x) {
    return (x % 8 + 8) % 8;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    vector<vector<int>> v(t, vector<int>(8));
    for (int i = 0; i < t; i++) {
        string s; cin >> s;
        for (int j = 0; j < 8; j++) v[i][j] = s[j] - '0';
    }
    
    int k; cin >> k;
    vector<int> p(t, 0);
    while (k--) {
        int n, d; cin >> n >> d; n--;
        
        // left
        int l;
        for (l = n; l > 0; l--) {
            if (v[l][idx(p[l] + 6)] != v[l - 1][idx(p[l - 1] + 2)]) {
                continue;
            } else {
                break;
            }
        }
        
        int dl = d;
        for (int i = n; i > l && i > 0; i--) {
            p[i - 1] += dl;
            dl *= -1;
        }
        
        // right
        int r;
        for (r = n; r < t - 1; r++) {
            if (v[r][idx(p[r] + 2)] != v[r + 1][idx(p[r + 1] + 6)]) {
                continue;
            } else {
                break;
            }
        }
        
        int dr = d;
        for (int i = n; i < r && i < t - 1; i++) {
            p[i + 1] += dr;
            dr *= -1;
        }
        
        // self
        p[n] -= d;
        
        // for (int i = 0; i < t; i++) cout << p[i] << ' ';
        // cout << '\n';
    }

    int cnt = 0;
    for (int i = 0; i < t; i++) if (v[i][idx(p[i])]) cnt++;
    cout << cnt;
    
    return 0;
}