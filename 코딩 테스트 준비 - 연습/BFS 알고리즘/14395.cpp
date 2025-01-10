#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000001


struct bfs {
    long long i;
    string s;
};


int s, t;
set<long long> visited;
deque<bfs> q;


int main() {
    cin >> s >> t;
    visited.insert(s);
    q.push_back(bfs{s, ""});
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        if (c.i == t) {
            if (s == t) cout << 0;
            else cout << c.s;
            return 0;
        }
        long long ni;
        ni = c.i * c.i;
        if (ni < MAX) if (!visited.count(ni)) {
            visited.insert(ni);
            q.push_back(bfs{ni, c.s + "*"});
        }
        ni = c.i + c.i;
        if (ni < MAX) if (!visited.count(ni)) {
            visited.insert(ni);
            q.push_back(bfs{ni, c.s + "+"});
        }
        if (!visited.count(1)) {
            visited.insert(ni);
            q.push_back({1, c.s + "/"});
        }
    }
    cout << -1;
}