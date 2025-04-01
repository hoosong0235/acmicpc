#include <bits/stdc++.h>
using namespace std;
#define N 100
#define M 2000
#define INF INT_MAX / 2
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

int n, m;
vector<tuple<int, int, int>> edges; // { a, b, w }
vector<vector<int>> f1(N, vector<int>(N, INF));
vector<vector<int>> f2(N, vector<int>(N, INF));

void floyd_warshall(int l) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            f2[i][j] = (i == j ? 0 : INF);
            
    for (int i = 0; i < m; i++)
        if (i != l) {
            auto [a, b, w] = edges[i];
            f2[a][b] = w, f2[b][a] = w;
        }
    
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                f2[i][j] = min(f2[i][j], f2[i][k] + f2[k][j]);
}

int calc() {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (f1[i][j] != f2[i][j])
                 cnt++;
    return cnt;                
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        edges.push_back({ a, b, w });
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            f1[i][j] = (i == j ? 0 : INF);
            
    for (int i = 0; i < m; i++) {
        auto [a, b, w] = edges[i];
        f1[a][b] = w, f1[b][a] = w;
    }
    
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                f1[i][j] = min(f1[i][j], f1[i][k] + f1[k][j]);
                
    for (int l = 0; l < m; l++) {
        floyd_warshall(l);
        cout << calc() << ' ';
    }
}