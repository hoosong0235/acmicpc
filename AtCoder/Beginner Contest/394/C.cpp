#include <bits/stdc++.h>
using namespace std;


int main() {
    string s; cin >> s;
    
    int p = -1, wp = -1, n = s.size();
    while (++p < n) {
        if (s[p] == 'W') {
            if (wp == -1)
                wp = p;
            else
                continue;
        } else if (s[p] == 'A' && wp != -1) {
            s[wp] = 'A';
            for (int i = wp + 1; i <= p; i++)
                s[i] = 'C';
            wp = -1;
        } else {
            wp = -1;
        }
    }
    
    cout << s;
}