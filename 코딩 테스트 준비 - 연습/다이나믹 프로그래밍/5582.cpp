#include <bits/stdc++.h>
using namespace std;
#define MAX 4000


string s1, s2;
int dp[MAX + 1][MAX + 1];


int main() {
    cin >> s1 >> s2;
    
    int max_num = INT_MIN;
    for (int i = 1; i <= s1.size(); i++)
        for (int j = 1; j <= s2.size(); j++)
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                max_num = max(max_num, dp[i][j]);
            }
            
    cout << (max_num != INT_MIN ? max_num : 0);
}