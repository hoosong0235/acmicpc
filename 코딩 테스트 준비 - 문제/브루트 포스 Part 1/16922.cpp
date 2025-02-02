#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
#define N 20


int n;
bool dp[MAX + 1];


int main() {
    cin >> n;
    for (int j: { 1, 5, 10, 50 }) dp[j] = true;
    for (int i = 2; i <= n; i++) {
        for (int j = MAX; j >= 1; j--) if (dp[j]) {
            for (int k: { 1, 5, 10, 50 }) dp[j + k] = true;
            dp[j] = false;
        }
    }
    int cnt = 0;
    for (int j = 1; j <= MAX; j++) if (dp[j]) cnt++;
    cout << cnt;
}