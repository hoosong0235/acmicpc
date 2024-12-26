#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k; cin >> n >> k;
    vector<bool> visited(100001, false); visited[n] = true;
    deque<pair<int, int>> q; q.push_back({n, 0});
    
    while (!q.empty()) {
        pair<int, int> curr = q.front(); q.pop_front();
        int x = curr.first, d = curr.second;
        
        if (x == k) {
            cout << d; break;
        }
        
        if (x <= 50000 && !visited[x * 2]) {
            q.push_back({x * 2, d});
            visited[x * 2] = true;
        }
        if (x && !visited[x - 1]) {
            q.push_back({x - 1, d + 1});
            visited[x - 1] = true;
        }
        if (x != 100000 && !visited[x + 1]) {
            q.push_back({x + 1, d + 1});
            visited[x + 1] = true;
        }
    }
    
    return 0;
}