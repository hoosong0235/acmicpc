class Solution {
    public:
      int totalWays(int n) {
          int a = 1;
          for (int i = log2(n); i >= 0; i--) {
              int bit = n & (1 << i);
              if (bit) a <<= 1;
              else continue;
          }
          
          int b = 1;
          bool c = false;
          for (int i = log2(n); i >= 0; i--) {
              int bit = n & (1 << i);
              if (!c && !bit) c = true;
              if (c) {
                  if (bit) b <<= 1;
                  else continue;
              }
          }
          
          return (c ? a - b : a);
      }
  };