#include <bits/stdc++.h>
using namespace std;


vector<bool> visited(4000001, true);
vector<int> ps;


int main() {
    for (int i = 2; i * i <= 4000000; i++) if (visited[i]) {
        for (int j = i * i; j <= 4000000; j += i) visited[j] = false;
    }
    for (int i = 2; i <= 4000000; i++) if (visited[i]) ps.push_back(i);
    
    int n = ps.size(), m; cin >> m;
    int start = 0, end = 0, sum = ps[0], cnt = 0;
    while (end < n) {
        if (sum < m) {
            sum += ps[++end];
            if (end == n && sum == m) cnt++;
        } else if (sum == m) {
            cnt++;
            sum -= ps[start++];
        } else {
            sum -= ps[start++];
        }
    }
    cout << cnt;
    
    return 0;
}