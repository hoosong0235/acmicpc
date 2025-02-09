class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n = groups.size(), m = elements.size();
        
        vector<int> dp(100000 + 1, -1);
        for (int i = 0; i < m; i++) {
            int e = elements[i];
            if (dp[e] != -1) continue;
            for (int j = e; j <= 100000; j += e) if (dp[j] == -1) dp[j] = i;
        }
        
        vector<int> assigned(n);
        for (int i = 0; i < n; i++) {
            int g = groups[i];
            assigned[i] = dp[g];
        }
        
        return assigned;
    }
};