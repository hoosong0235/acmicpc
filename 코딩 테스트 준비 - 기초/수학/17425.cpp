#include <iostream>
#include <vector>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    vector<long long> f(1e6+1, 0), g(1e6+1, 0);
    for (int i=1; i<=1e6; i++) {
        for (int j=1; i*j<=1e6; j++) {
            f[i*j] += i;
        }
    }
    for (int i=1; i<=1e6; i++) g[i] = g[i-1] + f[i];
    
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << g[N] << '\n';
    }
    
    return 0;
}