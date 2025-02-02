class Solution {
  public:
    vector<int> absDifference(string& s) {
        vector<int> ans;
        string cs = "aeiou";
        int isc = 0, isnotc = 0;
        for (char c: s) {
            bool b = false;
            for (int i = 0; i < 5; i++) if (c == cs[i]) b = true;
            if (b) isc++;
            else isnotc++;
            ans.push_back(abs(isc - isnotc));
        }
        return ans;
    }
};