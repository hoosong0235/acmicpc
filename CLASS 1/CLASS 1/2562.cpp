#include <bits/stdc++.h>
using namespace std;


int main() {
    int max_i, max_num = INT_MIN;
    for (int i = 1; i <= 9; i++) {
        int num; cin >> num;
        if (max_num < num) {
            max_i = i;
            max_num = num;
        }
    }
    cout << max_num << '\n' << max_i;
}