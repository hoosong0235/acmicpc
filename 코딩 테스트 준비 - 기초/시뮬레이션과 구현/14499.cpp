#include <bits/stdc++.h>
using namespace std;


bool b;
int n, m, x, y;
vector<int> dice = {0, 0, 0, 0, 0, 0};


void east() {
    if (y == m - 1) {
        b = false; return;
    }
    y++;
    swap(dice[5], dice[3]);
    swap(dice[3], dice[2]);
    swap(dice[2], dice[1]);
}

void west() {
    if (!y) {
        b = false; return;
    }
    y--;
    swap(dice[5], dice[1]);
    swap(dice[1], dice[2]);
    swap(dice[2], dice[3]);
}

void south() {
    if (x == n - 1) {
        b = false; return;
    }
    x++;
    swap(dice[5], dice[4]);
    swap(dice[4], dice[2]);
    swap(dice[2], dice[0]);
}

void north() {
    if (!x) {
        b = false; return;
    }
    x--;
    swap(dice[0], dice[2]);
    swap(dice[2], dice[4]);
    swap(dice[4], dice[5]);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int k; cin >> n >> m >> x >> y >> k;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];
    for (int i = 0; i < k; i++) {
        int f; cin >> f;
        b = true;
        switch (f) {
            case 1:
                east();
                break;
            case 2:
                west();
                break;
            case 3:
                north();
                break;
            case 4:
                south();
                break;
            default:
                break;
        }
        if (!b) continue;
        if (v[x][y]) {
            dice[5] = v[x][y];
            v[x][y] = 0;
        } else {
            v[x][y] = dice[5];
        }
        cout << dice[2] << '\n';
    }
    
    return 0;
}