#include <bits/stdc++.h>
using namespace std;


void solve(int n, int m, list<int> selecteds) {
    if (!m) {
        for (int selected: selecteds) cout << selected << ' ';
        cout << '\n';
        return;
    }
    
    for (int i=1; i<=n; i++) {
        if (
            *max_element(selecteds.begin(), selecteds.end()) < i &&
            find(selecteds.begin(), selecteds.end(), i) == selecteds.end()
        ) {
            selecteds.push_back(i);
            solve(n, m - 1, selecteds);
            selecteds.pop_back();
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    list<int> selecteds;
    solve(n, m, selecteds);
    
    return 0;
}