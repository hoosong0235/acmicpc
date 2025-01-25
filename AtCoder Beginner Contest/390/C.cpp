#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int h, w; cin >> h >> w;
    char a[1000][1000];
    int minx = INT_MAX, maxx = INT_MIN, miny = INT_MAX, maxy = INT_MIN;
    for (int i = 0; i < h; i++) {
        string s; cin >> s;
        for (int j = 0; j < w; j++) {
            a[i][j] = s[j];
            if (a[i][j] == '#') {
                minx = min(minx, i), maxx = max(maxx, i);
                miny = min(miny, j), maxy = max(maxy, j);
            }
        }
    }
    
    for (int i = minx; i <= maxx; i++) for (int j = miny; j <= maxy; j++) if (a[i][j] == '.') { cout << "No"; return 0; }
    cout << "Yes";
}