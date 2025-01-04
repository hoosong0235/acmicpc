#include <bits/stdc++.h>
using namespace std;


int n, k, max_num = INT_MIN;
vector<int> ss(50, 0);
int cs = 0;


int calc() {
    int cnt = 0;
    for (int i = 0; i < n; i++) if (ss[i] == (ss[i] & cs)) cnt++;
    return cnt;
}


void solve(int d, int ii) {
    if (d == k) {
        max_num = max(max_num, calc()); return;
    }
    
    for (int i = ii; i < 26; i++) if (~cs & 1 << i) {
        cs |= 1 << i;
        solve(d + 1, i + 1);
        cs &= ~(1 << i);
    }
}


int main() {
    cin >> n >> k;
    
    if (k < 5) {
        cout << 0;
    } else {
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (char c: s) ss[i] |= 1 << (c - 'a');
        }
        for (int i: {0, 2, 8, 13, 19}) cs |= 1 << i;
        
        solve(5, 0); cout << max_num;
    }
    
    return 0;
}