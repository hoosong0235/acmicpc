#include <bits/stdc++.h>
using namespace std;
#define MAX 100


struct bfs {
    int x, y;
};


int n, pcnt = 0, ccnt = 0;
char prr[MAX][MAX];
char crr[MAX][MAX];
bool pvstd[MAX][MAX];
bool cvstd[MAX][MAX];
deque<bfs> q;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};


void psolve(int x, int y) {
    pvstd[x][y] = true;
    q.push_back(bfs{x, y});
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        for (int d = 0; d < 4; d++) {
            int nx = c.x + dx[d], ny = c.y + dy[d];
            if (!(0 <= nx && nx < n && 0 <= ny && ny < n)) continue;
            if (!pvstd[nx][ny] && prr[nx][ny] == prr[x][y]) {
                pvstd[nx][ny] = true;
                q.push_back(bfs{nx, ny});
            }
        }
    }
    pcnt++;
}


void csolve(int x, int y) {
    cvstd[x][y] = true;
    q.push_back(bfs{x, y});
    while (!q.empty()) {
        bfs c = q.front(); q.pop_front();
        for (int d = 0; d < 4; d++) {
            int nx = c.x + dx[d], ny = c.y + dy[d];
            if (!(0 <= nx && nx < n && 0 <= ny && ny < n)) continue;
            if (!cvstd[nx][ny] && crr[nx][ny] == crr[x][y]) {
                cvstd[nx][ny] = true;
                q.push_back(bfs{nx, ny});
            }
        }
    }
    ccnt++;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> prr[i][j];
        crr[i][j] = prr[i][j] == 'B' ? 'B' : 'R';
    }
    
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (!pvstd[i][j]) psolve(i, j);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (!cvstd[i][j]) csolve(i, j);
    
    cout << pcnt << ' ' << ccnt;
    
}