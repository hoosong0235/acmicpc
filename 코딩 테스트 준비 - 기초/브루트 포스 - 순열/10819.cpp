#include <bits/stdc++.h>
using namespace std;


int n, max_num = INT_MIN;
vector<int> a(8, INT_MIN);
vector<int> b(8, INT_MIN);


int calc() {
    int num = 0;
    for (int i=0; i<n-1; i++) num += abs(b[i] - b[i+1]);
    return num;
}

bool check(int i) {
    return count(b.begin(), b.end(), a[i]) < count(a.begin(), a.end(), a[i]);
}

void solve(int depth) {
    if (depth == n) {
        max_num = max(max_num, calc());
        return;
    }
    
    for (int i=0; i<n; i++) {
        if (check(i)) {
            b[depth] = a[i];
            solve(depth + 1);
            b[depth] = INT_MIN;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    
    solve(0);
    cout << max_num;
    
    return 0;
}