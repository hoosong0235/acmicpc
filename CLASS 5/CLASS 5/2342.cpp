#include <bits/stdc++.h>
using namespace std;
#define MAX 100000


int i, n, min_w = INT_MAX;
vector<int> a;
int dp[MAX + 1][5][5];


const int w[5][5] = {
    { 2, 2, 2, 2, 2 },
    { 0, 1, 3, 4, 3 },
    { 0, 3, 1, 3, 4 },
    { 0, 4, 3, 1, 3 },
    { 0, 3, 4, 3, 1 },
};


void debug() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << '\n';
        for (int l = 0; l < 5; l++) {
            for (int r = 0; r < 5; r++) {
                cout << dp[i][l][r];
            }
            cout << '\n';
        }
        cout << '\n';
    }
}


int main() {
    do {
        cin >> i;
        a.push_back(i);
    } while (i);
    a.pop_back();
    n = a.size();
    
    dp[0][a[0]][0] = w[0][a[0]], dp[0][0][a[0]] = w[0][a[0]];
    for (int i = 1; i < n; i++) {
        for (int l = 0; l < 5; l++) for (int r = 0; r < 5; r++) if (dp[i - 1][l][r]) {
            // left foot
            if (r != a[i]) {
                if (!dp[i][a[i]][r]) dp[i][a[i]][r] = dp[i - 1][l][r] + w[l][a[i]];
                dp[i][a[i]][r] = min(dp[i][a[i]][r], dp[i - 1][l][r] + w[l][a[i]]);
            }
            // right foot
            if (l != a[i]) {
                if (!dp[i][l][a[i]]) dp[i][l][a[i]] = dp[i - 1][l][r] + w[r][a[i]];
                dp[i][l][a[i]] = min(dp[i][l][a[i]], dp[i - 1][l][r] + w[r][a[i]]);
            }
        }
    }
    // debug();
    
    for (int l = 0; l < 5; l++) for (int r = 0; r < 5; r++) if (dp[n - 1][l][r]) min_w = min(min_w, dp[n - 1][l][r]);
    cout << min_w;
}