#include <bits/stdc++.h>
using namespace std;


int n;
vector<int> s(13);
list<int> nums;

bool check(int i) {
    return *max_element(nums.begin(), nums.end()) < s[i];
}

void solve(int init_i, int depth) {
    if (depth == 6) {
        for (int num: nums) cout << num << ' ';
        cout << '\n';
        return;
    }
    
    for (int i=init_i; i<n; i++) if (check(i)) {
        nums.push_back(s[i]);
        solve(init_i + 1, depth + 1);
        nums.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    while (cin >> n) {
        for (int i=0; i<n; i++) cin >> s[i];
        solve(0, 0);
        cout << '\n';
    }
    
    return 0;
}