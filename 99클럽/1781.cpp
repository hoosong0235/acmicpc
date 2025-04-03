#include <bits/stdc++.h>
using namespace std;
#define N 200'000
#define ll long long

int n, cnt;
vector<ll> bs[N + 1];
priority_queue<ll> pq;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        bs[a].push_back(b);
    }
    for (int i = n; i >= 1; i--) {
        for (auto b: bs[i]) pq.push(b);
        if (!pq.empty()) {
            cnt += pq.top(); 
            pq.pop();
        }
    }
    cout << cnt;
}