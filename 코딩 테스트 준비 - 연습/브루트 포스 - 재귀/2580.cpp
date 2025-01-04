#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> v(9, vector<int>(9));
vector<pair<int, int>> zs;


bool check(int r, int c, int cand) {
	for (int i = 0; i < 9; i++) if (cand == v[i][c]) return false;
	for (int j = 0; j < 9; j++) if (cand == v[r][j]) return false;
	int R = 3 * (r / 3), C = 3 * (c / 3);
	for (int i = R; i < R + 3; i++) for (int j = C; j < C + 3; j++) if (cand == v[i][j]) return false;
	return true;
}


void solve(int d) {
	if (d == zs.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) cout << v[i][j] << ' ';
			cout << '\n';
		}
		exit(0);
	}

    pair<int, int> z = zs[d];
    for (int cand = 1; cand < 10; cand++) if (check(z.first, z.second, cand)) {
        v[z.first][z.second] = cand;
        solve(d + 1);
        v[z.first][z.second] = 0;
    }
}


int main() {
	for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) {
		cin >> v[i][j];
		if (!v[i][j]) zs.push_back({i, j});
	}

	solve(0);
	return 0;
}