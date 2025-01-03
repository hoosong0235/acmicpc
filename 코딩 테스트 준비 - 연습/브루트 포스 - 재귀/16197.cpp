#include <bits/stdc++.h>
using namespace std;


int n, m, min_num = INT_MAX;
vector<vector<char>> v(20, vector<char>(20));
int c1x, c1y, c2x, c2y, c = 0;
const vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};


bool check1(int c1nx, int c1ny) {
    return 0 <= c1nx && c1nx < n && 0 <= c1ny && c1ny < m;
}


bool check2(int c2nx, int c2ny) {
    return 0 <= c2nx && c2nx < n && 0 <= c2ny && c2ny < m;
}


void solve(int d) {
    if (d > 10) return;
    
    switch (c) {
        case 0: return;
        case 1: min_num = min(min_num, d); return;
        case 2: 
            for (pair<int, int> dir: dirs) {
                int c1cx = c1x, c1cy = c1y, c2cx = c2x, c2cy = c2y;
                int c1nx = c1x + dir.first, c1ny = c1y + dir.second, c2nx = c2x + dir.first, c2ny = c2y + dir.second;
                if (check1(c1nx, c1ny) && check2(c2nx, c2ny) && v[c1nx][c1ny] == '#' && v[c2nx][c2ny] == '#') continue;
                if (!check1(c1nx, c1ny)) {
                    c--;
                } else if (v[c1nx][c1ny] != '#') {
                    c1x = c1nx; c1y = c1ny;
                }
                if (!check2(c2nx, c2ny)) {
                    c--;
                } else if (v[c2nx][c2ny] != '#') {
                    c2x = c2nx; c2y = c2ny;
                }
                solve(d + 1);
                if (!check1(c1nx, c1ny)) {
                    c++;
                } else if (v[c1nx][c1ny] != '#') {
                    c1x = c1cx; c1y = c1cy;
                }
                if (!check2(c2nx, c2ny)) {
                    c++;
                } else if (v[c2nx][c2ny] != '#') {
                    c2x = c2cx; c2y = c2cy;
                }
            }
        default: break;
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            v[i][j] = s[j];
            if (s[j] == 'o') {
                if (!c) {
                    c1x = i; c1y = j; c++;
                } else {
                    c2x = i; c2y = j; c++;
                }
            }
        }
    }
    
    solve(0);
    
    cout << (min_num != INT_MAX ? min_num : -1);
    
    return 0;
}