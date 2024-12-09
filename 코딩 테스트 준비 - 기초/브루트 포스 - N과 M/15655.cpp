#include <bits/stdc++.h>
using namespace std;


void solve(vector<int> is, int m, list<int> selecteds) {
    if (!m) {
        for (int selected: selecteds) cout << selected << ' ';
        cout << '\n';
        return;
    }
    
    for (int i: is) {
        if (
            find(selecteds.begin(), selecteds.end(), i) == selecteds.end() &&
            *max_element(selecteds.begin(), selecteds.end()) < i
        ) {
            selecteds.push_back(i);
            solve(is, m - 1, selecteds);
            selecteds.pop_back();
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<int> is(n); while (n--) cin >> is[n];
    sort(is.begin(), is.end());
    list<int> selecteds;
    solve(is, m, selecteds);
    
    return 0;
}