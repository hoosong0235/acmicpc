#include <bits/stdc++.h>
using namespace std;
#define MAXN 100


int n;
double r;
double a[MAXN];


int main() {
    cin >> n;
    if (n <= 2) { cout << "Yes"; return 0; }
    cin >> a[0] >> a[1];
    r = a[1] / a[0];
    for (int i = 2; i < n; i++) {
        cin >> a[i];
        if (a[i - 1] * r != a[i]) { cout << "No"; return 0; }
    }
    cout << "Yes";
}