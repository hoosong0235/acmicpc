#include <bits/stdc++.h>
using namespace std;


int n, m;
vector<vector<int>> C(100, vector<int>(100)), N(100, vector<int>(100));


void f1() {
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) N[i][j] = C[(n - 1) - i][j];
}

void f2() {
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) N[i][j] = C[i][(m - 1) - j];
}

void f3() {
    swap(n, m); for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) N[i][j] = C[(m - 1) - j][i];
}

void f4() {
    swap(n, m); for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) N[i][j] = C[j][(n - 1) - i];
}

void f5() {
    int n2 = n / 2, m2 = m / 2;
    for (int i = 0; i < n2; i++) for (int j = 0; j < m2; j++) N[i][j] = C[i + n2][j];
    for (int i = 0; i < n2; i++) for (int j = m2; j < m; j++) N[i][j] = C[i][j - m2];
    for (int i = n2; i < n; i++) for (int j = m2; j < m; j++) N[i][j] = C[i - n2][j];
    for (int i = n2; i < n; i++) for (int j = 0; j < m2; j++) N[i][j] = C[i][j + m2];
}

void f6() {
    int n2 = n / 2, m2 = m / 2;
    for (int i = 0; i < n2; i++) for (int j = 0; j < m2; j++) N[i][j] = C[i][j + m2];
    for (int i = 0; i < n2; i++) for (int j = m2; j < m; j++) N[i][j] = C[i + n2][j];
    for (int i = n2; i < n; i++) for (int j = m2; j < m; j++) N[i][j] = C[i][j - m2];
    for (int i = n2; i < n; i++) for (int j = 0; j < m2; j++) N[i][j] = C[i - n2][j];
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int r; cin >> n >> m >> r;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> C[i][j];
    for (int i = 0; i < r; i++) {
        int f; cin >> f;
        switch (f) {
            case 1: f1(); break;
            case 2: f2(); break;
            case 3: f3(); break;
            case 4: f4(); break;
            case 5: f5(); break;
            case 6: f6(); break;
            default: break;
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) C[i][j] = N[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << C[i][j] << ' ';
        cout << '\n';
    }
    
    return 0;
}