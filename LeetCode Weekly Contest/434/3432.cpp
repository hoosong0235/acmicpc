class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int k = 0; k < n - 1; k++) {
            int l = 0, r = 0;
            for (int i = 0; i < k + 1; i++) l += nums[i];
            for (int i = k + 1; i < n; i++) r += nums[i];
            if ((l - r) % 2 == 0) cnt++;
        }
        return cnt;
    }
};