#include <bits/stdc++.h>
using namespace std;
#define MAX 100


int n = 3, m = 3, cnt = 0;
int r, c, k;
int a[MAX + 1][MAX + 1];


void debug() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << a[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}


void rop(int i) {
    map<int, int> num2cnt;
    for (int j = 1; j <= m; j++) if (a[i][j]) num2cnt[a[i][j]]++;
    map<int, set<int>> cnt2nums;
    for (auto &[num, cnt]: num2cnt) cnt2nums[cnt].insert(num);
    int j = 1;
    for (auto &[cnt, nums]: cnt2nums) {
        for (int num: nums) {
            a[i][j++] = num;
            a[i][j++] = cnt;
            m = max(m, j - 1);
            if (100 < j) return;
        }
    }
    for (; j <= m; j++) a[i][j] = 0;
}


void cop(int j) {
    map<int, int> num2cnt;
    for (int i = 1; i <= n; i++) if (a[i][j]) num2cnt[a[i][j]]++;
    map<int, set<int>> cnt2nums;
    for (auto &[num, cnt]: num2cnt) cnt2nums[cnt].insert(num);
    int i = 1;
    for (auto &[cnt, nums]: cnt2nums) {
        for (int num: nums) {
            a[i++][j] = num;
            a[i++][j] = cnt;
            n = max(n, i - 1);
            if (100 < i) return;
        }
    }
    for (; i <= n; i++) a[i][j] = 0;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> r >> c >> k;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
    // debug();
    if (a[r][c] == k) { cout << 0; return 0; }
    while (cnt++ < 100) {
        if (n >= m) for (int i = 1; i <= n; i++) rop(i);
        else for (int j = 1; j <= m; j++) cop(j);
        // debug();
        if (a[r][c] == k) break;
    }
    cout << (cnt <= 100 ? cnt : -1);
}