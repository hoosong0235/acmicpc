#include <bits/stdc++.h>
using namespace std;


struct bfs {
    int d, rx, ry, bx, by;
};


int n, m, ox, oy, num = -1;
char board[10][10];
bool visited[10][10][10][10];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
deque<bfs> q;



bool check(int x, int y, int rx, int ry, int bx, int by, bool ro, bool bo) {
    if ((!ro && x == rx && y == ry) || (!bo && x == bx && y == by)) return false;
    return board[x][y] != '#';
}


void solve() {
    while (!q.empty()) {
        bfs st = q.front(); q.pop_front();
        // cout << st.d << ' ' << st.rx << ' ' << st.ry << ' ' << st.bx << ' ' << st.by << '\n';
        
        for (int d = 0; d < 4; d++) {
            int nrx = st.rx, nry = st.ry, nbx = st.bx, nby = st.by;
            bool ro = false, bo = false;
            bool rb = !ro && check(nrx + dx[d], nry + dy[d], nrx, nry, nbx, nby, ro, bo);
            bool bb = !bo && check(nbx + dx[d], nby + dy[d], nrx, nry, nbx, nby, ro, bo);
            while (rb || bb) {
                if (rb) { nrx += dx[d], nry += dy[d]; }
                if (bb) { nbx += dx[d], nby += dy[d]; }
                
                if (nrx == ox && nry == oy) { ro = true; }
                if (nbx == ox && nby == oy) { bo = true; }
                
                rb = !ro && check(nrx + dx[d], nry + dy[d], nrx, nry, nbx, nby, ro, bo);
                bb = !bo && check(nbx + dx[d], nby + dy[d], nrx, nry, nbx, nby, ro, bo);
            }
            
            if (bo) continue;
            if (ro) { num = st.d; return; }
            
            if (!visited[nrx][nry][nbx][nby] && st.d < 10) {
                q.push_back(bfs{st.d + 1, nrx, nry, nbx, nby});
                visited[nrx][nry][nbx][nby] = true;
            }
        }
    }
}


int main() {
    int rx, ry, bx, by;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'R') { rx = i, ry = j; }
            if (s[j] == 'B') { bx = i, by = j; }
            if (s[j] == 'O') { ox = i, oy = j; }
            board[i][j] = s[j];
        }
    }
    
    q.push_back(bfs{1, rx, ry, bx, by});
    visited[rx][ry][bx][by] = true;
    solve();
    cout << num;
    
    return 0;
}