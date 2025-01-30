#include <bits/stdc++.h>
using namespace std;
#define N 300000
#define K 300000
#define ll long long


int n, k, m, v;
pair<int, int> js[N]; // { m , v }
int cs[K];
priority_queue<int> pq;


int main() {
    // Input
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        js[i] = { m, v };
    }
    for (int i = 0; i < k; i++) cin >> cs[i];
    
    // Greedy algorithm    
    sort(js, js + n);
    sort(cs, cs + k);
    ll sum = 0;
    int i = 0;
    for (int j = 0; j < k; j++) {
        while (i < n && js[i].first <= cs[j]) pq.push(js[i++].second);
        if (!pq.empty()) sum += pq.top(), pq.pop();
    }
    cout << sum;
}