#include <bits/stdc++.h>
using namespace std;
#define N 50


string ss[N];


int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ss[i];
        
    sort(ss, ss + n, [](auto a, auto b) { return a.size() < b.size(); });
    for (int i = 0; i < n; i++)
        cout << ss[i];
}