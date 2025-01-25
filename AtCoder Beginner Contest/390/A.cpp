#include <bits/stdc++.h>
using namespace std;


int a[5];
int ds[2] = {-1, 1};


bool check() {
    for (int i = 0; i < 5; i++) if (a[i] != i + 1) return false;
    return true;
}


int main() {
    for (int i = 0; i < 5; i++) cin >> a[i];
    for (int i = 0; i < 5; i++) {
        for (int d = 0; d < 2; d++) {
            int j = i + ds[d];
            if (!(0 <= j && j < 5)) continue;
            swap(a[i], a[j]);
            if (check()) { cout << "Yes"; return 0; }
            swap(a[i], a[j]);
        }
    }
    cout << "No";
}