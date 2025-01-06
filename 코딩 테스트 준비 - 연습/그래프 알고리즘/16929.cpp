#include <bits/stdc++.h>
using namespace std;


int n, m, px, py;
char pc;
vector<vector<char>> v(50, vector<char>(50));
vector<vector<bool>> visited(50, vector<bool>(50, false));
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


void solve(int depth, int x, int y) {
    // cout << "solve(" << depth << ", " << x << ", " << y << ")\n";
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) continue;
        
        if (depth >= 4 && nx == px && ny == py) {
            cout << "Yes"; exit(0);
        }
        
        if (v[nx][ny] != pc) continue;
        if (visited[nx][ny]) continue;
        
        // cout << nx << ny << '\n';
        visited[nx][ny] = true;
        solve(depth + 1, nx, ny);
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) v[i][j] = s[j];
    }
    
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        px = i, py = j, pc = v[i][j];
        for (int x = 0; x < n; x++) for (int y = 0; y < m; y++) visited[x][y] = false;
        visited[i][j] = true;
        solve(1, i, j);
    }
    
    cout << "No";
}