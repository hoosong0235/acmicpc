#include <bits/stdc++.h>
using namespace std;
#define N 100
#define M 100

int n, m;
char a[N][M];
bool visited[N][M];
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };
vector<tuple<int, int, int>> ans;


int calc(int i, int j) {
    int num = 0;
    bool flag = false, loop = true;
    while (loop) {
        num++;
        for (int d = 0; d < 5; d++) {
            int ni = i + num * dx[d], nj = j + num * dy[d];
            if (!(0 <= ni && ni < n && 0 <= nj && nj < m)) { loop = false; break; }
            if (a[ni][nj] == '.') { loop = false; break; }
            if (a[ni][nj] == '*' && !visited[ni][nj]) flag = true;
        }
    }
    return flag ? --num : 0;
}


void solve(int i, int j, int s) {
    for (int num = 1; num <= s; num++) {
        for (int d = 0; d < 5; d++) {
            int ni = i + num * dx[d], nj = j + num * dy[d];
            visited[ni][nj] = true;
        }
    }
}


bool check() {
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (a[i][j] == '*' && !visited[i][j]) return false;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) a[i][j] = s[j];
    }
    
    int cnt = 0;
    for (int i = 1; i < n - 1; i++) for (int j = 1; j < m - 1; j++) {
        if (int s = calc(i, j)) {
            solve(i, j, s);
            cnt++, ans.push_back({ i, j, s });
        }
    }
    
    if (!check()) { cout << -1; return 0; }
    
    cout << cnt << '\n';
    for (auto t: ans) cout << get<0>(t) + 1 << ' ' << get<1>(t) + 1 << ' ' << get<2>(t) << '\n';
}