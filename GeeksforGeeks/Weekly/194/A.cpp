// User function Template for C++
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


class Solution {
  public:
    int c(int x) {
        int m = to_string(x).size();
        long long num = 0;
        while (m--) {
            num *= 10;
            num += 9;
        }
        return num - x;
    }
    
    
    long long countPairs(vector<int>& arr) {
        int n = arr.size();
        
        map<int, int> m;
        long long cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            cnt += m[arr[i]];
            m[c(arr[i])]++;
        }
        return cnt;
    }
};