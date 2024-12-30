#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m, r, c, d; cin >> n >> m >> r >> c >> d;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];
    
    int cnt = 0;
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    while (1) {
        if (!visited[r][c]) {
            cnt++;
            visited[r][c] = true;
        }
        
        bool b = false;
        for (pair<int, int> dir: dirs) {
            int nr = r + dir.first, nc = c + dir.second;
            if (0 <= nr && nr <= n - 1 && 0 <= nc && nc <= m - 1)
                if (!v[nr][nc] && !visited[nr][nc]) b = true;
        }
        
        if (b) {
            d = (d + 3) % 4;
            pair<int, int> dir = dirs[d];
            int nr = r + dir.first, nc = c + dir.second;
            if (0 <= nr && nr <= n - 1 && 0 <= nc && nc <= m - 1)
                if (!v[nr][nc] && !visited[nr][nc]) {
                    r = nr; c = nc;
                }
        } else {
            pair<int, int> dir = dirs[(d + 2) % 4];
            int nr = r + dir.first, nc = c + dir.second;
            if (0 <= nr && nr <= n - 1 && 0 <= nc && nc <= m - 1) {
                if (!v[nr][nc]) {
                    r = nr; c = nc;
                } else {
                    break;
                }
            }
        }
    }
    
    cout << cnt;
    return 0;
}