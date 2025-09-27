#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    vector<int> v;
    int n, m;
    cin >> n;
    while (n--) {
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(), v.end());
    for (auto e: v)
        cout << e << '\n';
}