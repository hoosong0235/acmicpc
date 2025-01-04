#include <bits/stdc++.h>
using namespace std;


int n;
bool b;
vector<vector<int>> v(9, vector<int>(9));
vector<vector<bool>> visited(10, vector<bool>(10));
const vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};


bool check(int r, int c, int cand) {
	for (int i = 0; i < 9; i++) if (cand == v[i][c]) return false;
	for (int j = 0; j < 9; j++) if (cand == v[r][j]) return false;
	int R = 3 * (r / 3), C = 3 * (c / 3);
	for (int i = R; i < R + 3; i++) for (int j = C; j < C + 3; j++) if (cand == v[i][j]) return false;
	return true;
}


void solve(int d) {
	if (d == 36 - n) {
		b = true; return;
	}

    for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) if (!v[i][j]) {
        for (pair<int, int> dir: dirs) {
            int ni = i + dir.first, nj = j + dir.second;
            if (!(0 <= ni && ni < 9 && 0 <= nj && nj < 9)) continue;
            if (v[ni][nj]) continue;
            
            for (int cand1 = 1; cand1 < 10; cand1++) if (check(i, j, cand1)) {
                v[i][j] = cand1;
                for (int cand2 = 1; cand2 < 10; cand2++) if (check(ni, nj, cand2) && !visited[cand1][cand2]) {
                    v[ni][nj] = cand2;
                    visited[cand1][cand2] = true; visited[cand2][cand1] = true;
                    
                    solve(d + 1);
                    if (b) return;
                    
                    v[ni][nj] = 0;
                    visited[cand1][cand2] = false; visited[cand2][cand1] = false;
                }
                v[i][j] = 0;
            }
        }
        
        return;
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int cnt = 0;
    cin >> n;
    while (n) {
        for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) {
            v[i][j] = 0;
            visited[i + 1][j + 1] = i == j;
        }
        for (int i = 0; i < n; i++) {
            int i1, i2; string s1, s2; cin >> i1 >> s1 >> i2 >> s2;
            v[s1[0] - 'A'][s1[1] - '1'] = i1; v[s2[0] - 'A'][s2[1] - '1'] = i2;
            visited[i1][i2] = true; visited[i2][i1] = true;
        }
        for (int i = 1; i < 10; i++) {
            string s; cin >> s;
            v[s[0] - 'A'][s[1] - '1'] = i;
        }
        
        b = false;
        solve(0);
        
        cout << "Puzzle " << ++cnt << '\n';
        for (int i = 0; i < 9; i++) { for (int j = 0; j < 9; j++) cout << v[i][j]; cout << '\n'; }
        cin >> n;
    }
    
	return 0;
}