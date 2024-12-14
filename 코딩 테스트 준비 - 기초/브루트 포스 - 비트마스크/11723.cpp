#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    vector<bool> s(21, false);
    string op;
    int i, x, n; cin >> n;
    while (n--) {
        cin >> op;
        if (op != "all" && op != "empty") cin >> x;
        if (op == "add") s[x] = true;
        else if (op == "remove") s[x] = false;
        else if (op == "check") cout << (s[x] ? 1 : 0) << '\n';
        else if (op == "toggle") s[x] = !s[x];
        else if (op == "all") for (i=1; i<21; i++) s[i] = true;
        else if (op ==  "empty") for (i=1; i<21; i++) s[i] = false;
    }
    
    return 0;
}