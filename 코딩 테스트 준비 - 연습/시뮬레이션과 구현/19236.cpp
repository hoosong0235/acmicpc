#include <bits/stdc++.h>
using namespace std;


struct shark {
    int x, y, s, d; // row, column, score, direction
};


struct bfs {
    shark s;
    vector<bool> eaten;
    vector<vector<pair<int, int>>> fs; // { num, dir }
    vector<pair<int, int>> poss; // { x, y }
};


int max_s = INT_MIN;
int rot[8] = { 1, 2, 3, 4, 5, 6, 7, 0 };
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
deque<bfs> q;


void debug(bfs c) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == c.s.x && j == c.s.y) cout << 'S' << ' ' << c.s.d + 1 << '\t';
            else if (c.eaten[c.fs[i][j].first]) cout << '\t';
            else cout << c.fs[i][j].first + 1 << ' ' << c.fs[i][j].second + 1 << '\t';
        }
        cout << '\n';
    }
    cout << '\n';
}


int main() {
    // init
    shark s = { 0, 0, 0, 0 };
    vector<bool> eaten(16, false);
    vector<vector<pair<int, int>>> fs(4, vector<pair<int, int>>(4));
    vector<pair<int, int>> poss(16);
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
        int f, d; cin >> f >> d;
        fs[i][j] = { f - 1, d - 1 };
        poss[f - 1] = { i, j };
    }
    s.s += fs[0][0].first + 1;
    s.d = fs[0][0].second;
    eaten[fs[0][0].first] = true;
    max_s = max(max_s, s.s);
    
    // bfs
    bfs c = { s, eaten, fs, poss };
    // debug(c);
    q.push_back(c);
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        
        // move fishes
        for (int f = 0; f < 16; f++) if (!c.eaten[f]) {
            pair<int, int> pos = c.poss[f];
            int x = pos.first, y = pos.second;
            int d = c.fs[x][y].second;
            int nx = x + dx[d], ny = y + dy[d];
            int cnt = 1;
            while ((nx == c.s.x && ny == c.s.y) || !(0 <= nx && nx < 4 && 0 <= ny && ny < 4)) {
                c.fs[x][y].second = rot[d];
                d = c.fs[x][y].second;
                nx = x + dx[d], ny = y + dy[d];
                if (++cnt > 8) break;
            }
            if (cnt > 8) continue;
            c.poss[c.fs[x][y].first] = { nx, ny };
            c.poss[c.fs[nx][ny].first] = { x, y };
            swap(c.fs[x][y], c.fs[nx][ny]);
        }
        // debug(c);
        
        // move shark
        int nx = c.s.x + dx[c.s.d], ny = c.s.y + dy[c.s.d];
        while (0 <= nx && nx < 4 && 0 <= ny && ny < 4) {
            if (!c.eaten[c.fs[nx][ny].first]) {
                shark s;
                s.x = nx, s.y = ny, s.s = c.s.s, s.d = c.s.d;
                vector<bool> eaten(16);
                for (int i = 0; i < 16; i++) eaten[i] = c.eaten[i];
                vector<vector<pair<int, int>>> fs(4, vector<pair<int, int>>(4));
                for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) fs[i][j] = c.fs[i][j];
                vector<pair<int, int>> poss(16);
                for (int i = 0; i < 16; i++) poss[i] = c.poss[i];
                
                s.s += fs[nx][ny].first + 1;
                s.d = fs[nx][ny].second;
                eaten[fs[nx][ny].first] = true;
                max_s = max(max_s, s.s);
                
                bfs n = bfs { s, eaten, fs, poss };
                // debug(n);
                q.push_back(n);
            }
            nx = nx + dx[c.s.d], ny = ny + dy[c.s.d];
        }
    }
    
    cout << max_s;
}