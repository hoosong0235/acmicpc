#include <bits/stdc++.h>
using namespace std;
#define N 10 // digit
#define M 9 // operator
#define ll long long


string s;
int n, m, k;
int ns[N];
char ms[M];
bool visited[N];
ll max_num = LONG_LONG_MIN;
deque<int> secondary;
deque<int> primary;


ll calc() {
    ll tmp[N] = {};
    int group[N] = {};
    int grouptmp[N] = {};
    for (int i = 0; i < n; i++) tmp[i] = ns[i], group[i] = i, grouptmp[i] = i;
    
    ll res;
    for (auto p: primary) {
        if (ms[p] == '*') res = tmp[p] * tmp[p + 1];
        else if (ms[p] == '+') res = tmp[p] + tmp[p + 1];
        else res = tmp[p] - tmp[p + 1];
        for (int i = 0; i < n; i++)
            if (group[i] == group[p] || group[i] == group[p + 1])
                grouptmp[i] = group[p], tmp[i] = res;
        for (int i = 0; i < n; i++) group[i] = grouptmp[i];
        // for (int i = 0; i < n; i++) cout << group[i] << ' '; cout << '\n';
    }
    for (auto s: secondary) if (find(primary.begin(), primary.end(), s) == primary.end()) {
        if (ms[s] == '*') res = tmp[s] * tmp[s + 1];
        else if (ms[s] == '+') res = tmp[s] + tmp[s + 1];
        else res = tmp[s] - tmp[s + 1];
        for (int i = 0; i < n; i++)
            if (group[i] == group[s] || group[i] == group[s + 1])
                grouptmp[i] = group[s], tmp[i] = res;
        for (int i = 0; i < n; i++) group[i] = grouptmp[i];
        // for (int i = 0; i < n; i++) cout << group[i] << ' '; cout << '\n';
    }
    return res;
}


void debug() {
    for (int p: primary) cout << p << ' ';
    for (int s: secondary) if (find(primary.begin(), primary.end(), s) == primary.end()) cout << s << ' ';
    cout << '\n';
    cout << calc() << '\n';
}


void solve() {
    // debug();
    max_num = max(max_num, calc());
    
    for (int i = 0; i < n - 1; i++) if (!visited[i] && !visited[i + 1]) {
        visited[i] = true;
        visited[i + 1] = true;
        primary.push_back(i);
        solve();
        visited[i] = false;
        visited[i + 1] = false;
        primary.pop_back();
    }
}


int main() {
    cin >> k; m = k / 2; n = m + 1;
    cin >> s;
    for (int i = 0; i < k; i++) {
        if (i % 2) ms[i / 2] = s[i];
        else ns[i / 2] = s[i] - '0';
    }
    for (int i = 0; i < m; i++) {
        if (ms[i] == '*') secondary.push_front(i);
        else secondary.push_back(i);
        // secondary.push_back(i);
    }
    
    solve();
    cout << (k == 1 ? ns[0] : max_num);
}