#include <bits/stdc++.h>
using namespace std;
#define N 100


int h, w, n;
int rs[N], cs[N];


bool check(int i, int j) {
    int ir = rs[i], jr = rs[j], ic = cs[i], jc = cs[j];
    if (ir + jr <= h && ic <= w && jc <= w) return true;
    if (ic + jr <= h && ir <= w && jc <= w) return true;
    if (ir + jc <= h && ic <= w && jr <= w) return true;
    if (ic + jc <= h && ir <= w && jr <= w) return true;
    if (ir + jr <= w && ic <= h && jc <= h) return true;
    if (ic + jr <= w && ir <= h && jc <= h) return true;
    if (ir + jc <= w && ic <= h && jr <= h) return true;
    if (ic + jc <= w && ir <= h && jr <= h) return true;
    return false;
}


int calc(int i, int j) {
    int ir = rs[i], jr = rs[j], ic = cs[i], jc = cs[j];
    return ir * ic + jr * jc;
}


int main() {
    cin >> h >> w >> n;
    for (int i = 0; i < n; i++) cin >> rs[i] >> cs[i];
    
    int max_num = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (check(i, j))
                max_num = max(max_num, calc(i, j));
    cout << max_num;
}