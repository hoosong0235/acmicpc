#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


string s1, s2;
int dp[MAX + 1][MAX + 1];


int main() {
    cin >> s1 >> s2;
    
    for (int i = 1; i <= s1.size(); i++)
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    
    int i = s1.size(), j = s2.size();
    cout << dp[i][j];
    if (!dp[i][j]) return 0;
    
    string s;
    while (i && j) {
        if (dp[i - 1][j] == dp[i][j]) i--;
        else if (dp[i][j - 1] == dp[i][j]) j--;
        else s = s1[i - 1] + s, i--, j--;
    }
    cout << '\n' << s;
}