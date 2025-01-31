#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll offset;
deque<ll> q;
deque<ll> ls;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int Q; cin >> Q;
    while (Q--) {
        // for (ll i: q) cout << i << " "; cout << '\n';
        int i, j; cin >> i;
        if (i == 1) {
            cin >> j;
            if (q.empty()) q.push_back(j);
            else q.push_back(q.back() + j);
            ls.push_back(j);
        } else if (i == 2) {
            offset += ls.front();
            q.pop_front();
            ls.pop_front();
        } else {
            cin >> j;
            cout << q[j - 1] - ls[j - 1] - offset << '\n';
        }
    }
}