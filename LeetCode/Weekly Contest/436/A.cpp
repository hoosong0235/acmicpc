class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {        
        int n = grid.size();
        int m = 2 * n - 1;
        vector<vector<int>> ans(n, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            int cnt = i < n ? i + 1 : m - i;
            
            vector<int> sorted(cnt);
            for (int j = 0; j < cnt; j++) {
                int x = i < n ? i - j : n - 1 - j;
                int y = i < n ? n - 1 - j : m - 1 - i - j;
                sorted[j] = grid[x][y];
            }
            
            if (i < n - 1) sort(sorted.begin(), sorted.end(), greater<int>());
            else sort(sorted.begin(), sorted.end(), less<int>());
            
            for (int j = 0; j < cnt; j++) {
                int x = i < n ? i - j : n - 1 - j;
                int y = i < n ? n - 1 - j : m - 1 - i - j;
                ans[x][y] = sorted[j];
            }
        }
        
        return ans;
    }
    
};