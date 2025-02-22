// 01:21:25
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define N 10


int a[N][N], min_num = INT_MAX;
int cnts[6] = { 0, 5, 5, 5, 5, 5 };


int calc() {
    int num = 0;
    for (auto cnt: cnts) num += cnt;
    return 25 - num;
}


bool check(int x, int y, int k) {
    if (!cnts[k])
        return false;

    for (int i = x; i < x + k; i++)
        for (int j = y; j < y + k; j++)
            if (!a[i][j] || i >= N || j >= N)
                return false;
    return true;
}


void cover(int x, int y, int k, bool rev=false) {
    for (int i = x; i < x + k; i++)
        for (int j = y; j < y + k; j++)
            a[i][j] = (rev ? 1 : 0);
}


void solve(int i, int j) {
    if (i == N && j == 0) {
        min_num = min(min_num, calc());
        return;
    }

    if (a[i][j]) {
        for (int k = 1; k <= 5; k++)
            if (check(i, j, k)) {
                cnts[k]--;
                cover(i, j, k);
                solve((j == N - 1 ? i + 1 : i), (j == N - 1 ? 0 : j + 1));
                cnts[k]++;
                cover(i, j, k, true);
            }
    } else
        solve((j == N - 1 ? i + 1 : i), (j == N - 1 ? 0 : j + 1));
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];

    solve(0, 0);
    cout << (min_num != INT_MAX ? min_num : -1);
}