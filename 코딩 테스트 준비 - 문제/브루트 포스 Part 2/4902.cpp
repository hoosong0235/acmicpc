// 00:51:28
#include <bits/stdc++.h>
using namespace std;
#define N 400


int n;
int a[N + 1][2 * N], s[N + 1][2 * N];


void debug() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 2 * i; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 2 * i; j++) {
            cout << s[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    for (int t = 1; true; t++) {
        cin >> n;
        if (n == 0) return 0;
        
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < 2 * i; j++) {
                cin >> a[i][j];
                s[i][j] = s[i][j - 1] + a[i][j];
            }
        
        int max_num = INT_MIN;
        // pos
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < 2 * i; j += 2) {
                int num = 0;
                for (int k = 0; k <= n - i; k++) {
                    num += s[i + k][2 * k + j] - s[i + k][j - 1];
                    max_num = max(max_num, num);
                }
            }
        // neg
        for (int i = n; i >= 1; i--)
            for (int j = 2; j < 2 * i; j += 2) {
                int num = 0;
                for (int k = 0; k < min(j / 2, i - j / 2); k++) {
                    num += s[i - k][j] - s[i - k][j - 2 * k - 1];
                    max_num = max(max_num, num);
                }
            }
        cout << t << ". " << max_num << '\n';
    }
}