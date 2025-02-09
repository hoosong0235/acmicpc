#include <bits/stdc++.h>
using namespace std;
#define N 100
#define K 100000


int n, k, a;
double ks[N + 1];
map<int, double> cnts[N + 1];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cout.precision(9);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        ks[i] = k;
        for (int j = 1; j <= k; j++) {
            cin >> a;
            cnts[i][a]++;
        }
    }
    
    double max_num = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double num = 0;
            for (auto &[key, value]: cnts[i])
                if (cnts[j].find(key) != cnts[j].end())
                    num += value * cnts[j][key];
            max_num = max(max_num, num / ks[i] / ks[j]);
        }
    }
    cout << max_num;
}