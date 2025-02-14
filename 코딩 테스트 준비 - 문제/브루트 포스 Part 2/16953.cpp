// 약 00:10:00
#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll a, b;
deque<pair<ll, int>> q;
set<ll> visited;


int main() {
    cin >> a >> b;
    q.push_back({ a, 0 });
    visited.insert(a);
    while (!q.empty()) {
        pair<ll, int> c = q.front(); q.pop_front();
        if (c.first == b) {
            cout << c.second + 1; return 0;
        }
        if (c.first * 2 <= b && visited.find(c.first * 2) == visited.end()) {
            q.push_back({ c.first * 2, c.second + 1 });
            visited.insert(c.first * 2);
        }
        if (c.first * 10 + 1 <= b && visited.find(c.first * 10 + 1) == visited.end()) {
            q.push_back({ c.first * 10 + 1, c.second + 1 });
            visited.insert(c.first * 10 + 1);
        }
    }
    cout << -1;
}