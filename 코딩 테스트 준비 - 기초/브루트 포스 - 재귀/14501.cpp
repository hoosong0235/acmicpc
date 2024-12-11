#include <bits/stdc++.h>
using namespace std;


int n, max_p = 0;
vector<pair<int, int>> counsels(15);


bool check(int curr_t) {
    for (int i = curr_t; i < n; i++) if (i + counsels[i].first <= n) return true;
    return false;
}


void solve(int curr_t, int curr_p) {
    if (!check(curr_t)) {
        if (max_p < curr_p) max_p = curr_p;
        return;
    }
    
    for (int i = curr_t; i < n; i++) {
        int t = counsels[i].first, p = counsels[i].second;
        if (i + t > n) continue;
        solve(i + t, curr_p + p);
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t, p; cin >> t >> p;
        counsels[i] = {t, p};
    }
    
    solve(0, 0); cout << max_p;
    
    return 0;
}