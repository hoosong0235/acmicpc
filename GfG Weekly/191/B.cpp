//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int longestPalindrome(vector<int>& arr) {
        // code here
        int n = arr.size();
        int lp = 0, rp = n - 1;
        long long l = arr[lp++], r = arr[rp--];
        while (lp <= rp) {
            if (l < r) {
                l += arr[lp++], n--;
            } else if (l > r) {
                r += arr[rp--], n--;
            } else {
                l = arr[lp++], r = arr[rp--];
            }
        }
        return l == r ? n : n - 1;
    }
};

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        int v;
        vector<int> a;
        while (ss >> v) {
            a.push_back(v);
        }
        Solution ob;
        cout << ob.longestPalindrome(a) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends