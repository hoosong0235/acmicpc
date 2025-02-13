// 00:24:21
#include <bits/stdc++.h>
using namespace std;
#define N 50


int n;
int a[N][9];
vector<int> orders(9);


int out, order, score;
bool runners[3];


void run(int i) {
    for (int j = 3 - i; j < 3; j++)
        if (runners[j])
            runners[j] = false, score++;
    for (int j = 3 - i - 1; j >= 0; j--)
        if (runners[j])
            runners[j] = false, runners[j + i] = true;
}


void one() { run(1); runners[0] = true; }
void two() { run(2); runners[1] = true; }
void three() { run(3); runners[2] = true; }
void four() { run(3); score++; }
void zero() { out++; }


void solve() {
    out = 0, order = 0, score = 0;
    for (int i = 0; i < n; i++) {
        while (out < 3) {
            switch (a[i][orders[order]]) {
                case 1: one(); break;
                case 2: two(); break;
                case 3: three(); break;
                case 4: four(); break;
                case 0: zero(); break;
                default: break;
            }
            order = (order + 1) % 9;
        }
        out = 0;
        for (int i = 0; i < 3; i++) runners[i] = false;
    }
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < 9; j++) cin>> a[i][j];
    
    vector<int> suborders(8);
    for (int i = 0; i < 8; i++) suborders[i] = i + 1;
    
    int max_num = 0;
    do {
        for (int i = 0; i < 3; i++) orders[i] = suborders[i];
        orders[3] = 0;
        for (int i = 4; i < 9; i++) orders[i] = suborders[i - 1];
        
        solve();
        max_num = max(max_num, score);
    } while (next_permutation(suborders.begin(), suborders.end()));
    cout << max_num;
}