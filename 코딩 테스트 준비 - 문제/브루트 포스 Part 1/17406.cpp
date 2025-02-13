// 00:30:57
#include <bits/stdc++.h>
using namespace std;
#define N 50
#define M 50


int n, m, k, r, c, s;
int a[N][M], b[N][M], e[N][M];
vector<tuple<int, int, int>> ks;


void debug() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << e[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}


int calc() {
    int min_num = INT_MAX;
    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = 0; j < m; j++) num += b[i][j];
        min_num = min(min_num, num);
    }
    return min_num;
}


void subrotate(int r, int c, int s) {
    memcpy(e, b, sizeof(int) * N * M);
    int rb = r - s, re = r + s, cb = c - s, ce = c + s;
    for (int j = cb; j < c; j++) {
        int d = j - cb;
        for (int i = rb + d; i < re - d; i++)
            e[i][j] = b[i + 1][j];
    }
    for (int i = rb; i < r; i++) {
        int d = i - rb;
        for (int j = ce - d; j > cb + d; j--)
            e[i][j] = b[i][j - 1];
    }
    for (int j = ce; j > c; j--) {
        int d = ce - j;
        for (int i = re - d; i > rb + d; i--)
            e[i][j] = b[i - 1][j];
    }
    for (int i = re; i > r; i--) {
        int d = re - i;
        for (int j = cb + d; j < ce - d; j++)
            e[i][j] = b[i][j + 1];
    }
    e[r][c] = b[r][c];
    // debug();
    memcpy(b, e, sizeof(int) * N * M);
}


void rotate() {
    memcpy(b, a, sizeof(int) * N * M);
    for (auto k: ks) subrotate(get<0>(k), get<1>(k), get<2>(k));
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 0; i < k; i++) {
        cin >> r >> c >> s;
        ks.push_back({ r - 1, c - 1, s });
    }
    
    sort(ks.begin(), ks.end());
    int min_num = INT_MAX;
    do {
        rotate();
        min_num = min(min_num, calc());
    } while (next_permutation(ks.begin(), ks.end()));
    cout << min_num;
}