#include <bits/stdc++.h>
using namespace std;


int main() {
    string s; cin >> s;
    int n = s.size();
    
    int cnt = 0;
    for (int i = 1; i < n - 1; i++) if (s[i] == 'B') {
        for (int j = 1; j <= min(i, n - 1 - i); j++) {
            if (s[i - j] == 'A' && s[i + j] == 'C') cnt++;
        }
    }
    cout << cnt;
}