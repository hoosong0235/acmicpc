#include <bits/stdc++.h>
using namespace std;


int main() {
    string s, t; cin >> s >> t;
    if (s == "sick") {
        if (t == "sick") cout << 1;
        else cout << 2;
    } else {
        if (t == "sick") cout << 3;
        else cout << 4;
    }
}