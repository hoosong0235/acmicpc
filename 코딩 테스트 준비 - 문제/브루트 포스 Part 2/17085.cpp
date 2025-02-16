// 00:29:55
#include <bits/stdc++.h>
using namespace std;
#define N 15
#define M 15


int n, m;
char a[N][M];
bool visited[N][M];


int calc(int x, int y) { // returns size if exists, else -1.
    for (int k = 0; ; k++) {
        if (!(0 <= x - k && x + k < n && 0 <= y - k && y + k < m)) return k - 1;
        if (visited[x - k][y] || a[x - k][y] != '#') return k - 1;
        if (visited[x][y - k] || a[x][y - k] != '#') return k - 1;
        if (visited[x + k][y] || a[x + k][y] != '#') return k - 1;
        if (visited[x][y + k] || a[x][y + k] != '#') return k - 1;
    }
}


void visit(int x, int y, int d, bool rev=false) {
    for (int k = 0; k <= d; k++) {
        visited[x - k][y] = !rev;
        visited[x][y - k] = !rev;
        visited[x + k][y] = !rev;
        visited[x][y + k] = !rev;
    }
}


int cvrt(int d) {
    return 4 * d + 1;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) a[i][j] = s[j];
    }
    
    int max_num = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        int d = calc(i, j);
        if (d != -1) {
            for (int dd = 0; dd <= d; dd++) {
                visit(i, j, dd);
                for (int ii = 0; ii < n; ii++) for (int jj = 0; jj < m; jj++) {
                    int num = cvrt(dd) * cvrt(calc(ii, jj));
                    max_num = max(max_num, num);
                }
                visit(i, j, dd, true);
            }
        }
    }
    cout << max_num;
}