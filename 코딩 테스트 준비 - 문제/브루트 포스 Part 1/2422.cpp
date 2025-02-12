#include <bits/stdc++.h>
using namespace std;
#define N 200
#define M 100'00


int n, m, a, b, cnt = 0;
bool ms[M + 1][M + 1];
vector<int> is;


bool check(int j) {
    for (int i: is) if (ms[i][j]) return false; return true;
}


void debug() {
    for (int i: is) cout << i << ' '; cout << '\n';
}


void solve(int depth, int ci) {
    if (depth == 3) {
        // debug();
        cnt++; return;
    }
    
    for (int i = ci; i <= n; i++) if (check(i)) {
        is.push_back(i);
        solve(depth + 1, i + 1);
        is.pop_back();
    }
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        ms[a][b] = true, ms[b][a] = true;
    }
    
    solve(0, 1);
    cout << cnt;
}