#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b;
    while (1) {
        cin >> a >> b;
        if (!a && !b)
            break;
        cout << a + b << '\n';
    }
}