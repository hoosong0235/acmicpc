#include <bits/stdc++.h>
using namespace std;


int n;
vector<vector<char>> matrix(10, vector<char>(10, 0));
vector<int> ans;


void solve(int cnt) {
    if (cnt == n) {
        for (int a: ans) cout << a << ' ';
        exit(0);
    }
    
    int max_min = -10, min_max = 10;
    for (int i=0; i<cnt+1; i++) {
        int j = cnt;
        int sum = 0;
        for (int k=i; k<cnt; k++) sum += ans[k];
        
        if (matrix[i][j] == '0') {
            if (-10 > -1 * sum || 10 < -1 * sum) return;
            max_min = -1 * sum;
            min_max = -1 * sum;
        } else if (matrix[i][j] == '+') {
            max_min = max(max_min, -1 * sum + 1);
        } else {
            min_max = min(min_max, -1 * sum - 1);
        }
    }
    
    for (int num=max_min; num<=min_max; num++) {
        ans.push_back(num);
        solve(cnt + 1);
        ans.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            cin >> matrix[i][j];
        }
    }
    solve(0);
    
    return 0;
}