// 00:21:35
#include <bits/stdc++.h>
using namespace std;
#define N 1'000
#define T 2'000
#define M 1'000


int n, t, s, x, y, m, a, b;
bool ss[N + 1];
pair<int, int> ps[N + 1];
int ts[N + 1];


int dist(int a, int b) {
    return abs(ps[a].first - ps[b].first) + abs(ps[a].second - ps[b].second);
}


void debug() {
    for (int i = 1; i <= n; i++)
        cout << ss[i] << ' ';
    cout << '\n';
    
    for (int i = 1; i <= n; i++)
        cout << ps[i].first << ',' << ps[i].second << ' ';
    cout << '\n';
    
    for (int i = 1; i <= n; i++)
        cout << ts[i] << ' ';
    cout << '\n';
}


void init() {
    for (int i = 1; i <= n; i++) {
        int min_dist = INT_MAX, min_city = 0;
        for (int j = 1; j <= n; j++)
            if (ss[j] && (dist(i, j) < min_dist)) {
                min_dist = dist(i, j);
                min_city = j;
            }
        ts[i] = min_city;
    }
}


int solve(int a, int b) {
    return (ts[a] || ts[b]) ? min(
        dist(a, b),
        dist(a, ts[a]) + t + dist(b, ts[b])
    ) : dist(a, b);
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> s >> x >> y;
        if (s) ss[i] = true;
        ps[i] = { x, y };
    }
    
    init();
    
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        cout << solve(a, b) << '\n';
    }
}