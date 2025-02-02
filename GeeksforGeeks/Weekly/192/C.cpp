class Solution {
  public:
    int minCharacter(string& s, string& t) {
        // Longest Common Substring * Longest Common Subsequence
        int max_num = 0;
        int dp[s.length() + 1][t.length() + 1] = {};
        for (int i = 1; i <= s.length(); i++) for (int j = 1; j <= t.length(); j++) {
            if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = dp[i - 1][j];
            max_num = max(max_num, dp[i][j]);
        }
        
        // Debug
        // cout << s.length() << ' ' << t.length() << '\n';
        // for (int i = 0; i <= s.length(); i++) {
        //     for (int j = 0; j <= t.length(); j++) cout << dp[i][j] << ' ';
        //     cout << '\n';
        // }
        
        return s.length() - max_num;
    }
};