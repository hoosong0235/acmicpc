#include <bits/stdc++.h>
using namespace std;


int n;
set<int> a[100001];
bool visited[100001];
deque<set<int>> q;
int ans[100001];


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
    visited[1] = true;
    q.push_back(a[1]);
    set<int> s;
    for (int i = 2; i <= n; i++) {
        if (s.empty()) {
            s = q.front(); q.pop_front();
            // cout << "s = "; for (int j: s) cout << j << ' '; cout << ";\n";
        }
        if (!s.count(ans[i])) {
            cout << '0'; return 0;
        } else {
            // cout << "s.erase(" << ans[i] << ")\n";
            s.erase(ans[i]);
            visited[ans[i]] = true;
            set<int> tmp;
            for (int j: a[ans[i]]) if (!visited[j]) tmp.insert(j);
            if (!tmp.empty()) q.push_back(tmp);
        }
    }
    cout << '1';
}