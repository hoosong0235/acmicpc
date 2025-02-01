class Solution {
public:
    string findValidPair(string s) {
        map<int, int> m;
        for (char c: s) m[c - '0']++;
        
        int ci = s[0] - '0';
        for (int i = 1; i < s.length(); i++) {
            char ni = s[i] - '0';
            if (ci != ni && m[ci] == ci && m[ni] == ni) return to_string(10 * ci + ni);
            ci = ni;
        }
        return "";
    }
};