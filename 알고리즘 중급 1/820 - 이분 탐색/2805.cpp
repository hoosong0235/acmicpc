#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000
#define MAXM 2000000000
#define ll long long


int n, m;
int ns[MAXN];


bool check(int i) {
    ll cnt = 0;
    for (int j = 0; j < n; j++) if (ns[j] > i) cnt += ns[j] - i;
    return cnt >= m;
}


int bs(ll lo, ll hi) {
    int mid = (lo + hi) / 2;
    if (lo > hi) return mid;
    if (check(mid)) return bs(mid + 1, hi);
    else return bs(lo, mid - 1);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> ns[i];
    cout << bs(1, MAXM);
}