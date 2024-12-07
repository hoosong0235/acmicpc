#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int E, S, M; cin >> E >> S >> M;
    int year = 0;
    for (int e=0, s=0, m=0; !(e==E&&s==S&&m==M); year++) {
        if (++e > 15) e %= 15;
        if (++s > 28) s %= 28;
        if (++m > 19) m %=19;
    }
    cout << year;
    
    return 0;
}