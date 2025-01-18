#include <bits/stdc++.h>
using namespace std;
#define MAX 60


int n, a, b, c;


int main() {
    cin >> n;
    if (n == 1) {
        cin >> a;
        cout << (a / 9 + (a % 9 ? 1 : 0));
    } else if (n == 2) {
        struct bfs { int d, a, b; };
        bool visited[MAX + 1][MAX + 1];
        deque<bfs> q;
        int dmg[2][3] = {{9, 3}, {3, 9}};
        cin >> a >> b;
        visited[a][b] = true;
        q.push_back(bfs{0, a, b});
        while (!q.empty()) {
            bfs c = q.front(); q.pop_front();
            if (!c.a && !c.b) { cout << c.d; return 0; }
            for (int d = 0; d < 2; d++) {
                int na = c.a - dmg[d][0], nb = c.b - dmg[d][1];
                na = max(0, na), nb = max(0, nb);
                if (visited[na][nb]) continue;
                visited[na][nb] = true;
                q.push_back(bfs{c.d + 1, na, nb});
            }
        }
    } else {
        struct bfs { int d, a, b, c; };
        bool visited[MAX + 1][MAX + 1][MAX + 1];
        deque<bfs> q;
        int dmg[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 9, 3}, {1, 3, 9}};
        cin >> a >> b >> c;
        visited[a][b][c] = true;
        q.push_back(bfs{0, a, b, c});
        while (!q.empty()) {
            bfs c = q.front(); q.pop_front();
            if (!c.a && !c.b && !c.c) { cout << c.d; return 0; }
            for (int d = 0; d < 6; d++) {
                int na = c.a - dmg[d][0], nb = c.b - dmg[d][1], nc = c.c - dmg[d][2];
                na = max(0, na), nb = max(0, nb), nc = max(0, nc);
                if (visited[na][nb][nc]) continue;
                visited[na][nb][nc] = true;
                q.push_back(bfs{c.d + 1, na, nb, nc});
            }
        }
    }
}