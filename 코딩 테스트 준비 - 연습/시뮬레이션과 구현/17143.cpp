#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
#define MAXM 10000


struct shark {
    int s, d, z;
};


int sum = 0;
int r, c, m;
int i1, i2, i3, i4, i5;
shark cs[MAXN + 1][MAXN + 1], ns[MAXN + 1][MAXN + 1];
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };


int rev(int d) {
    switch (d) {
        case 1: return 2;
        case 2: return 1;
        case 3: return 4;
        case 4: return 3;
        default: return 0;
    }
}


void debug() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            shark s = cs[i][j];
            cout << s.s << s.d << s.z << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}


void fish(int j) {
    for (int i = 1; i <= r; i++) if (cs[i][j].z) {
        sum += cs[i][j].z;
        cs[i][j] = shark { 0, 0, 0 };
        break;
    }
}


void move(int i, int j) { // O(s) -> O(n);
    if (!cs[i][j].z) return;
    shark s = cs[i][j];
    int mod = s.d == 1 || s.d == 2 ? s.s % (2 * r - 2) : s.s % (2 * c - 2);
    for (int k = 0; k < mod; k++) {
        int ni = i + dx[s.d], nj = j + dy[s.d];
        if (!(1 <= ni && ni <= r && 1 <= nj && nj <= c)) {
            s.d = rev(s.d);
            ni = i + dx[s.d], nj = j + dy[s.d];
        }
        i = ni, j = nj;
    }
    if (ns[i][j].z < s.z) ns[i][j] = s;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> r >> c >> m;
    while (m--) {
        cin >> i1 >> i2 >> i3 >> i4 >> i5;
        cs[i1][i2] = shark { i3, i4, i5 };
    }
    
    for (int fishking = 1; fishking <= c; fishking++) { // O(n^4) -> O(n^4)
        fish(fishking);
        // debug();
        for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) move(i, j); // O(n^2*s) -> O(n^3)
        for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) {
            cs[i][j] = ns[i][j];
            ns[i][j] = shark { 0, 0, 0 };
        }
        // debug();
    }
    cout << sum;
}