#include <bits/stdc++.h>
using namespace std;


int n;
list<int> a;


void solve(int depth) {
    if (depth == n) {
        for (int ea: a) cout << ea << ' ';
        cout << '\n';
        return;
    }
    
    for (int i=1; i<=n; i++) if (find(a.begin(), a.end(), i) == a.end()) {
        a.push_back(i);
        solve(depth + 1);
        a.pop_back();
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    solve(0);
    
    return 0;
}