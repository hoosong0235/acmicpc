#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<vector<int>> fs(2000);
vector<int> a;


void solve(int depth, int prev) {
    if (depth == 4) {
        cout << 1;
        exit(0);
    }
    
    for (int f: fs[prev]) if (find(a.begin(), a.end(), f) == a.end()) {
        a.push_back(f);
        solve(depth + 1, f);
        a.pop_back();
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int r, c; cin >> r >> c;
        fs[r].push_back(c);
        fs[c].push_back(r);
    }
    
    for (int i = 0; i < n; i++) {
        a.push_back(i);
        solve(0, i);
        a.pop_back();
    }
    
    cout << 0;
    
    return 0;
}