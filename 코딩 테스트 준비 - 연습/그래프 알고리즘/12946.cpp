#include <bits/stdc++.h>
using namespace std;


int n, max_num = 0;
int dx[6] = {0, 1, 1, 0, -1, -1};
int dy[6] = {1, 0, -1, -1, 0, 1};
char a[50][50];
int visited[50][50];


int solve(int x, int y) {
    bool is1 = false, is2 = false;
    for (int d = 0; d < 6; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (!(0 <= nx && nx < n && 0 <= ny && ny < n)) continue;
        if (a[nx][ny] == 'X' && visited[nx][ny]) {
            if (visited[nx][ny] == 1) is1 = true;
            if (visited[nx][ny] == 2) is2 = true;
        }
    }
    
    if (is1 && is2) {
        cout << '3'; exit(0);
    } else if (is1) {
        return 2;
    } else if (is2) {
        return 1;
    } else {
        return -1;
    }
}


void dfs(int x, int y) {
    for (int d = 0; d < 6; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (!(0 <= nx && nx < n && 0 <= ny && ny < n)) continue;
        if (a[nx][ny] == 'X' && !visited[nx][ny]) {
            visited[nx][ny] = solve(nx, ny);
            max_num = max(max_num, visited[nx][ny]);
            dfs(nx, ny);
        }
    }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (a[i][j] == 'X' && !visited[i][j]) {
        visited[i][j] = 1;
        max_num = max(max_num, visited[i][j]);
        dfs(i, j);
    }
    
    cout << max_num;
}