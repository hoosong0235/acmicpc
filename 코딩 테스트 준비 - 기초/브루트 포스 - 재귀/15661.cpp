#include <bits/stdc++.h>
using namespace std;


int n, diff, min_diff = INT_MAX, sum_starts, sum_links;
vector<vector<int>> matrix(20, vector<int>(20));
set<int> starts, links;


void solve(int k, int next_i) {
    if (!k) {
        links.clear();
        for (int i = 0; i < n; i++) if (!starts.count(i)) links.insert(i);
        
        sum_starts = 0; sum_links = 0;
        for (int i: starts) for (int j: starts) if (i != j) sum_starts += matrix[i][j];
        for (int i: links) for (int j: links) if (i != j) sum_links += matrix[i][j];
        
        diff = abs(sum_starts - sum_links);
        if (diff < min_diff) min_diff = diff;
        return;
    }
    
    for (int i = next_i; i < n; i++) {
        starts.insert(i);
        solve(k - 1, i + 1);
        starts.erase(starts.find(i));
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> matrix[i][j];
    for (int i = 1; i <= n / 2; i++) solve(i, 0);
    cout << min_diff;
    
    return 0;
}