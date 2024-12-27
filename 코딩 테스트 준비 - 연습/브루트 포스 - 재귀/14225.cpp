#include <bits/stdc++.h>
using namespace std;


int n;
vector<int> v(20);
deque<int> s;
set<int> sums;


void rec(int next_i) {
    for (int i = next_i; i < n; i++) {
        s.push_back(v[i]);
        sums.insert(accumulate(s.begin(), s.end(), 0));
        rec(i + 1);
        s.pop_back();
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n; for (int i = 0; i < n; i++) cin >> v[i];
    rec(0);
    for (int i = 1; ; i++) if (!sums.count(i)) {
        cout << i; break;
    }
    
    return 0;
}