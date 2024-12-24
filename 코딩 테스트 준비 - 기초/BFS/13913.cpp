#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   	
	int n, k; cin >> n >> k;
	vector<int> visited(100001, 0);
	vector<int> previous(100001, -1);
	deque<pair<int, int>> q;

	visited[n] = 1;
	q.push_back({n, 0});
	
	while (!q.empty()) {
		pair<int, int> curr = q.front();
		int p = curr.first, d = curr.second;
		q.pop_front();
		
		if (p == k) {
			cout << d << "\n";
			list<int> is;
			int i = p;
			while (i != -1) {
				is.push_front(i);
				i = previous[i];
			}
			for (int i: is) cout << i << ' ';
			break;
		}
		
		if (p) if (!visited[p - 1]) {
			visited[p - 1] = 1;
			previous[p - 1] = p;
			q.push_back({p - 1, d + 1});
		}
		if (p <= 100000) if (!visited[p + 1]) {
			visited[p + 1] = 1;
			previous[p + 1] = p;
			q.push_back({p + 1, d + 1});
		}
		if (p <= 50000) if (!visited[p * 2]) {
			visited[p * 2] = 1;
			previous[p * 2] = p;
			q.push_back({p * 2, d + 1});
		}
	}
	
    return 0;
}