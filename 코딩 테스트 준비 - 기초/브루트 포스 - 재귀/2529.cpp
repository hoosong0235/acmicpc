#include <bits/stdc++.h>
using namespace std;


long long num, k, max_num = LONG_LONG_MIN, min_num = LONG_LONG_MAX;
vector<char> signs(9);
vector<long long> selected;


string format(long long i) {
    return i < pow(10, k) ? '0' + to_string(i) : to_string(i);
}

bool check(int i, int j) {
    if (!i) return true;
    return (signs[i - 1] == '<' && selected[i - 1] < j) || (signs[i - 1] == '>' && selected[i - 1] > j);
}

void solve(int i) {
    if (i == k+1) {
        num = 0;
        for (int j=0; j<k+1; j++) num = num * 10 + selected[j];
        max_num = max(max_num, num);
        min_num = min(min_num, num);
        return;
    }
    
    for (int j=0; j<10; j++) {
        if (find(selected.begin(), selected.end(), j) == selected.end() && check(i, j)) {
            selected.push_back(j);
            solve(i + 1);
            selected.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> k;
    for (int i=0; i<k; i++) cin >> signs[i];
    solve(0); cout << format(max_num) << '\n' << format(min_num);
    
    return 0;
}