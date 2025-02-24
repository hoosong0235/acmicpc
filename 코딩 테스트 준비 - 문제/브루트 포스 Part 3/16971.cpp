// 00:37:45
#include <bits/stdc++.h>
using namespace std;
#define N 1000
#define M 1000
#define ll long long


int n, m;
ll a[N][M], rs[N], cs[M];


void debug() {
    for (int i = 0; i < n; i++)
        cout << rs[i] << ' ';
    cout << '\n';
    for (int j = 0; j < m; j++) 
        cout << cs[j] << ' ';
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (j == 0 || j == m - 1)
                rs[i] += a[i][j];
            else
                rs[i] += 2 * a[i][j];
        }
        
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1)
                cs[j] += a[i][j];
            else
                cs[j] += 2 * a[i][j];
        }
        
    // debug();
    
    ll max_r = max(rs[0], rs[n - 1]);
    int max_ri = (max_r == rs[0] ? 0 : n - 1);
    ll min_r = LONG_LONG_MAX;
    int min_ri = -1;
    for (int i = 1; i < n - 1; i++)
        if (rs[i] < min_r) {
            min_r = rs[i];
            min_ri = i;
        }
    
    ll max_c = max(cs[0], cs[m - 1]);
    int max_cj = (max_c == cs[0] ? 0 : m - 1);
    ll min_c = LONG_LONG_MAX;
    int min_cj = -1;
    for (int j = 1; j < m - 1; j++)
        if (cs[j] < min_c) {
            min_c = cs[j];
            min_cj = j;
        }
    
    ll num = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n - 1)
            num += rs[i];
        else
            num += 2 * rs[i];
    }
    ll r_num = 0;   
    if (min_r < max_r) {
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1) {
                if (i == max_ri)
                    r_num += 2 * rs[i];
                else
                    r_num += rs[i];
            } else {
                if (i == min_ri)
                    r_num += rs[i];
                else
                    r_num += 2 * rs[i];
            }
        }
    }
    ll c_num = 0;
    if (min_c < max_c) {
        for (int j = 0; j < m; j++) {
            if (j == 0 || j == m - 1) {
                if (j == max_cj)
                    c_num += 2 * cs[j];
                else
                    c_num += cs[j];
            } else {
                if (j == min_cj)
                    c_num += cs[j];
                else
                    c_num += 2 * cs[j];
            }
        }
    }
    
    ll max_num = num;
    if (min_r < max_r)
        max_num = max(max_num, r_num);
    if (min_c < max_c)
        max_num = max(max_num, c_num);
    cout << max_num;
}