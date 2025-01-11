#include <bits/stdc++.h>
using namespace std;
#define MAX 100


struct bfs {
    int d, x, y;
};


int t, h, w, s1x, s1y, s2x, s2y;
char a[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[MAX][MAX];
deque<bfs> q;


void solve(vector<vector<int>> &s) {
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        s[c.x][c.y] = c.d;
        for (int d = 0; d < 4; d++) {
            int nx = c.x + dx[d], ny = c.y + dy[d];
            if (!(0 <= nx && nx < h && 0 <= ny && ny < w)) continue;
            if (a[nx][ny] == '*' || visited[nx][ny]) {
                continue;
            } else if (a[nx][ny] == '.' || a[nx][ny] == '$') {
                visited[nx][ny] = true;
                q.push_front(bfs{c.d, nx, ny});
            } else if (a[nx][ny] == '#') {
                visited[nx][ny] = true;
                q.push_back(bfs{c.d + 1, nx, ny});
            }
        }
    }
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) visited[i][j] = false;
}


int main() {
    cin >> t;
    while (t--) {
        bool b = false;
        cin >> h >> w;
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
            cin >> a[i][j];
            if (a[i][j] == '$') {
                if (!b) s1x = i, s1y = j, b = true;
                else s2x = i, s2y = j;
            }
        }
        
        vector<vector<int>> s1(MAX, vector<int>(MAX, MAX * MAX));
        visited[s1x][s1y] = true;
        q.push_back(bfs{0, s1x, s1y});
        solve(s1);

        vector<vector<int>> s2(MAX, vector<int>(MAX, MAX * MAX));
        visited[s2x][s2y] = true;
        q.push_back(bfs{0, s2x, s2y});
        solve(s2);
        
        vector<vector<int>> s3(MAX, vector<int>(MAX, MAX * MAX));
        for (int i = 0; i < h; i++) {
            for (int j: {0, w - 1}) {
                if (a[i][j] == '.') {
                    visited[i][j] = true;
                    q.push_front(bfs{0, i, j});
                } else if (a[i][j] == '#') {
                    visited[i][j] = true;
                    q.push_back(bfs{1, i, j});
                }
            }
        }
        for (int j = 0; j < w; j++) {
            for (int i: {0, h - 1}) {
                if (a[i][j] == '.') {
                    visited[i][j] = true;
                    q.push_front(bfs{0, i, j});
                } else if (a[i][j] == '#') {
                    visited[i][j] = true;
                    q.push_back(bfs{1, i, j});
                }
            }
        }
        solve(s3);
        
        // for (int i = 0; i < h; i++) { for (int j = 0; j < w; j++) cout << a[i][j] << ' '; cout << '\n'; } cout << '\n';
        // for (int i = 0; i < h; i++) { for (int j = 0; j < w; j++) cout << s1[i][j] << ' '; cout << '\n'; } cout << '\n';
        // for (int i = 0; i < h; i++) { for (int j = 0; j < w; j++) cout << s2[i][j] << ' '; cout << '\n'; } cout << '\n';
        // for (int i = 0; i < h; i++) { for (int j = 0; j < w; j++) cout << s3[i][j] << ' '; cout << '\n'; } cout << '\n';
        
        int min_s1 = INT_MAX, min_s2 = INT_MAX, min_s3 = INT_MAX;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i == 0 || i == h - 1 || j == 0 || j == w - 1) min_s1 = min(min_s1, s1[i][j]);
                if (i == 0 || i == h - 1 || j == 0 || j == w - 1) min_s2 = min(min_s2, s2[i][j]);
                min_s3 = min(min_s3, s1[i][j] + s2[i][j] + s3[i][j] - (a[i][j] == '#' ? 2 : 0));
                // cout << s1[i][j] + s2[i][j] + s3[i][j] - (a[i][j] == '#' ? 2 : 0) << ' ';
            }
            // cout << '\n';
        }
        // cout << '\n';
        cout << min(min_s3, min_s1 + min_s2) << '\n';
    }
}