//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minOperations(int x, int y) {
        // code here
        if (x % 2) return -1;
        if (y % 2) return -1;
        int ans = 0;
        ans += abs(x) / 4;
        ans += abs(y) / 4;
        if (x % 4) ans += 1;
        if (y % 4) ans += 1;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.minOperations(x, y) << endl;
    }

    return 0;
}

// } Driver Code Ends