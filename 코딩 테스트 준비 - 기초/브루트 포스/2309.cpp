#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    vector<int> heights(9);
    for (int i=0; i<9; i++) cin >> heights[i];
    sort(heights.begin(), heights.end());
    
    for (int i=0; i<9; i++) {
        for (int j=0; i!=j && j<9; j++) {
            if (accumulate(heights.begin(), heights.end(), 0) - heights[i] - heights[j] == 100) {
                for (int k=0; k<9; k++) if (k!=i && k!=j) cout << heights[k] << '\n';
                return 0;
            }
        }
    }
    
    return 0;
}