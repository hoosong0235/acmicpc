#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    vector<bool> primes(1e6+1, true);
    primes[1] = false;
    for (int i=2; i<=sqrt(1e6); i++) {
        if (!primes[i]) continue;
        for (int j=2; i*j<=1e6; j++) {
            primes[i*j] = false;
        }
    }
    
    int n;
    while (cin >> n) {
        if (!n) break;
        bool isBreak = false;
        for (int i=3; i<=n/2 && i<=1e6/2; i++) {
            if (primes[i] && primes[n - i]) {
                cout << n << " = " << i << " + " << n - i << '\n';
                isBreak = true;
                break;
            }
        }
        if (!isBreak) cout << "Goldbach's conjecture is wrong.\n";
    }
    
    return 0;
}