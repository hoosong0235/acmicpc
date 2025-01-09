#include <bits/stdc++.h>
using namespace std;


int n, m, dnt = 0;
int arr[1001][1001];
pair<int, int> brr[1001][1001];
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool visited[1001][1001];
deque<pair<int, int>> q;
deque<pair<int, int>> r;


void bfs(int x, int y) {
    int cnt = 1;
    visited[x][y] = true;
    q.push_back({x, y});
    while (!q.empty()) {
        pair<int, int> c = q.front(); q.pop_front(); r.push_back(c);
        for (int d = 0; d < 4; d++) {
            int nx = c.first + dx[d], ny = c.second + dy[d];
            if (!(1 <= nx && nx <= n && 1 <= ny && ny <= m)) continue;
            if (!arr[nx][ny] && !visited[nx][ny]) {
                cnt++;
                visited[nx][ny] = true;
                q.push_back({nx, ny});
            }
        }
    }
    dnt++;
    while (!r.empty()) {
        pair<int, int> c = r.front(); r.pop_front();
        brr[c.first][c.second] = {cnt, dnt};
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 1; j <= m; j++) arr[i][j] = s[j - 1] - '0';
    }
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (!arr[i][j] && !visited[i][j]) bfs(i, j);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            set<int> dnts;
            if (!arr[i][j]) {
                cout << 0;
            } else {
                int sum = 0;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (!(1 <= ni && ni <= n && 1 <= nj && nj <= m)) continue;
                    int cnt = brr[ni][nj].first, dnt = brr[ni][nj].second;
                    if (!dnts.count(dnt)) {
                        sum += cnt;
                        dnts.insert(dnt);
                    }
                }
                cout << (sum + 1) % 10;
            }
        }
        cout << '\n';
    }
}