// 00:17:40
#include <bits/stdc++.h>
using namespace std;
#define N 3
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


int a[N][N], b[N][N], min_num = INT_MAX;
const pair<int, int> ls[8][3] = {
    {{ 0, 0 }, { 0, 1 }, { 0, 2 }}, // 1st row
    {{ 1, 0 }, { 1, 1 }, { 1, 2 }}, // 2nd row
    {{ 2, 0 }, { 2, 1 }, { 2, 2 }}, // 3rd row
    {{ 0, 0 }, { 1, 0 }, { 2, 0 }}, // 1st col
    {{ 0, 1 }, { 1, 1 }, { 2, 1 }}, // 2nd col
    {{ 0, 2 }, { 1, 2 }, { 2, 2 }}, // 3rd col
    {{ 0, 0 }, { 1, 1 }, { 2, 2 }}, // lt-rb dia
    {{ 0, 2 }, { 1, 1 }, { 2, 0 }}, // rt-lb dia
};
int magics[8];
bool visited[N * N + 1];


bool check() {
    int magic = 0;
    for (auto p: ls[0])
        magic += b[p.first][p.second];
        
    for (int i = 0; i < 8; i++) {
        int num = 0;
        for (auto p: ls[i])
            num += b[p.first][p.second];
        if (magic != num)
            return false;
    }
    return true;
}


int calc() {
    int num = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            num += abs(a[i][j] - b[i][j]);
    return num;
}


void solve(int d) {
    if (d == 9) {
        if (check())
            min_num = min(min_num, calc());
        return;
    }
    
    int i = d / N, j = d % N;
    for (int k = 1; k <= 9; k++)
        if (!visited[k]) {
            b[i][j] = k;
            visited[k] = true;
            solve(d + 1);
            visited[k] = false;
            // b[i][j] = 0;
        }
}


int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];
            
    solve(0);
    cout << min_num;
}