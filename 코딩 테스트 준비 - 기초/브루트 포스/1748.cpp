#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i *= 10) sum += (n - i + 1);
    cout << sum;
    
    return 0;
}