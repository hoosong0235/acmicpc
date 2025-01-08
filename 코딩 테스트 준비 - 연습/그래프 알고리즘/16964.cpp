#include <bits/stdc++.h>
using namespace std;


int n, cnt = 1;
set<int> a[100001];
set<int> b[100001];
int ans[100001];
bool visited[100001];


void solve(int i) {
    set<int> tmp;
    for (int j: a[i]) if (!visited[j]) tmp.insert(j);
    b[i] = tmp;
    // cout << "solve(" << i << ") b[" << i << "]: "; for (int j: b[i]) cout << j << ' '; cout << '\n';
    while (!b[i].empty()) {
        if (!b[i].count(ans[cnt])) {
            cout << '0'; exit(0);
        } else {
            b[i].erase(ans[cnt]);
            cnt++;
            visited[ans[cnt - 1]] = true;
            solve(ans[cnt - 1]);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    int x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        a[x].insert(y); a[y].insert(x);
    }
    for (int i = 1; i <= n; i++) cin >> ans[i];
    
    if (ans[1] != 1) {
        cout << '0'; return 0;
    }
    cnt++;
    visited[ans[cnt - 1]] = true;
    solve(ans[cnt - 1]);
    cout << '1';
}