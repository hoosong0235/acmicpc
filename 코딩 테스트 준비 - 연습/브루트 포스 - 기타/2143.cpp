#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    int n; cin >> n;
    vector<int> na(n + 1); for (int i = 1; i < n + 1; i++) cin >> na[i];
    vector<int> ns(n + 1); ns[0] = 0; for (int i = 1; i < n + 1; i++) ns[i] = ns[i - 1] + na[i];
    int m; cin >> m;
    vector<int> ma(m + 1); for (int i = 1; i < m + 1; i++) cin >> ma[i];
    vector<int> ms(m + 1); ms[0] = 0; for (int i = 1; i < m + 1; i++) ms[i] = ms[i - 1] + ma[i];
    
    long long cnt = 0;
    map<int, int> d;
    for (int i = 0; i < n + 1; i++) for (int j = i + 1; j < n + 1; j++) d[ns[j] - ns[i]]++;
    for (int i = 0; i < m + 1; i++) for (int j = i + 1; j < m + 1; j++) if (d[t - (ms[j] - ms[i])]) cnt += d[t - (ms[j] - ms[i])];
    
    cout << cnt;
}