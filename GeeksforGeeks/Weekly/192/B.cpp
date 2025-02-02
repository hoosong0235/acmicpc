class Solution {
  public:
    int maxLength(vector<int> &arr) {
        map<int, int> m;
        for (int i: arr) m[i]++;
        
        // for (pair<int, int> p: m) {
        //     cout << p.first << ':' << p.second << '\n';
        // }
        
        map<int, int> n;
        for (pair<int, int> p: m) for (pair<int, int> q: m) {
            if (p.first == q.first) n[2 * p.first] += 2 * (p.second / 2);
            else n[p.first + q.first] += min(p.second, q.second);
        }
        for (pair<int, int> p: n) n[p.first] /= 2;
        for (pair<int, int> p: m) n[p.first] += p.second;
        
        // for (pair<int, int> p: n) {
        //     cout << p.first << ':' << p.second << '\n';
        // }
        
        int max_num = INT_MIN;
        for (pair<int, int> p: n) max_num = max(max_num, p.second);
        return max_num - 1;
    }
};