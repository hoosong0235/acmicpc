#include <bits/stdc++.h>
using namespace std;
#define MAXN 50
#define MAXM 50


int n, m, t;
int x, d, k;
int a[MAXN][MAXM];
int offset[MAXN];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };


int apply(int i, int j) {
    return ((j + offset[i]) % m + m) % m;
}


void debug() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << a[i][apply(i, j)] << ' ';
        cout << '\n';
    }
    cout << '\n';
}


void rotate() {
    for (int i = x - 1; i < n; i += x) {
        if (d) offset[i] += k;
        else offset[i] -= k;
    }
}


bool check() {
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][apply(i, j)]) for (int dir = 0; dir < 4; dir++) {
        int ni = i + dx[dir], nj = j + dy[dir];
        if (ni == -1 || ni == n) continue;
        if (nj == -1) nj = m - 1;
        else if (nj == m) nj = 0;
        if (a[i][apply(i, j)] == a[ni][apply(ni, nj)]) return true;
    }
    return false;
}


void erase() {
    bool visited[MAXN][MAXM] = {};
    deque<pair<int, int>> q;
    deque<pair<int, int>> r;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][apply(i, j)]) {
        visited[i][j] = true;
        q.push_back({ i, j });
        r.push_back({ i, j });
        while (!q.empty()) {
            pair<int, int> c = q.front(); q.pop_front();
            for (int dir = 0; dir < 4; dir++) {
                int ni = c.first + dx[dir], nj = c.second + dy[dir];
                if (ni == -1 || ni == n) continue;
                if (nj == -1) nj = m - 1;
                else if (nj == m) nj = 0;
                if (a[i][apply(i, j)] == a[ni][apply(ni, nj)] && !visited[ni][nj]) {
                    visited[ni][nj] = true;
                    q.push_back({ ni, nj });
                    r.push_back({ ni, nj });
                }
            }
        }
        if (r.size() > 1) {
            while (!r.empty()) {
                pair<int, int> c = r.front(); r.pop_front();
                a[c.first][apply(c.first, c.second)] = 0;
            }
        } else {
            r.pop_front();
        }
    }
}


void update() {
    double s = 0, t = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j]) s += a[i][j], t++;
    double avg = s / t;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j]) {
        if (a[i][j] > avg) a[i][j]--;
        else if (a[i][j] < avg) a[i][j]++;
    }
}


int calc() {
    int s = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) s += a[i][j];
    return s;
}


int main() {
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    // debug();
    while (t--) {
        cin >> x >> d >> k;
        rotate();
        // debug();
        if (check()) erase();
        else update();
        // debug();
    }
    cout << calc();
}