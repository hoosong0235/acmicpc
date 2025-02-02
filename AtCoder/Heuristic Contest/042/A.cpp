#include <bits/stdc++.h>
using namespace std;
#define N 20


bool oni, fuku;
int n, i, j, onidx;
string s;
char origin[N][N], board[N][N];
vector<pair<char, int>> ans;


void L() {
    for (i = 0; i < n; i++) { // L
        oni = false, fuku = false, onidx = 0;
        for (j = 0; j < n; j++) {
            if (board[i][j] == 'x') {
                oni = true, onidx = j;
                board[i][j] = '.';
            }
            if (board[i][j] == 'o') {
                fuku = true;
                break;
            }
        }
        if (oni) {
            for (int k = 0; k < onidx + 1; k++) ans.push_back({'L', i});
            if (fuku) for (int k = 0; k < onidx + 1; k++) ans.push_back({'R', i});
        }
    }
}


void T() {
    for (j = 0; j < n; j++) { // T
        oni = false, fuku = false, onidx = 0;
        for (i = 0; i < n; i++) {
            if (board[i][j] == 'x') {
                oni = true, onidx = i;
                board[i][j] = '.';
            }
            if (board[i][j] == 'o') {
                fuku = true;
                break;
            }
        }
        if (oni) {
            for (int k = 0; k < onidx + 1; k++) ans.push_back({'U', j});
            if (fuku) for (int k = 0; k < onidx + 1; k++) ans.push_back({'D', j});
        }
    }
}


void R() {
    for (i = 0; i < n; i++) { // R
        oni = false, fuku = false, onidx = 0;
        for (j = n - 1; j >= 0; j--) {
            if (board[i][j] == 'x') {
                oni = true, onidx = j;
                board[i][j] = '.';
            }
            if (board[i][j] == 'o') {
                fuku = true;
                break;
            }
        }
        if (oni) {
            for (int k = n - 1; k >= onidx; k--) ans.push_back({'R', i});
            if (fuku) for (int k = n - 1; k >= onidx; k--) ans.push_back({'L', i});
        }
    }
}


void B() {
    for (j = 0; j < n; j++) { // B
        oni = false, fuku = false, onidx = 0;
        for (i = n - 1; i >= 0; i--) {
            if (board[i][j] == 'x') {
                oni = true, onidx = i;
                board[i][j] = '.';
            }
            if (board[i][j] == 'o') {
                fuku = true;
                break;
            }
        }
        if (oni) {
            for (int k = n - 1; k >= onidx; k--) ans.push_back({'D', j});
            if (fuku) for (int k = n - 1; k >= onidx; k--) ans.push_back({'U', j});
        }
    }
}


string min_order;
int min_num = INT_MAX;


void solve(string order) {
    ans.clear();
    memcpy(board, origin, sizeof(char) * N * N);
    for (char c: order) {
        if (c == 'L') L();
        if (c == 'T') T();
        if (c == 'R') R();
        if (c == 'B') B();
    }
    if (ans.size() < min_num) {
        min_num = ans.size();
        min_order = order;
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> s;
        for (j = 0; j < n; j++) origin[i][j] = s[j];
    }
    
    for (string order: {
        "LTRB", "LTBR", "LRTB", "LRBT", "LBTR", "LBRT",
        "TRBL", "TRLB", "TBRL", "TBLR", "TLRB", "TLBR",
        "RBLT", "RBTL", "RLBT", "RLTB", "RTBL", "RTLB",
        "BLTR", "BLRT", "BTLR", "BTRL", "BRLT", "BRTL"
    }) {
        solve(order);
    }
    
    solve(min_order);
    for (pair<char, int> p: ans) cout << p.first << ' ' << p.second << '\n';
}