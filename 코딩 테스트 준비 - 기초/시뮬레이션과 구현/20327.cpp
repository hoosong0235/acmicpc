#include <bits/stdc++.h>
using namespace std;


int n, N, r, L;
vector<vector<int>> v(128, vector<int>(128)), w(128, vector<int>(128));


void f1() {
    for (int I = 0; I < N; I += L) for (int J = 0; J < N; J += L) for (int i = I; i < I + L; i++) for (int j = J; j < J + L; j++) {
        w[i][j] = v[I + ((L - 1) - (i - I))][j];
    }
}

void f2() {
    for (int I = 0; I < N; I += L) for (int J = 0; J < N; J += L) for (int i = I; i < I + L; i++) for (int j = J; j < J + L; j++) {
        w[i][j] = v[i][J + ((L - 1) - (j - J))];
    }
}

void f3() {
    for (int I = 0; I < N; I += L) for (int J = 0; J < N; J += L) for (int i = I; i < I + L; i++) for (int j = J; j < J + L; j++) {
        w[i][j] = v[I + ((L - 1) - (j - J))][J + (i - I)];
    }
}

void f4() {
    for (int I = 0; I < N; I += L) for (int J = 0; J < N; J += L) for (int i = I; i < I + L; i++) for (int j = J; j < J + L; j++) {
        w[i][j] = v[I + (j - J)][J + ((L - 1) - (i - I))];
    }
}

void f5() {
    for (int I = 0; I < N; I += L) for (int J = 0; J < N; J += L) for (int i = I; i < I + L; i++) for (int j = J; j < J + L; j++) {
        w[i][j] = v[(i - I) + (L * ((N / L - 1) - (I / L)))][j];
    }
}

void f6() {
    for (int I = 0; I < N; I += L) for (int J = 0; J < N; J += L) for (int i = I; i < I + L; i++) for (int j = J; j < J + L; j++) {
        w[i][j] = v[i][(j - J) + (L * ((N / L - 1) - (J / L)))];
    }
}

void f7() {
    for (int I = 0; I < N; I += L) for (int J = 0; J < N; J += L) for (int i = I; i < I + L; i++) for (int j = J; j < J + L; j++) {
        w[i][j] = v[(i - I) + (L * ((N / L - 1) - (J / L)))][(j - J) + I];
    }
}

void f8() {
    for (int I = 0; I < N; I += L) for (int J = 0; J < N; J += L) for (int i = I; i < I + L; i++) for (int j = J; j < J + L; j++) {
        w[i][j] = v[(i - I) + J][(j - J) + (L * ((N / L - 1) - (I / L)))];
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> r; N = pow(2, n);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> v[i][j];
    while (r--) {
        int k, l; cin >> k >> l; L = pow(2, l);
        switch (k) {
            case 1: f1(); break;
            case 2: f2(); break;
            case 3: f3(); break;
            case 4: f4(); break;
            case 5: f5(); break;
            case 6: f6(); break;
            case 7: f7(); break;
            case 8: f8(); break;
            default: break;
        }
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) v[i][j] = w[i][j];
    }
    for (int i = 0; i < N; i++) { for (int j = 0; j < N; j++) cout << v[i][j] << ' '; cout << '\n'; }
    
    return 0;
}