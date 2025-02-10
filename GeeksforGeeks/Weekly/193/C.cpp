class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        int pp = pat.size() - 1, tp = tar.size() - 1;
        
        while (pp >= 0 && tp >= 0) {
            if (pat[pp] == tar[tp]) pp--, tp--;
            else pp -= 2;
        }
        
        return tp < 0;
    }
};