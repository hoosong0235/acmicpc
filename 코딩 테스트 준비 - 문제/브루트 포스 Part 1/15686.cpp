// 00:19:13
#include <bits/stdc++.h>
using namespace std;
#define N 50
#define M 13
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


int n, m, min_num = INT_MAX;
int a[N + 1][N + 1];
vector<pair<int, int>> cs, hs, curr;


int dist(pair<int, int> &a, pair<int, int> &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}


int calc() {
    int sum = 0;
    for (auto h: hs) {
        int min_num = INT_MAX;
        for (auto c: curr) min_num = min(min_num, dist(h, c));
        sum += min_num;
    }
    return sum;
}


void solve(int ci) {
    if (curr.size() == m) {
        min_num = min(min_num, calc());
        return;
    }
    
    for (int i = ci; i < cs.size(); i++) {
        curr.push_back(cs[i]);
        solve(i + 1);
        curr.pop_back();
    }
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        if (a[i][j] == 1) hs.push_back({ i, j });
        if (a[i][j] == 2) cs.push_back({ i, j });
    }    
    solve(0);
    cout << min_num;
}