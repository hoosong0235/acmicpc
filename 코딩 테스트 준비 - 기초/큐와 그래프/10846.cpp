#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    deque<int> a; string s; int i;
    while (n--) {
        cin >> s;
        if (s == "push_front" || s == "push_back") cin >> i;
        if (s == "push_front") {
            a.push_front(i);
        } else if (s == "push_back") {
            a.push_back(i);
        } else if (s == "pop_front") {
            if (a.size()) {
                cout << a.front() << '\n'; a.pop_front();
            } else {
                cout << -1 << '\n';
            }
        } else if (s == "pop_back") {
            if (a.size()) {
                cout << a.back() << '\n'; a.pop_back();
            } else {
                cout << -1 << '\n';
            }
        } else if (s == "size") {
            cout << a.size() << '\n';
        } else if (s == "empty") {
            cout << (a.size() ? 0 : 1) << '\n';
        } else if (s == "front") {
            if (a.size()) cout << a.front() << '\n';
            else cout << -1 << '\n';
        } else if (s == "back") {
            if (a.size()) cout << a.back() << '\n';
            else cout << -1 << '\n';
        }
    }
    
    return 0;
}