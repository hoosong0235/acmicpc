#include <bits/stdc++.h>
using namespace std;
#define MAXN 10


int n, m, k, x, y, z;
int a[MAXN][MAXN];
deque<int> b[MAXN][MAXN];
int c[MAXN][MAXN];
int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {1, 0, -1, 1, 0, -1, 1, -1};


void debug() {
    return;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ':';
            for (int age: b[i][j]) cout << age << ',';
            cout << '\t';
        }
        cout << '\n';
    }
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        a[i][j] = 5;
        cin >> c[i][j];
    }
    while (m--) {
        cin >> x >> y >> z;
        b[x - 1][y - 1].push_back(z);
    }
    
    while (k--) {
        debug();
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (!b[i][j].empty()) {
            sort(b[i][j].begin(), b[i][j].end());
            int size = b[i][j].size();
            int sum = 0;
            while (size--) {
                int age = b[i][j].front(); b[i][j].pop_front();
                if (a[i][j] >= age) {
                    a[i][j] -= age;
                    b[i][j].push_back(age + 1);
                } else {
                    sum += age / 2;
                }
            }
            a[i][j] += sum;
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            for (int age: b[i][j]) if (age % 5 == 0) for (int d = 0; d < 8; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (!(0 <= ni && ni < n && 0 <= nj && nj < n)) continue;
                b[ni][nj].push_back(1);
            }
            a[i][j] += c[i][j];
        }
    }
    debug();
    
    int cnt = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cnt += b[i][j].size();
    cout << cnt;
}