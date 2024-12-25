#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<vector<bool>> visited(2001, vector<bool>(2001, false)); visited[0] = { true }; visited[1][0] = true;
    deque<tuple<int, int, int>> q; q.push_back({1, 0, 0});
    int s; cin >> s;
    
    while (!q.empty()) {
        tuple<int, int, int> curr = q.front(); q.pop_front();
        int p = get<0>(curr), c = get<1>(curr), d = get<2>(curr);

        if (p == s) {
            cout << d; break;
        }
        
        if (!visited[p][p]) {
            visited[p][p] = true;
            q.push_back({p, p, d + 1});
        }
        if (p + c <= 2000 && !visited[p + c][c]) {
            visited[p + c][c] = true;
            q.push_back({p + c, c, d + 1});
        }
        if (p && !visited[p - 1][c]) {
            visited[p - 1][c] = true;
            q.push_back({p - 1, c, d + 1});
        }
    }
    
    return 0;
}