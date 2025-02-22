#include <bits/stdc++.h>
using namespace std;
#define N 10


int n, m, k, ps[N + 1], min_num = INT_MAX;
vector<int> adj[N + 1], rs, bs;


bool check() {
    if (rs.empty() || bs.empty())
        return false;
        
    deque<int> rq;
    bool rvisited[N + 1] = { };
    rq.push_back(rs[0]);
    rvisited[rs[0]] = true;
    while (!rq.empty()) {
        int c = rq.front(); rq.pop_front();
        for (int n: adj[c])
            if (!rvisited[n] && find(rs.begin(), rs.end(), n) != rs.end()) {
                rq.push_back(n);
                rvisited[n] = true;
            }
    }
    for (int r: rs)
        if (!rvisited[r])
            return false;
            
    deque<int> bq;
    bool bvisited[N + 1] = { };
    bq.push_back(bs[0]);
    bvisited[bs[0]] = true;
    while (!bq.empty()) {
        int c = bq.front(); bq.pop_front();
        for (int n: adj[c])
            if (!bvisited[n] && find(bs.begin(), bs.end(), n) != bs.end()) {
                bq.push_back(n);
                bvisited[n] = true;
            }
    }
    for (int b: bs)
        if (!bvisited[b])
            return false;
    
    return true;
}


int calc() {
    int rp = 0, bp = 0;
    for (auto r: rs)
        rp += ps[r];
    for (auto b: bs)
        bp += ps[b];
    return abs(rp - bp);
}


void solve(int d) {
    if (d == n + 1) {
        if (check())
            min_num = min(min_num, calc());
        return;
    }
    
    rs.push_back(d);
    solve(d + 1);
    rs.pop_back();
    bs.push_back(d);
    solve(d + 1);
    bs.pop_back();
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> ps[i];
    for (int i = 1; i <= n; i++) {
        cin >> m;
        while (m--) {
            cin >> k;
            adj[i].push_back(k);
        }
    }
    
    solve(1);
    
    cout << (min_num != INT_MAX ? min_num : -1);
}