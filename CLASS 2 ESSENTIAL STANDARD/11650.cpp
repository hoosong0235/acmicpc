#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    vector<pair<int, int>> v;
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for (auto e: v)
        cout << e.first << ' ' << e.second << '\n';
}