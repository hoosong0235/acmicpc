#include <bits/stdc++.h>
using namespace std;
#define ll long long


const string D = "0123456789", C = "abcdefghijklmnopqrstuvwxyz";
ll cnt = 0;
string s, t;


void solve(int d) {
    if (d == s.length()) {
        cnt++;
        return;
    }
    
    if (s[d] == 'd') {
        for (char c: D) if (d == 0 || t[d - 1] != c) {
            t[d] = c;
            solve(d + 1);
        }
    } else {
        for (char c: C) if (d == 0 || t[d - 1] != c) {
            t[d] = c;
            solve(d + 1);
        }
    }
}


int main() {
    cin >> s;
    solve(0);
    cout << cnt;
}