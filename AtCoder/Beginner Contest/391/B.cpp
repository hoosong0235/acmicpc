#include <bits/stdc++.h>
using namespace std;
#define MAX 50


int n, m;
char s[MAX][MAX], t[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string st; cin >> st;
        for (int j = 0; j < n; j++) s[i][j] = st[j];
    }
    for (int i = 0; i < m; i++) {
        string st; cin >> st;
        for (int j = 0; j < m; j++) t[i][j] = st[j];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool b = true;
            for (int x = i; x < i + m; x++) {
                for (int y = j; y < j + m; y++) {
                    if (s[x][y] != t[x - i][y - j]) b = false;
                }
            }
            if (b) {
                cout << i + 1 << ' ' << j + 1;
                return 0;
            }
        }
    }
}