#include <iostream>
using namespace std;
#define MAXN 1024


int n, m, w, x, y, c, x1, y1, x2, y2;
int tree[2 * MAXN][2 * MAXN];


void debug() {
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) cout << tree[i][j] << ' ';
        cout << '\n';
    }
}


int subquery(int x, int y1, int y2) {
    y1 += n, y2 += n;
    int s = 0;
    while (y1 <= y2) {
        if (y1 % 2 == 1) s += tree[x][y1++];
        if (y2 % 2 == 0) s += tree[x][y2--];
        y1 /= 2, y2 /= 2;
    }
    return s;
}


int query(int x1, int y1, int x2, int y2) {
    x1 += n, x2 += n;
    int s = 0;
    while (x1 <= x2) {
        if (x1 % 2 == 1) s += subquery(x1++, y1, y2);
        if (x2 % 2 == 0) s += subquery(x2--, y1, y2);
        x1 /= 2, x2 /= 2;
    }
    return s;
}


void subupdate(int x, int y, int d) {
    y += n;
    tree[x][y] += d;
    for (y /= 2; y >= 1; y /= 2) tree[x][y] = tree[x][2 * y] + tree[x][2 * y + 1];
}


void update(int x, int y, int c) {
    int d = c - tree[x + n][y + n];
    x += n;
    subupdate(x, y, d);
    for (x /= 2; x >= 1; x /= 2) subupdate(x, y, d);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = n; i < 2 * n; i++) for (int j = n; j < 2 * n; j++) cin >> tree[i][j];
    for (int i = n; i < 2 * n; i++) for (int j = n - 1; j >= 1; j--) tree[i][j] = tree[i][2 * j] + tree[i][2 * j + 1];
    for (int i = n - 1; i >= 1; i--) for (int j = 1; j < 2 * n; j++) tree[i][j] = tree[2 * i][j] + tree[2 * i + 1][j];
    while (m--) {
        cin >> w;
        if (w == 0) {
            cin >> x >> y >> c;
            update(x - 1, y - 1, c);
        } else {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << query(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << '\n';
        }
    }
}