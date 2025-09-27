#include <bits/stdc++.h>
using namespace std;

#define M 1000

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    vector<bool> primes(M + 1, true);
    primes[1] = false;
    
    for (int i = 2; i * i <= M; i++)
        if (primes[i])
            for (int j = i * i; j <= M; j += i)
                primes[j] = false;
                
    int cnt = 0;
    int n, m;
    cin >> n;
    while (n--) {
        cin >> m;
        if (primes[m])
            cnt++;
    }
    cout << cnt;
}