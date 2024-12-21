#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> graph(1001, vector<int>(1001, 0 ));
vector<vector<int>> visited(1001, vector<int>(1001, 0));
deque<pair<pair<int, int>, int>> q;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
	int n, m; cin >> m >> n;
	for (int i = 1; i < n + 1; i++) for (int j = 1; j < m + 1; j++) cin >> graph[i][j];
	
	for (int i = 1; i < n + 1; i++) for (int j = 1; j < m + 1; j++) if (graph[i][j] == 1) {
		visited[i][j] = 1;
		q.push_back({{i, j}, 0});
	}
	
	int max_num = 0;
	while (!q.empty()) {
		pair<pair<int, int>, int> curr = q.front();
		int i = curr.first.first, j = curr.first.second, d = curr.second;
		q.pop_front();
		
		max_num = max(max_num, d);

		if (j > 1) if (graph[i][j - 1] == 0 && !visited[i][j - 1]) {
			visited[i][j - 1] = 1;
			q.push_back({{i, j - 1}, d + 1});
		}
		if (i > 1) if (graph[i - 1][j] == 0 && !visited[i - 1][j]) {
			visited[i - 1][j] = 1;
			q.push_back({{i - 1, j}, d + 1});
		}
		if (j < m) if (graph[i][j + 1] == 0 && !visited[i][j + 1]) {
			visited[i][j + 1] = 1;
			q.push_back({{i, j + 1}, d + 1});
		}
		if (i < n) if (graph[i + 1][j] == 0 && !visited[i + 1][j]) {
			visited[i + 1][j] = 1;
			q.push_back({{i + 1, j}, d + 1});
		}
	}
    
	for (int i = 1; i < n + 1; i++) for (int j = 1; j < m + 1; j++) if (graph[i][j] == 0 && !visited[i][j]) {
		cout << -1; exit(0);
	}
	cout << max_num;
    return 0;
}