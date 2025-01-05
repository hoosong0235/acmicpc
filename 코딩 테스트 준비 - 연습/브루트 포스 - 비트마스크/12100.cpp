#include <bits/stdc++.h>
using namespace std;


int n, max_num = INT_MIN;


void solve(int d, int curr[20][20]) {
    if (d > 4) return;
    
    // cout << d << '\n'; for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) cout << curr[i][j] << ' '; cout << '\n'; }
    
    int next[20][20];
    bool visited[20][20];
    
    // L
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) { next[i][j] = curr[i][j]; visited[i][j] = false; }
    for (int j = 1; j < n; j++) for (int i = 0; i < n; i++) {
        for (int k = j - 1; k >= 0; k--) {
            if (!next[i][k]) {
                swap(next[i][k + 1], next[i][k]);
                swap(visited[i][k + 1], visited[i][k]);
            } else {
                if (visited[i][k] || visited[i][k + 1]) break;
                
                if (next[i][k + 1] == next[i][k]) {
                    next[i][k + 1] = 0;
                    next[i][k] *= 2;
                    visited[i][k] = true;
                    max_num = max(max_num, next[i][k]);
                } else {
                    break;
                }
            }
        }
    }
    solve(d + 1, next);
    
    // T
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) { next[i][j] = curr[i][j]; visited[i][j] = false; }
    for (int i = 1; i < n; i++) for (int j = 0; j < n; j++) {
        for (int k = i - 1; k >= 0; k--) {
            if (!next[k][j]) {
                swap(next[k + 1][j], next[k][j]);
                swap(visited[k + 1][j], visited[k + 1][j]);
            } else {
                if (visited[k][j] || visited[k + 1][j]) break;
                
                if (next[k + 1][j] == next[k][j]) {
                    next[k + 1][j] = 0;
                    next[k][j] *= 2;
                    visited[k][j] = true;
                    max_num = max(max_num, next[k][j]);
                } else {
                    break;
                }
            }
        }
    }
    solve(d + 1, next);
    
    // R
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) { next[i][j] = curr[i][j]; visited[i][j] = false; }
    for (int j = n - 2; j >= 0; j--) for (int i = 0; i < n; i++) {
        for (int k = j + 1; k < n; k++) {
            if (!next[i][k]) {
                swap(next[i][k - 1], next[i][k]);
                swap(visited[i][k - 1], visited[i][k]);
            } else {
                if (visited[i][k] || visited[i][k - 1]) break;
                
                if (next[i][k - 1] == next[i][k]) {
                    next[i][k - 1] = 0;
                    next[i][k] *= 2;
                    visited[i][k] = true;
                    max_num = max(max_num, next[i][k]);
                } else {
                    break;
                }
            }
        }
    }
    solve(d + 1, next);
    
    // B
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) { next[i][j] = curr[i][j]; visited[i][j] = false; }
    for (int i = n - 2; i >= 0; i--) for (int j = 0; j < n; j++) {
        for (int k = i + 1; k < n; k++) {
            if (!next[k][j]) {
                swap(next[k - 1][j], next[k][j]);
                swap(visited[k - 1][j], visited[k][j]);
            } else {
                if (visited[k][j] || visited[k - 1][j]) break;
                
                if (next[k - 1][j] == next[k][j]) {
                    next[k - 1][j] = 0;
                    next[k][j] *= 2;
                    visited[k][j] = true;
                    max_num = max(max_num, next[k][j]);
                } else {
                    break;
                }
            }
        }
    }
    solve(d + 1, next);
}


int main() {
    cin >> n;
    int curr[20][20];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> curr[i][j]; max_num = max(max_num, curr[i][j]);
    }
    
    solve(0, curr);
    cout << max_num;
    
    return 0;
}