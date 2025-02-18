// 약 00:14:00
#include <bits/stdc++.h>
using namespace std;
#define N 8


struct egg { int s, w; };


int n, s, w, max_num = 0;
egg eggs[N];


int calc() {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (eggs[i].s <= 0)
            cnt++;
    return cnt;
}


bool check(int d) {
    for (int i = 0; i < n; i++)
        if (i != d)
            if (eggs[i].s > 0)
                return true;
    return false;
}


void solve(int d) {
    if (d == n) {
        max_num = max(max_num, calc());
        return;
    }
    
    if (eggs[d].s <= 0) {
        solve(d + 1);
        return;
    }
    
    if (!check(d)) {
        solve(d + 1);
        return;
    }
    
    for (int i = 0; i < n; i++)
        if (i != d)
            if (eggs[i].s > 0) {
                eggs[d].s -= eggs[i].w;
                eggs[i].s -= eggs[d].w;
                solve(d + 1);
                eggs[d].s += eggs[i].w;
                eggs[i].s += eggs[d].w;
            }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> w;
        eggs[i] = { s, w };
    }
    
    solve(0);
    cout << max_num;
}