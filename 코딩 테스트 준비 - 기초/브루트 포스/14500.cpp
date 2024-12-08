#include <bits/stdc++.h>
using namespace std;


const vector<pair<int, int>> rectangles = {
    {4, 1},
    {1, 4},
    {2, 2},
    {3, 2},
    {2, 3},
};

const vector<vector<vector<pair<int, int>>>> tetrominoes = {
    {{{0, 0}, {1, 0}, {2, 0}, {3, 0}}},
    {{{0, 0}, {0, 1}, {0, 2}, {0, 3}}},
    {{{0, 0}, {0, 1}, {1, 0}, {1, 1}}},
    {
        {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
        {{0, 1}, {1, 1}, {2, 0}, {2, 1}},
        {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
        {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
        {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
        {{0, 1}, {1, 0}, {1, 1}, {2, 0}},
        {{0, 0}, {1, 0}, {1, 1}, {2, 0}},
        {{0, 1}, {1, 0}, {1, 1}, {2, 1}},
    },
    {
        {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
        {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
        {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
        {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
        {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
        {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
        {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
        {{0, 1}, {1, 0}, {1, 1}, {1, 2}},
    },
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N, M; cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(M));
    for (int n = 0; n < N; n++) for (int m = 0; m < M; m++) cin >> matrix[n][m];
    
    int max_sum = 0;
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            for (int k = 0; k < 5; k++) {
                pair<int, int> rectangle = rectangles[k];
                vector<vector<pair<int, int>>> tetromino = tetrominoes[k];
                
                if (n + rectangle.first > N || m + rectangle.second > M) continue;

                for (vector<pair<int, int>> points: tetromino) {
                    int sum = 0;
                    for (pair<int, int> point: points) sum += matrix[n + point.first][m + point.second];
                    if (sum > max_sum) max_sum = sum;
                }
            }
        }
    }
    cout << max_sum;
    
    return 0;
}