// 00:39:08
#include <bits/stdc++.h>
using namespace std;


const int points[4][22] = {
	{	0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20,
		22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0
	},
	{ 10, 13, 16, 19, 25, 30, 35, 40, 0 },
	{ 20, 22, 24, 25, 30, 35, 40, 0 },
	{ 30, 28, 27, 26, 25, 30, 35, 40, 0 }
};
pair<int, int> horses[4] = {
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
};
int dices[10];
int max_num = 0;


bool move(int depth, int h) {
	int dice = dices[depth];
	int x = horses[h].first, y = horses[h].second;

	while (dice--)
		if (points[x][++y] == 0) {
			horses[h] = { x, y };
			return true;
		}

	switch (points[x][y]) {
	case 10:
		x = 1, y = 0;
		break;
	case 20:
		x = 2, y = 0;
		break;
	case 30:
	    if (x == 0)
		    x = 3, y = 0;
		break;
	default:
		break;
	}

	for (auto horse: horses) {
		int hx = horse.first, hy = horse.second;
		if (horse.first == x && horse.second == y)
			return false;
		if (points[hx][hy] == 25 && points[x][y] == 25)
			return false;
		if (
		    (points[hx][hy] == 30 && points[x][y] == 30) &&
		    !(hx == 3 && hy == 0) && !(x == 3 && y == 0)
	    )
		    return false;
		if (points[hx][hy] == 35 && points[x][y] == 35)
			return false;
		if (points[hx][hy] == 40 && points[x][y] == 40)
			return false;
	}

	horses[h] = { x, y };
// 	cout << depth << ':' << ' ';
// 	for (auto horse: horses) cout << horse.first << ' ' << horse.second << ' ';
// 	cout << '\n';
	return true;
}


void solve(int depth, int num) {
	if (depth == 10) {
		max_num = max(max_num, num);
		return;
	}

	for (int h = 0; h < 4; h++) {
		int cx = horses[h].first, cy = horses[h].second;
		if (!(cx == 0 && cy == 0) && points[cx][cy] == 0) continue;
		if (move(depth, h)) {
			int nx = horses[h].first, ny = horses[h].second;
			solve(depth + 1, num + points[nx][ny]);
			horses[h] = { cx, cy };
		}
	}
}


int main() {
	for (int i = 0; i < 10; i++) cin >> dices[i];
	solve(0, 0);
	cout << max_num;
}