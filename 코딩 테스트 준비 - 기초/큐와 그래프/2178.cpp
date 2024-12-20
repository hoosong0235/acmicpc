#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> graph(101, vector<int>(101, 0 ));
vector<vector<int>> visited(101, vector<int>(101, 0));
deque<pair<pair<int, int>, int>> q;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, m, a, b; cin >> n >> m;
    string s;
    for (int i = 1; i < n + 1; i++) {
        cin >> s;
        for (int j = 1; j < m + 1; j++) graph[i][j] = s[j - 1] - '0';
    }
	
	visited[1][1] = 1;
	q.push_back({{1, 1}, 1});
	
	while (!q.empty()) {
		pair<pair<int, int>, int> curr = q.front();
		int i = curr.first.first, j = curr.first.second, d = curr.second;
		q.pop_front();
		
		if (i == n && j == m) {
			cout << d; break;
		}

		if (j > 1) if (graph[i][j - 1] && !visited[i][j - 1]) {
			visited[i][j - 1] = 1;
			q.push_back({{i, j - 1}, d + 1});
		}
		if (i > 1) if (graph[i - 1][j] && !visited[i - 1][j]) {
			visited[i - 1][j] = 1;
			q.push_back({{i - 1, j}, d + 1});
		}
		if (j < m) if (graph[i][j + 1] && !visited[i][j + 1]) {
			visited[i][j + 1] = 1;
			q.push_back({{i, j + 1}, d + 1});
		}
		if (i < n) if (graph[i + 1][j] && !visited[i + 1][j]) {
			visited[i + 1][j] = 1;
			q.push_back({{i + 1, j}, d + 1});
		}
	}
    
    return 0;
}