// 00:51:20
#include <bits/stdc++.h>
using namespace std;
#define I 20000


struct bfs { string s; int m; };
int k;


int main() {
    cin >> k;
    while (k--) {
        int i; cin >> i;
        deque<bfs> q;
        bool visited[I + 1] = { };
        q.push_back(bfs { "1", 1 % i });
        visited[1 % i] = true;
        bool b = false;
        while (!q.empty()) {
            bfs c = q.front(); q.pop_front();
            if (c.s.size() > 100) continue;
            if (c.m == 0) { b = true; cout << c.s << '\n'; break; }
            if (!visited[(c.m * 10) % i]) {
                q.push_back(bfs { c.s + "0", (c.m * 10) % i });
                visited[(c.m * 10) % i] = true;
            }
            if (!visited[(c.m * 10 + 1) % i]) {
                q.push_back(bfs { c.s + "1", (c.m * 10 + 1) % i });
                visited[(c.m * 10 + 1) % i] = true;
            }
        }
        if (!b) cout << "BRAK\n";
    }
}