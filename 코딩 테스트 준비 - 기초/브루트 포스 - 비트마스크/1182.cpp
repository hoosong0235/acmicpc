#include <bits/stdc++.h>
using namespace std;


int n, sum, cnt = 0;
vector<int> a(20);
list<int> s;


void solve(int depth, int init_i) {
    if (s.size() && accumulate(s.begin(), s.end(), 0) == sum) cnt++;
    
    for (int i=init_i; i<n; i++) {
        s.push_back(a[i]);
        solve(depth + 1, i + 1);
        s.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> sum;
    for (int i=0; i<n; i++) cin >> a[i];
    
    solve(0, 0);
    cout << cnt;
    
    return 0;
}