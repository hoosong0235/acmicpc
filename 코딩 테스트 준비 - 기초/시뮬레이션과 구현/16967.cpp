#include <bits/stdc++.h>
using namespace std;


int h, w, x, y;
vector<vector<int>> a(300, vector<int>(300, -1));
vector<vector<int>> b(600, vector<int>(600));


int main() {
    cin >> h >> w >> x >> y;
    for (int i = 0; i < h + x; i++) for (int j = 0; j < w + y; j++) cin >> b[i][j];
    
    for (int i = 0; i < x; i++) for (int j = 0; j < w; j++) a[i][j] = b[i][j];
    for (int i = 0; i < h; i++) for (int j = 0; j < y; j++) a[i][j] = b[i][j];
    for (int i = h; i < h + x; i++) for (int j = y; j < w + y; j++) a[i - x][j - y] = b[i][j];
    for (int i = x; i < h + x; i++) for (int j = w; j < w + y; j++) a[i - x][j - y] = b[i][j];
    for (int i = x; i < h; i++) for (int j = y; j < w; j++) {
        if (a[i - x][j - y] != -1) a[i][j] = b[i][j] - a[i - x][j - y];
        if (a[i][j] != -1) a[i - x][j - y] = b[i][j] - a[i][j];
    }
    
    for (int i = 0; i < h; i++) { for (int j = 0; j < w; j++) cout << a[i][j] << ' '; cout << '\n'; }
}