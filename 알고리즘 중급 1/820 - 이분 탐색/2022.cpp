#include <bits/stdc++.h>
using namespace std;
#define MAXW 3000000000


double x, y, c;


double calc(double w) {
    double hl = sqrt(x * x - w * w);
    double hr = sqrt(y * y - w * w);
    return hl * hr / (hl + hr);
}


double bs(double lo, double hi) {
    double mid = (lo + hi) / 2;
    if (abs(calc(mid) - c) < 1e-6) return mid;
    if (calc(mid) < c) return bs(lo, mid);
    else return bs(mid, hi);
}


int main() {
    cin >> x >> y >> c;
    cout << bs(0, min(x, y));
}