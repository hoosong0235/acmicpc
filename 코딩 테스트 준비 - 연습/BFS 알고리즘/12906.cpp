#include <bits/stdc++.h>
using namespace std;


struct bfs {
    int d;
    tuple<string, string, string> ss;
};


set<tuple<string, string, string>> visited;
deque<bfs> q;


bool check(tuple<string, string, string> ss) {
    for (char c: get<0>(ss)) if (c != 'A') return false;
    for (char c: get<1>(ss)) if (c != 'B') return false;
    for (char c: get<2>(ss)) if (c != 'C') return false;
    return true;
}


int main() {
    int is[3];
    string ss[3];
    for (int i = 0; i < 3; i++) {
        cin >> is[i];
        if (is[i]) cin >> ss[i];
    }
    
    visited.insert({ss[0], ss[1], ss[2]});
    q.push_back(bfs{0, {ss[0], ss[1], ss[2]}});
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        // for (string s: c.ss) cout << s << ', '; cout << '\n';
        if (check(c.ss)) {
            cout << c.d; return 0;
        }
        tuple<string, string, string> nss;
        if (get<0>(c.ss).size()) {
            nss = {get<0>(c.ss).substr(0, get<0>(c.ss).size() - 1), get<1>(c.ss) + get<0>(c.ss)[get<0>(c.ss).size() - 1], get<2>(c.ss)};
            if (!visited.count(nss)) {
                visited.insert(nss);
                q.push_back(bfs{c.d + 1, nss});
            }
            nss = {get<0>(c.ss).substr(0, get<0>(c.ss).size() - 1), get<1>(c.ss), get<2>(c.ss) + get<0>(c.ss)[get<0>(c.ss).size() - 1]};
            if (!visited.count(nss)) {
                visited.insert(nss);
                q.push_back(bfs{c.d + 1, nss});
            }
        }
        if (get<1>(c.ss).size()) {
            nss = {get<0>(c.ss) + get<1>(c.ss)[get<1>(c.ss).size() - 1], get<1>(c.ss).substr(0, get<1>(c.ss).size() - 1), get<2>(c.ss)};
            if (!visited.count(nss)) {
                visited.insert(nss);
                q.push_back(bfs{c.d + 1, nss});
            }
            nss = {get<0>(c.ss), get<1>(c.ss).substr(0, get<1>(c.ss).size() - 1), get<2>(c.ss) + get<1>(c.ss)[get<1>(c.ss).size() - 1]};
            if (!visited.count(nss)) {
                visited.insert(nss);
                q.push_back(bfs{c.d + 1, nss});
            }
        }
        if (get<2>(c.ss).size()) {
            nss = {get<0>(c.ss) + get<2>(c.ss)[get<2>(c.ss).size() - 1], get<1>(c.ss), get<2>(c.ss).substr(0, get<2>(c.ss).size() - 1)};
            if (!visited.count(nss)) {
                visited.insert(nss);
                q.push_back(bfs{c.d + 1, nss});
            }
            nss = {get<0>(c.ss), get<1>(c.ss) + get<2>(c.ss)[get<2>(c.ss).size() - 1], get<2>(c.ss).substr(0, get<2>(c.ss).size() - 1)};
            if (!visited.count(nss)) {
                visited.insert(nss);
                q.push_back(bfs{c.d + 1, nss});
            }
        }
    }
}