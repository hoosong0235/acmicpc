#include <bits/stdc++.h>
using namespace std;
#define N 10
#define M 19


bool debug = false;
int n, m;
int max_num1 = INT_MIN, max_num2 = INT_MIN;
int a[N][N];
// int d1[M];
// int d2[M];
vector<int> d1(M, -1);
vector<int> d2(M, -1);


// 0, 2, 4, ...
void solve1(int i, int num) {
    if (debug) {
        cout << "solve1(" << i << ", " << num << ")\t";
        for (int j = 0; j < m; j++) cout << d1[j] << ' '; 
        cout << '\n';
    }
    if (i >= m) {
        max_num1 = max(max_num1, num);
        return;
    }
    int minj = i < n ? (n - 1) - i : (n - 1) - ((m - 1) - i);
    int maxj = i < n ? (n - 1) + i : (n - 1) + ((m - 1) - i);
    for (int j = minj; j <= maxj; j += 2) {
        int jdx = (j - minj) / 2;
        int x = i < n ? i - jdx : (n - 1) - jdx;
        int y = i < n ? jdx : (i - (n - 1)) + jdx;
        if (!a[x][y]) continue;
        bool b = false;
        for (int k = 0; k < i; k += 2) if (d1[k] == j) b = true;
        if (b) continue;
        d1[i] = j;
        solve1(i + 2, num + 1);
        d1[i] = -1;
    }
    solve1(i + 2, num);
}


// 1, 3, 5, ...
void solve2(int i, int num) {
    if (debug) {
        cout << "solve2(" << i << ", " << num << ")\t";
        for (int j = 0; j < m; j++) cout << d2[j] << ' ';
        cout << '\n';
    }
    if (i >= m) {
        max_num2 = max(max_num2, num);
        return;
    }
    int minj = i < n ? (n - 1) - i : (n - 1) - ((m - 1) - i);
    int maxj = i < n ? (n - 1) + i : (n - 1) + ((m - 1) - i);
    for (int j = minj; j <= maxj; j += 2) {
        int jdx = (j - minj) / 2;
        int x = i < n ? i - jdx : (n - 1) - jdx;
        int y = i < n ? jdx : (i - (n - 1)) + jdx;
        if (!a[x][y]) continue;
        bool b = false;
        for (int k = 1; k <= i; k += 2) if (d2[k] == j) b = true;
        if (b) continue;
        d2[i] = j;
        solve2(i + 2, num + 1);
        d2[i] = -1;
    }
    solve2(i + 2, num);
}


int main() {
    // Input
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n; m = 2 * n - 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    
    //
    solve1(0, 0);
    solve2(1, 0);
    cout << max_num1 + max_num2;
}