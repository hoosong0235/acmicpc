#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b) {
    assert(a >= b);
    return a % b ? gcd(b, a % b) : b;
}

int lcm(int a, int b) {
    assert(a >= b);
    return a * b / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T; cin >> T;
    while (T--) {
        int M, N, X, Y; cin >> M >> N >> X >> Y;
        
        int ans = -1;
        if (Y == N) Y = 0;
        for (int year = X; year <= lcm(max(M, N), min(M, N)); year += M) {
            if (year % N == Y) {
                ans = year;
                break;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}