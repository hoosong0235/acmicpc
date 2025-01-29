#include <bits/stdc++.h>
using namespace std;
#define N 1000000


int n, i;
vector<int> v(1);


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    // Longest increasing subsequence
    cin >> v[0];
    while (--n) {
        cin >> i;
        auto it = lower_bound(v.begin(), v.end(), i);
        if (it == v.end()) v.push_back(i);
        else *it = i;
    }
    
    cout << v.size();
}