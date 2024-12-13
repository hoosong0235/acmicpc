#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> a(n); for (int i=0; i<n; i++) cin >> a[i];
    
    int j;
    for (j=n-1; j>0; j--) if (a[j-1] < a[j]) {
        for (int k=n-1; k>j-1; k--) if (a[j-1] < a[k]) {
            swap(a[j-1], a[k]);
            break;
        }
        sort(a.begin() + j, a.end());
        break;
    }
    
    if (!j) cout << -1;
    else for (int i=0; i<n; i++) cout << a[i] << ' ';
    
    return 0;
}