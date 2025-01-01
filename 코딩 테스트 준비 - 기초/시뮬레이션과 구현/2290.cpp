#include <bits/stdc++.h>
using namespace std;


const vector<vector<int>> hors = {
    {1, 0, 1},
    {0, 0, 0},
    {1, 1, 1},
    {1, 1, 1},
    {0, 1, 0},
    {1, 1, 1},
    {1, 1, 1},
    {1, 0, 0},
    {1, 1, 1},
    {1, 1, 1},
};

const vector<vector<int>> vers = {
    {1, 1, 1, 1},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 1, 0, 1},
    {1, 1, 0, 1},
    {1, 0, 0, 1},
    {1, 0, 1, 1},
    {0, 1, 0, 1},
    {1, 1, 1, 1},
    {1, 1, 0, 1},
};


int main() {
    int s; cin >> s;
    string n; cin >> n;
    
    int w = 2 * s + 3;
    while (w--) {
        for (char c:  n) {
            int i = c - '0';
            if (w == 0 || w == s + 1 || w == 2 * s + 2) {
                char ch;
                if ((w == 2 * s + 2 && hors[i][0]) || (w == s + 1 && hors[i][1]) || (w == 0 && hors[i][2])) ch = '-';
                else ch = ' ';
                cout << ' ';
                int wh = s; while (wh--) cout << ch;
                cout << ' ';
            } else {
                if ((w > s + 1 && vers[i][0]) || (w < s + 1 && vers[i][2])) cout << '|';
                else cout << ' ';
                int wh = s; while (wh--) cout << ' ';
                if ((w > s + 1 && vers[i][1]) || (w < s + 1 && vers[i][3])) cout << '|';
                else cout << ' ';
            }
            cout << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}