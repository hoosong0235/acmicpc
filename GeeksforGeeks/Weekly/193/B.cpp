class Solution {
  public:
    int cntPairs(int x, int y) {
        int cnt = 1;
        for (int i = 0; i < 32; i++) {
            int bx = x & 1 << i, by = y & 1 << i;
            if (bx) {
                if (by) return -1;
                else continue;
            } else {
                if (by) cnt *= 2;
                else continue;
            }
        }
        return cnt;
    }
};