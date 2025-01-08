#include <bits/stdc++.h>
using namespace std;


bool visited[1501][1501];
deque<tuple<int, int, int>> q;


tuple<int, int, int> mktup(int a, int b, int c) {
    if (a >= b && a >= c) {
        if (b >= c) return {a, b, c};
        else return {a, c, b};
    } else if (b >= a && b >= c) {
        if (a >= c) return {b, a, c};
        else return {b, c, a};
    } else {
        if (a >= b) return {c, a, b};
        else return {c, b, a};
    }
}


vector<tuple<int, int, int>> solve(int a, int b, int c) {
    vector<tuple<int, int, int>> nts;
    if (a != b) nts.push_back(mktup(a - b, b + b, c));
    if (b != c) nts.push_back(mktup(a, b - c, c + c));
    if (a != c) nts.push_back(mktup(a - c, b, c + c));
    return nts;
}


int main() {
    int a, b, c; cin >> a >> b >> c;
    tuple<int, int, int> t = mktup(a, b, c);
    visited[get<0>(t)][get<1>(t)] = true;
    q.push_back(t);
    while (!q.empty()) {
        t = q.front(); q.pop_front();
        if (get<0>(t) == get<1>(t) && get<1>(t) == get<2>(t)) {
            cout << '1'; return 0;
        }
        for (tuple<int, int, int> nt: solve(get<0>(t), get<1>(t), get<2>(t))) {
            if (!visited[get<0>(nt)][get<1>(nt)]) {
                visited[get<0>(nt)][get<1>(nt)] = true;
                q.push_back(nt);
            }
        }
    }
    cout << '0';
}