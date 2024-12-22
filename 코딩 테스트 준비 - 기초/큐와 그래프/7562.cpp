#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   
	int t; cin >> t;
	while (t--) {
		int l, si, sj, ei, ej; cin >> l >> si >> sj >> ei >> ej;
		
		vector<vector<int>> visited(l + 1, vector<int>(l + 1, 0));
		deque<pair<pair<int, int>, int>> q;
	
		visited[si + 1][sj + 1] = 1;
		q.push_back({{si + 1, sj + 1}, 0});
	
		while (!q.empty()) {
			pair<pair<int, int>, int> curr = q.front();
			int i = curr.first.first, j = curr.first.second, d = curr.second;
			q.pop_front();
		
			if (i == ei + 1 && j == ej + 1) {
				cout << d << "\n";
				break;
			}

			if (i >= 3 && j >= 2) if (!visited[i - 2][j - 1]) {
				visited[i - 2][j - 1] = 1;
				q.push_back({{i - 2, j - 1}, d + 1});
			}
			if (i >= 2 && j >= 3) if (!visited[i - 1][j - 2]) {
				visited[i - 1][j - 2] = 1;
				q.push_back({{i - 1, j - 2}, d + 1});
			}
			if (i <= l - 1 && j >= 3) if (!visited[i + 1][j - 2]) {
				visited[i + 1][j - 2] = 1;
				q.push_back({{i + 1, j - 2}, d + 1});
			}
			if (i >= 2 && j <= l - 2) if (!visited[i - 1][j + 2]) {
				visited[i - 1][j + 2] = 1;
				q.push_back({{i - 1, j + 2}, d + 1});
			}
			if (i <= l - 2 && j >= 2) if (!visited[i + 2][j - 1]) {
				visited[i + 2][j - 1] = 1;
				q.push_back({{i + 2, j - 1}, d + 1});
			}
			if (i >= 3 && j <= l - 1) if (!visited[i - 2][j + 1]) {
				visited[i - 2][j + 1] = 1;
				q.push_back({{i - 2, j + 1}, d + 1});
			}
			if (i <= l - 1 && j <= l - 2) if (!visited[i + 1][j + 2]) {
				visited[i + 1][j + 2] = 1;
				q.push_back({{i + 1, j + 2}, d + 1});
			}
			if (i <= l - 2 && j <= l - 1) if (!visited[i + 2][j + 1]) {
				visited[i + 2][j + 1] = 1;
				q.push_back({{i + 2, j + 1}, d + 1});
			}
		}
	}
	
    return 0;
}