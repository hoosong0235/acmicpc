#include <bits/stdc++.h>
using namespace std;


int maxseq(int N, vector<vector<char>> matrix) {
    int maxseq_row = 0;
    for (int i=0; i<N; i++) {
        int seq_row = 0;
        char curr = '\0';
        for (int j=0; j<N; j++) {
            if (!curr) {
                curr = matrix[i][j]; seq_row++;
            } else if (curr == matrix[i][j]) {
                seq_row++;
            } else {
                curr = matrix[i][j]; seq_row = 1;
            }
            
            if (maxseq_row < seq_row) maxseq_row = seq_row;
        }
    }
    
    int maxseq_col = 0;
    for (int i=0; i<N; i++) {
        int seq_col = 0;
        char curr = '\0';
        for (int j=0; j<N; j++) {
            if (!curr) {
                curr = matrix[j][i]; seq_col++;
            } else if (curr == matrix[j][i]) {
                seq_col++;
            } else {
                curr = matrix[j][i]; seq_col = 1;
            }
            
            if (maxseq_col < seq_col) maxseq_col = seq_col;
        }
    }
    
    return max(maxseq_row, maxseq_col);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N; cin >> N;
    vector<vector<char>> matrix(N, vector<char>(N));
    for (int i=0; i<N; i++) {
        string row; cin >> row;
        for (int j=0; j<N; j++) {
            matrix[i][j] = row[j];
        }
    }
    
    int ans = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int L = 0, T = 0, R = 0, B = 0;
            if (j != 0) {
                swap(matrix[i][j], matrix[i][j-1]);
                L = maxseq(N, matrix);
                swap(matrix[i][j], matrix[i][j-1]);
            }
            if (i != 0) {
                swap(matrix[i][j], matrix[i-1][j]);
                T = maxseq(N, matrix);
                swap(matrix[i][j], matrix[i-1][j]);
            }
            if (j != N-1) {
                swap(matrix[i][j], matrix[i][j+1]);
                R = maxseq(N, matrix);
                swap(matrix[i][j], matrix[i][j+1]);
            }
            if (i != N-1) {
                swap(matrix[i][j], matrix[i+1][j]);
                B = maxseq(N, matrix);
                swap(matrix[i][j], matrix[i+1][j]);
            }
            
            if (ans < max({L, T, R, B})) ans = max({L, T, R, B});
        }
    }
    
    cout << ans;
    
    return 0;
}