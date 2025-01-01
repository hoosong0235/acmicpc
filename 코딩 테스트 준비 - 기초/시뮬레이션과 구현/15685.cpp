#include <bits/stdc++.h>
using namespace std;


const vector<pair<int, int>> dirs = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
vector<vector<bool>> visited(101, vector<bool>(101, false));
vector<int> es;

int main() {
    int n; cin >> n;
    while (n--) {
        int x, y, d, g; cin >> x >> y >> d >> g;
        es = {d};
        while (g--) for (int i = es.size() - 1; i >= 0; i--) es.push_back((es[i] + 1) % 4);
        visited[x][y] = true;
        for (int e: es) {
            x += dirs[e].first;
            y += dirs[e].second;
            visited[x][y] = true;
        }
    }
    
    int cnt = 0;
    for (int i = 0; i < 100; i++) for (int j = 0; j < 100; j++) if (visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1]) cnt++;
    cout << cnt;
    
    return 0;
}