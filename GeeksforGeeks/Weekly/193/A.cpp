class Solution {
  public:
    int minOperation(string &s) {
        map<char, int> m;
        for (char c: s) m[c]++;
        
        string ls = "abcdefghijklmnopqrstuvwxyz";
        string us = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            char l = ls[i], u = us[i];
            if (m[l] != m[u]) cnt += abs(m[l] - m[u]);
        }
        return cnt / 2;
    }
};