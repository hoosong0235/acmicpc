// 역대급으로 못 풀었다


#include <bits/stdc++.h>
using namespace std;


int n, max_num = INT_MIN;
vector<string> ss(10);
vector<bool> visited(10, false);
deque<char> keys;
deque<int> values;


int calc() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int num = 0;
        for (char c: ss[i]) {
            num *= 10;
            num += values[c];
        }
        sum += num;
    }
    return sum;
}


void solve(int d) {
    if (d == keys.size()) {
        max_num = max(max_num, calc()); return;
    }
    
    for (int i = 0; i < 10; i++) if (!visited[i]) {
        values[keys[d]] = i;
        visited[i] = true;
        solve(d + 1);
        visited[i] = false;
    }
}


int main() {
    cin >> n;
    
    set<char> cs;
    for (int i = 0; i < n; i++) {
        cin >> ss[i];
        for (char c: ss[i]) cs.insert(c);
    }
    for (char c: cs) keys.push_back(c);
    
    solve(0); cout << max_num;
    
    return 0;
}