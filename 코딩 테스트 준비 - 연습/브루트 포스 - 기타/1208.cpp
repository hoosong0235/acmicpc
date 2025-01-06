#include <bits/stdc++.h>
using namespace std;


int n, m;
long long cnt = 0;
vector<int> s(6000000, 0);
vector<int> a(40);


void solve1(int ii, int num) {
    // cout << "solve1(" << ii << ", " << num << ")\n";
    s[num + 3000000]++;
    for (int i = ii; i < n / 2; i++) solve1(i + 1, num + a[i]);
}

void solve2(int ii, int num) {
    // cout << "solve2(" << ii << ", " << num << ")\n";   
    if (s[(m - num) + 3000000]) cnt += s[(m - num) + 3000000];
    for (int i = ii; i < n; i++) solve2(i + 1, num + a[i]);
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    solve1(0, 0);
    solve2(n / 2, 0);
    
    if (m == 0) cnt--;
    cout << cnt;
    
    return 0;
}