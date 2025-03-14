#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    while (n--) {
        int y; cin >> y;
        if (y < x) cout << y << ' ';
    }
}