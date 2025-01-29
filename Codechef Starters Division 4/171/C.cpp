#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    while (t--) {
        int m, k; cin >> m >> k;
        string s; cin >> s;
        int swishes = 0, passes = 0;
        for (char c: s) {
            if (c == 'S') swishes++;
            else passes++;
        }
        
        if (swishes < k) {
            cout << m + k - swishes - 1 << '\n';
        } else {
            cout << m << '\n';
        }
    }
}