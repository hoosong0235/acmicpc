#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll cnt = 0;
int n, q, a, p, nh;
map<int, int> p2h;
map<int, set<int>> h2p;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        h2p[i].insert(i);
        p2h[i] = i;
    }
    while (q--) {
        cin >> a;
        if (a == 1) {
            cin >> p >> nh;
                
            int ch = p2h[p];
            h2p[ch].erase(p);
            if (h2p[ch].size() == 1) cnt--;
            
            if (h2p[nh].size() == 1) cnt++;
            h2p[nh].insert(p);
            
            p2h[p] = nh;
                
        } else {
            
            
            cout << cnt << '\n';
            // for (pair<int, set<int>> p: h2p) {
            //     cout << p.first << ' ';
            //     for (int e: p.second) cout << e << ' ';
            //     cout << '\n';
            // }
            // cout << '\n';
        }
    }
}