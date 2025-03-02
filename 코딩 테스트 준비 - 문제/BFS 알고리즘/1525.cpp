// 00:37:10
#include <bits/stdc++.h>
using namespace std;
#define set unordered_set


struct bfs {
    string s;
    int d, i;
};


int ii;
string s;
deque<bfs> q;
set<string> visited;
const int ds[4] = { -3, -1, 1, 3 };
const string target = "123456780";


int main() {
    for (int i = 0; i < 9; i++) {
        int j; cin >> j;
        s += '0' + j;
        if (s[i] == '0') 
            ii = i;
    }
    
    q.push_back(bfs { s, 0, ii });
    visited.insert(s);
    
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        if (c.s == target) {
            cout << c.d;
            return 0;
        }
        for (int d = 0; d < 4; d++) {
            int ni = c.i + ds[d];
            if (ds[d] == -1 && (ni == 2 || ni == 5)) continue;
            if (ds[d] == 1 && (ni == 3 || ni == 6)) continue;
            if (ni < 0 || 9 <= ni) continue;
            string ns = c.s;
            swap(ns[c.i], ns[ni]);
            if (visited.find(ns) == visited.end()) {
                q.push_back(bfs { ns, c.d + 1, ni });
                visited.insert(ns);
            }
        }
    }
    
    cout << -1;
}