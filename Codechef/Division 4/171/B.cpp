#include <bits/stdc++.h>
using namespace std;


const string u = "ADVITIYA";


int solve(string s) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        char uc = u[i], sc = s[i];
        if (sc < uc) cnt += uc - sc;
        else if (sc == uc) continue;
        else cnt += ('Z' - sc) + (uc - 'A') + 1;
    }
    return cnt;
}


int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        cout << solve(s) << '\n';
    }
}