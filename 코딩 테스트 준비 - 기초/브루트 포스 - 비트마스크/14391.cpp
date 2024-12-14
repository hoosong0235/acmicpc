#include <bits/stdc++.h>
using namespace std;


char c;
int n, m, max_sum = INT_MIN;
vector<vector<int>> matrix(4, vector<int>(4));
vector<vector<bool>> bitmask(4, vector<bool>(4));

void solve(int depth) {
    if (depth == n * m) {
        int sum = 0;
        
        for (int i=0; i<n; i++) {
            int num = 0;
            for (int j=0; j<m; j++) {
                if (!bitmask[i][j]) {
                    num *= 10;
                    num += matrix[i][j];
                } else {
                    sum += num;
                    num = 0;
                }
            }
            if (!bitmask[i][m-1]) sum += num;
        }
        
        for (int j=0; j<m; j++) {
            int num = 0;
            for (int i=0; i<n; i++) {
                if (bitmask[i][j]) {
                    num *= 10;
                    num += matrix[i][j];
                } else {
                    sum += num;
                    num = 0;
                }
            }
            if (bitmask[n-1][j]) sum += num;
        }
        
        max_sum = max(max_sum, sum);
    } else {
        bitmask[depth / m][depth % m] = false;
        solve(depth + 1);
        bitmask[depth / m][depth % m] = true;
        solve(depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        cin >> c;
        matrix[i][j] = c - '0';
    }
    
    solve(0); cout << max_sum;
    
    return 0;
}