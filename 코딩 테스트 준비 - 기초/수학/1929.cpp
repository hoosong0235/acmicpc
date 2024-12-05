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
    
    int M, N; cin >> M >> N;
    for (int i=M; i<=N; i++) if (primes[i]) cout << i << '\n';
    
    return 0;
}