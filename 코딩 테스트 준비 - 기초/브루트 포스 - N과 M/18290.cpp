#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<vector<int>> matrix(10, vector<int>(10, 0));
vector<vector<int>> visited(10, vector<int>(10, 0));
list<int> selecteds;


int solve(int curr_i, int curr_j, int k) {
    if (!k) return accumulate(selecteds.begin(), selecteds.end(), 0);
    int max_sum = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < curr_i || (i == curr_i && j < curr_j)) continue;
            if (!visited[i][j]) {
                selecteds.push_back(matrix[i][j]);
                visited[i][j]++;
                if (i) visited[i - 1][j]++;
                if (i != n - 1) visited[i + 1][j]++;
                if (j) visited[i][j - 1]++;
                if (j != m - 1) visited[i][j + 1]++;
                
                int sum = solve(i, j, k - 1);   
                if (max_sum < sum) max_sum = sum;
                
                if (j != m - 1) visited[i][j + 1]--;
                if (j) visited[i][j - 1]--;
                if (i != n - 1) visited[i + 1][j]--;
                if (i) visited[i - 1][j]--;
                visited[i][j]--;
                selecteds.pop_back();
            }
        }
    }
    return max_sum;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int k; cin >> n >> m >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> matrix[i][j];
    cout << solve(0, 0, k);
    
    return 0;
}