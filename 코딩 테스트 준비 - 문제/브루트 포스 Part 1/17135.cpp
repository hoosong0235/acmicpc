// 01:49:44
#include <bits/stdc++.h>
using namespace std;
#define N 15
#define M 15


int n, m, d, score;
int a[N][M], b[N][M];
bool mask[M];
vector<pair<int, int>> atked;


void move() {
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < m; j++)
            if (i) b[i][j] = b[i - 1][j];
            else b[i][j] = 0;
}


int dist(int k, pair<int, int> p) {
    return abs(n - p.first) + abs(k - p.second);
}


void atk(int k) {
    vector<tuple<int, int, int>> ts;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (b[i][j] && dist(k, { i, j }) <= d)
                ts.push_back({ i, j, dist(k, { i, j }) });
    if (ts.empty()) return;
    sort(ts.begin(), ts.end(), [](auto a, auto b) {
        return get<2>(a) != get<2>(b) ? get<2>(a) < get<2>(b) : get<1>(a) < get<1>(b);
    });
    atked.push_back({ get<0>(ts[0]), get<1>(ts[0]) });
}


void do_atk() {
    for (auto p: atked)
        if (b[p.first][p.second])
            score++, b[p.first][p.second] = 0;
    atked.clear();
}


void solve() {
    score = 0;
    memcpy(b, a, sizeof(int) * N * M);
    for (int tmp = 0; tmp < n; tmp++) {
        for (int k = 0; k < m; k++) if (mask[k]) atk(k);
        do_atk();
        move();
    }
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    
    mask[0] = true, mask[1] = true, mask[2] = true;
    
    int max_num = 0;
    do {
        solve();
        max_num = max(max_num, score);
    } while (prev_permutation(mask, mask + m));
    cout << max_num;
}