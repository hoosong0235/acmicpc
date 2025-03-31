#include <bits/stdc++.h>
using namespace std;
#define N 4'000
#define M 100'000
#define ll long long
#define INF LONG_LONG_MAX

priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> fpq; // { d, i };
vector<ll> fdist(N + 1, INF);
vector<bool> fproc(N + 1, false);

priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> wpq; // { d, i, b };
vector<vector<ll>> wdist(2, vector<ll>(N + 1, INF));
vector<vector<bool>> wproc(2, vector<bool>(N + 1, false));

int n, m;
vector<pair<int, ll>> adj[N + 1]; // { i, w };

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, d; cin >> a >> b >> d;
        adj[a].push_back({ b, d });
        adj[b].push_back({ a, d });
    }
    
    fdist[1] = 0;
    fpq.push({ 0, 1 });
    while (!fpq.empty()) {
        auto [cd, ci] = fpq.top(); fpq.pop();
        if (fproc[ci]) continue;
        fproc[ci] = true;
        for (auto [ni, w]: adj[ci]) {
            ll nd = cd + w * 2;
            if (nd < fdist[ni]) {
                fdist[ni] = nd;
                fpq.push({ nd, ni });
            }
        }
    }
    
    wdist[0][1] = 0;
    wpq.push({ 0, 1, 0 });
    while (!wpq.empty()) {
        auto [cd, ci, cb] = wpq.top(); wpq.pop();
        if (wproc[cb][ci]) continue;
        wproc[cb][ci] = true;
        for (auto [ni, w]: adj[ci]) {
            int nb = 1 - cb;
            ll nd = cd + w * (cb ? 4 : 1);
            if (nd < wdist[nb][ni]) {
                wdist[nb][ni] = nd;
                wpq.push({ nd, ni, nb });
            }
        }
    }
    
    // for (int i = 1; i <= n; i++)
    //     cout << fdist[i] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= n; i++)
    //     cout << wdist[0][i] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= n; i++)
    //     cout << wdist[1][i] << ' ';
    // cout << '\n';
    
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (fdist[i] < min(wdist[0][i], wdist[1][i]))
            cnt++;
    cout << cnt;
}