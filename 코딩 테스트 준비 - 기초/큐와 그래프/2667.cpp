#include <bits/stdc++.h>
using namespace std;


int n;
vector<vector<int>> graph(25, vector<int>(25, 0 ));
vector<vector<int>> visited(25, vector<int>(25, 0));
int cnt;
vector<int> cnts;


void dfs(int i, int j) {
    visited[i][j] = 1;
    cnt++;
    if (j) if (graph[i][j - 1] && !visited[i][j - 1]) dfs(i, j - 1);
    if (i) if (graph[i - 1][j] && !visited[i - 1][j]) dfs(i - 1, j);
    if (j < n - 1) if (graph[i][j + 1] && !visited[i][j + 1]) dfs(i, j + 1);
    if (i < n - 1) if (graph[i + 1][j] && !visited[i + 1][j]) dfs(i + 1, j);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int a, b; cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) graph[i][j] = s[j] - '0';
    }
    
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (graph[i][j] && !visited[i][j]) {
        cnt = 0;
        dfs(i, j);
        cnts.push_back(cnt);
    }
    
    sort(cnts.begin(), cnts.end());
    cout << cnts.size() << '\n';
    for (int cnt: cnts) cout << cnt << '\n';
    
    return 0;
}