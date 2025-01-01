#include <bits/stdc++.h>
using namespace std;


int x, y;
vector<vector<int>> v(6, vector<int>(6));
vector<vector<int>> visited(6, vector<int>(6));
vector<bool> dice;
const vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};


void roll(int i) {
    bool tmp = dice[0];
    switch (i) {
        case 0:
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[3];
            dice[3] = tmp;
            break;
        case 1:
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[4];
            dice[4] = tmp;
            break;
        case 2:
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[2];
            dice[2] = tmp;
            break;
        case 3:
            dice[0] = dice[4];
            dice[4] = dice[5];
            dice[5] = dice[1];
            dice[1] = tmp;
            break;
        default:
            break;
    }
}


void dfs() {
    for (int i = 0; i < 4; i++) {
        int cx = x, cy = y, nx = x + dirs[i].first, ny = y + dirs[i].second;
        if (0 <= nx && nx < 6 && 0 <= ny && ny < 6 && v[nx][ny] && !visited[nx][ny]) {
            x = nx; y = ny; roll(i);
            visited[x][y] = true;
            dice[0] = v[x][y];
            dfs();
            x = cx; y = cy; roll((i + 2) % 4);
        }
    }
}


int main() {
    int w = 3;
    while (w--) {
        for (int i = 0; i < 6; i++) for (int j = 0; j < 6; j++) { cin >> v[i][j]; visited[i][j] = false; }
        for (int i = 0; i < 6; i++) for (int j = 0; j < 6; j++) if (v[i][j]) { x = i; y = j; break; }
        dice = {true, false, false, false, false, false};
        dfs();
        cout << (all_of(dice.begin(), dice.end(), [](bool b) { return b; }) ? "yes" : "no") << '\n';
    }
}