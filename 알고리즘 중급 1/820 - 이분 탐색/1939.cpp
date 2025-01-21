#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000
#define MAXC 1000000000
#define map unordered_map


int n, m, a, b, c, i1, i2;
map<int, map<int, int>> g;


bool check(int bsw) {
    bool visited[MAXN + 1] = { false };
    deque<int> q;
    visited[i1] = true;
    q.push_back(i1);
    while(!q.empty()) {
        int i = q.front(); q.pop_front();
        if (i == i2) return true;
        for (auto &[j, w]: g[i]) {
            if (w >= bsw && !visited[j]) {
                visited[j] = true;
                q.push_back(j);
            }
        }
        
    }
    return false;
}


int bs(int lo, int hi) {
    int mid = (lo + hi) / 2;
    if (lo > hi) return mid;
    if (check(mid)) return bs(mid + 1, hi);
    else return bs(lo, mid - 1);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a][b] = max(g[a][b], c);
        g[b][a] = max(g[b][a], c);
    }
    cin >> i1 >> i2;
    cout << bs(1, MAXC);
}