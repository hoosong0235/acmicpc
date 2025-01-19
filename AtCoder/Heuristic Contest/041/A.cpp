#include <bits/stdc++.h>
using namespace std;
#define N 1000


struct bfs {
    int d, i;
};


int n, m, h;
bool graph[N][N];
pair<int, int> vs[N];
int bs[N];
int ps[N];
int cnt = 0;
bool visited[N];
deque<bfs> q;


void solve(int d, int i) {
    if (d >= 10) return;
    
    for (int j = 0; j < N; j++) if (graph[i][j] && !visited[j]) {
        ps[j] = i;
        visited[j] = true; cnt++;
        solve(d + 1, j);
    }
}


int main() {
    cin >> n >> m >> h;
    for (int i = 0; i < N; i++) cin >> bs[i];
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        graph[a][b] = true, graph[b][a] = true;
    }
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        vs[i] = {a, b};
    }
    
    while (cnt < N) {
        int min_num = INT_MAX, min_index;
        for (int i = 0; i < N; i++) if (!visited[i] && bs[i] < min_num) min_num = bs[i], min_index = i;
        ps[min_index] = -1;
        visited[min_index] = true; cnt++;
        solve(0, min_index);
    }
    
    for (int i = 0; i < N; i++) cout << ps[i] << ' ';
}