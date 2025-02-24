// 00:17:10
#include <bits/stdc++.h>
using namespace std;
#define N 500
#define M 500
#define L 'L'
#define T 'U'
#define R 'R'
#define B 'D'


int n, m;
char a[N][M];
deque<pair<int, int>> q;
bool visited[N][M];
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
const char dd[4] = { B, T, R, L };


int calc() {
    int num = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (visited[i][j])
                num++;
    return num;
}


bool check(int x, int y) {
    return (
        (x == 0 && a[x][y] == T) ||
        (x == n - 1 && a[x][y] == B) ||
        (y == 0 && a[x][y] == L) ||
        (y == m - 1 && a[x][y] == R)
    );
}


void solve(int x, int y) {
    assert(x == 0 || x == n - 1 || y == 0 || y == m - 1);
    
    if (!visited[x][y] && check(x, y)) {
        q.push_back({ x, y });
        visited[x][y] = true;
    }
    
    while (!q.empty()) {
        pair<int, int> c = q.front(); q.pop_front();
        for (int d = 0; d < 4; d++) {
            int px = c.first + dx[d], py = c.second + dy[d];
            if (!(0 <= px && px < n && 0 <= py && py < m))
                continue;
            if (!visited[px][py] && dd[d] == a[px][py]) {
                q.push_back({ px, py });
                visited[px][py] = true;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
            a[i][j] = s[j];
    }
    
    for (int i = 0; i < n; i++)
        solve(i, 0), solve(i, m - 1);
    for (int j = 0; j < m; j++)
        solve(0, j), solve(n - 1, j);
        
    cout << calc();
}