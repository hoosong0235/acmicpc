#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, d;
    cin >> n >> d;
    vector<int> ts(n), ls(n);
    for (int i = 0; i < n; i++) cin >> ts[i] >> ls[i];
    for (int i = 1; i <= d; i++) {
        int max_num = INT_MIN;
        for (int j = 0; j < n; j++) max_num = max(max_num, ts[j] * (ls[j] + i));
        cout << max_num << '\n';
    }
}