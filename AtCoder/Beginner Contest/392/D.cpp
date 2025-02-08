#include <bits/stdc++.h>
using namespace std;
#define N 100
#define A 100000
#define K 100000
#define map unordered_map
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


int n, k, a;
double ks[N + 1];
double dices[N + 1][A + 1];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout.precision(100);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        ks[i] = k;
        for (int j = 1; j <= k; j++) {
            cin >> a;
            dices[i][a]++;
        }
    }
    
    double max_num = 0;
    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
        double same = 0;
        for (int a = 1; a <= A; a++)
            if (dices[i][a] && dices[j][a])
                same += dices[i][a] * dices[j][a];
        max_num = max(max_num, same / (ks[i] * ks[j]));
    }
    cout << max_num;
}