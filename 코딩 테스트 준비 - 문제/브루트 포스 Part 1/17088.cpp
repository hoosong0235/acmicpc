// 00:13:24
#include <bits/stdc++.h>
using namespace std;
#define N 100'000


int n, a[N], b[N];
const int ds[3] = { -1, 0, 1 };


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    if (n == 1) { cout << 0; return 0; }
    
    int min_num = INT_MAX;
    for (int d0: ds) for (int d1: ds) {
        memcpy(b, a, sizeof(int) * N);
        b[0] += d0, b[1] += d1;
        int d = b[1] - b[0];
        
        int num = abs(d0) + abs(d1);
        bool succ = true;
        for (int i = 2; i < n; i++) {
            if (b[i] - b[i - 1] - d == 0) continue;
            else if (abs(b[i] - b[i - 1] - d) == 1) b[i] = b[i - 1] + d, num++;
            else { succ = false; break; }
        }
        
        if (succ) min_num = min(min_num, num);
    }
    cout << (min_num != INT_MAX ? min_num : -1);
}