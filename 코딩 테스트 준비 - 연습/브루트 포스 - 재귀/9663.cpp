#include <bits/stdc++.h>
using namespace std;


int n, cnt = 0;
vector<int> qs(15);


bool check(int c) {
    for (int j = 0; j < c; j++) {
        if (qs[j] == qs[c] || abs(qs[j] - qs[c]) == c - j) return false;
    }
    return true;
}


void solve(int j) {
    if (j == n) {
        cnt++;
    }
    
    for (int i = 0; i < n; i++) {
        qs[j] = i;
        if (check(j)) solve(j + 1);
    }   
}


int main() {
    cin >> n;
    solve(0);
    cout << cnt;
    return 0;
}