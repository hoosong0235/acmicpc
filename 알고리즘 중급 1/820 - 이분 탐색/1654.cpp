#include <bits/stdc++.h>
using namespace std;
#define MAXK 10000
#define MAXN 1000000
#define ui unsigned int
#define ll long long


int k, n;
ui ks[MAXK];


bool check(int i) { // NlogK
    int sum = 0, j = i;
    while (1) {
        int num = k - (lower_bound(ks, ks + k, j) - ks);
        sum += num, j += i;

        if (!num) return false;
        if (sum >= n) return true;
    }
}


int bs(ui lo, ui hi) { // NLogK
    ui mid = (lo + hi) / 2;
    if (check(mid) && !check(mid + 1)) return mid;
    
    if (check(mid)) return bs(mid + 1, hi);
    else return bs(lo, mid - 1);
}


int main() {
    cin >> k >> n;
    for (int i = 0; i < k; i++) cin >> ks[i];
    sort(ks, ks + k);
    cout << bs(1, INT_MAX); // logINT_MAX
}