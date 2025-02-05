#include <bits/stdc++.h>
using namespace std;


int t, x, y;


int main() {
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (x % 2 && !(y % 2)) {
            for (int i = 0; i < x / 2; i++) cout << 1;
            for (int j = 0; j < y / 2; j++) cout << 2;
            cout << 1;
            for (int j = 0; j < y / 2; j++) cout << 2;
            for (int i = 0; i < x / 2; i++) cout << 1;
        } else if (!(x % 2) && y % 2) {
            for (int i = 0; i < x / 2; i++) cout << 1;
            for (int j = 0; j < y; j++) cout << 2;
            for (int i = 0; i < x / 2; i++) cout << 1;
        } else if (!(x % 2) && !(y % 2)) {
            for (int i = 0; i < x / 2; i++) cout << 1;
            for (int j = 0; j < y; j++) cout << 2;
            for (int i = 0; i < x / 2; i++) cout << 1;
        }
        cout << '\n';
    }
}