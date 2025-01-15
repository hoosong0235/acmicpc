#include <bits/stdc++.h>
using namespace std;
#define MAX 60


int n, s1, s2, s3, cnt = 0;
bool dp2[MAX + 1][MAX + 1];
bool dp3[MAX + 1][MAX + 1][MAX + 1];


int main() {
    cin >> n;
    if (n == 1) {
        cin >> s1;
        cout << s1 / 9 + (s1 % 9 ? 1 : 0);
    } else if (n == 2) {
        cin >> s1 >> s2;
        dp2[s1][s2] = true;
        while (!dp2[0][0]) {
            for (int i = 0; i <= MAX; i++)
                for (int j = 0; j <= MAX; j++)
                    if (dp2[i][j]) {
                        dp2[i - 9 >= 0 ? i - 9 : 0][j - 3 >= 0 ? j - 3 : 0] = true;
                        dp2[i - 3 >= 0 ? i - 3 : 0][j - 9 >= 0 ? j - 9 : 0] = true;
                    }
            cnt++;
        }
        cout << cnt;
    } else {
        cin >> s1 >> s2 >> s3;
        dp3[s1][s2][s3] = true;
        while (!dp3[0][0][0]) {
            for (int i = 0; i <= MAX; i++)
                for (int j = 0; j <= MAX; j++)
                    for (int k = 0; k <= MAX; k++)
                        if (dp3[i][j][k]) {
                            dp3[i - 9 >= 0 ? i - 9 : 0][j - 3 >= 0 ? j - 3 : 0][k - 1 >= 0 ? k - 1 : 0] = true;
                            dp3[i - 9 >= 0 ? i - 9 : 0][j - 1 >= 0 ? j - 1 : 0][k - 3 >= 0 ? k - 3 : 0] = true;
                            dp3[i - 3 >= 0 ? i - 3 : 0][j - 9 >= 0 ? j - 9 : 0][k - 1 >= 0 ? k - 1 : 0] = true;
                            dp3[i - 3 >= 0 ? i - 3 : 0][j - 1 >= 0 ? j - 1 : 0][k - 9 >= 0 ? k - 9 : 0] = true;
                            dp3[i - 1 >= 0 ? i - 1 : 0][j - 9 >= 0 ? j - 9 : 0][k - 3 >= 0 ? k - 3 : 0] = true;
                            dp3[i - 1 >= 0 ? i - 1 : 0][j - 3 >= 0 ? j - 3 : 0][k - 9 >= 0 ? k - 9 : 0] = true;
                        }
            cnt++;
        }
        cout << cnt;
    }
}