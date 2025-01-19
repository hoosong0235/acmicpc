#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


string s1, s2;
int dp[MAX + 1][MAX + 1];


int main() {
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // for (int i = 0; i <= s1.size(); i++) {
    //     for (int j = 0; j <= s2.size(); j++) cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    cout << dp[s1.size()][s2.size()];
}