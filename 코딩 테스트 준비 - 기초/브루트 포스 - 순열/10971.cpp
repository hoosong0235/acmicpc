#include <bits/stdc++.h>
using namespace std;


int n, min_price = INT_MAX;
vector<vector<int>> w(10, vector<int>(10, 0));
vector<int> visited;

int calc() {
    int price = 0;
    for (int i=1; i<n; i++) price += w[visited[i-1]][visited[i]];
    int last = w[visited[n-1]][visited[0]];
    return last ? price + last : INT_MAX;
}

bool check(int i) {
    if (!visited.size()) return true;
    return !count(visited.begin(), visited.end(), i) && w[visited.back()][i];
}

void solve(int depth) {
    if (depth == n) {
        min_price = min(min_price, calc());
        return;
    }
    
    for (int i=0; i<n; i++) {
        if (check(i)) {
            visited.push_back(i);
            solve(depth + 1);
            visited.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin >> w[i][j];
    
    solve(0);
    cout << min_price;
    
    return 0;
}