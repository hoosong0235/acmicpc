class Solution {
    public:
        bool hasSpecialSubstring(string s, int k) {
            int n = s.size();
            if (n - k == 0) {
                bool b = true;
                char c = s[0];
                for (int i = 0; i < n; i++) if (c != s[i]) b= false;
                return b;
            }
            
            for (int i = 0; i <= n - k; i++) {
                bool b = true;
                char c = s[i];
                if (0 < i && c == s[i - 1]) continue;
                if (i + k < n && c == s[i + k]) continue;
                for (int j = i; j < i + k; j++) if (c != s[j]) b = false;
                if (b) return true;
            }
            return false;
        }
    };