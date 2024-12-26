#include <bits/stdc++.h>
using namespace std;


struct bfs {
    int x;
    int y;
    int d;
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m; cin >> m >> n;
    deque<bfs> q; q.push_back(bfs{0, 0, 0});
    vector<vector<bool>> v(n, vector<bool>(m, false)); v[0][0] = true;
    vector<vector<int>> M(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) M[i][j] = s[j] - '0';
    }
    
    vector<pair<int, int>> nexts = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while (!q.empty()) {
        bfs curr = q.front(); q.pop_front();
        int cx = curr.x, cy = curr.y, cd = curr.d;
        
        if (cx == n - 1 && cy == m - 1) {
            cout << cd; break;
        }
        
        for (pair<int, int> next: nexts) {
            int nx = cx + next.first, ny = cy + next.second;
            if (0 <= nx && nx < n && 0 <= ny && ny < m && !v[nx][ny]) {
                v[nx][ny] = true;
                if (!M[nx][ny]) q.push_front(bfs{nx, ny, cd});
                else q.push_back(bfs{nx, ny, cd + 1});
            }
        }
    }
    
    return 0;
}