#include <bits/stdc++.h>
using namespace std;
#define N 1000000


int n;
int a[N], idxs[N];
vector<int> v, w;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // Longest increasing subsequence
    idxs[0] = 0;
    v.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        if (it == v.end()) {
            idxs[i] = v.size();
            v.push_back(a[i]);
        } else {
            idxs[i] = it - v.begin();
            *it = a[i];
        }
    }
    int idx = v.size() - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (idxs[i] == idx) {
            idx--;
            w.push_back(a[i]);
        }
    }
    reverse(w.begin(), w.end());
    
    cout << v.size() << '\n';
    for (int i: w) cout << i << ' ';
}