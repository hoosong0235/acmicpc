#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    vector<bool> primes(1e3+1, true);
    primes[1] = false;
    for (int i=2; i<=sqrt(1e3); i++) {
        for (int j=2; i*j<=1e3; j++) {
            primes[i*j] = false;
        }
    }
    
    int N; cin >> N;
    int cnt = 0;
    while (N--) {
        int M; cin >> M;
        if (primes[M]) cnt++;
    }
    
    cout << cnt;
    
    return 0;
}