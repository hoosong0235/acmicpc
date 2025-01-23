#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int r, c, t;
int x1, x2;
int a[MAX][MAX];
int b[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


void debug() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << a[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}


void contaminate() {
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) if (a[i][j]) {
        if (a[i][j] != -1) {
            b[i][j] += a[i][j];
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (!(0 <= ni && ni < r && 0 <= nj && nj < c)) continue;
                if (a[ni][nj] == -1) continue;
                b[ni][nj] += a[i][j] / 5;
                b[i][j] -= a[i][j] / 5;
            }
        } else {
            b[i][j] = a[i][j];
        }
    }
    memcpy(a, b, sizeof(int) * MAX * MAX);
    memset(b, 0, sizeof(int) * MAX * MAX);
}


void purify() {
    for (int i = x1 - 1; i > 0; i--) a[i][0] = a[i - 1][0];
    for (int j = 0; j < c - 1; j++) a[0][j] = a[0][j + 1];
    for (int i = 0; i < x1; i++) a[i][c - 1] = a[i + 1][c - 1];
    for (int j = c - 1; j > 1; j--) a[x1][j] = a[x1][j - 1];
    a[x1][1] = 0;
    
    for (int i = x2 + 1; i < r - 1; i++) a[i][0] = a[i + 1][0];
    for (int j = 0; j < c - 1; j++) a[r - 1][j] = a[r - 1][j + 1];
    for (int i = r - 1; i > x2; i--) a[i][c - 1] = a[i - 1][c - 1];
    for (int j = c - 1; j > 1; j--) a[x2][j] = a[x2][j - 1];
    a[x2][1] = 0;
}


int calc() {
    int sum = 0;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) if (a[i][j] != -1) sum += a[i][j];
    return sum;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
        cin >> a[i][j];
        if (a[i][j] == -1) {
            if (x1) x2 = i;
            else x1 = i;
        }
    }
    
    while (t--) {
        contaminate();
        //debug();
        purify();
        //debug();
    }
    cout << calc();
}