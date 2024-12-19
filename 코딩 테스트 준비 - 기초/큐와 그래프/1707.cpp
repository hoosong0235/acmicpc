#include <bits/stdc++.h>
using namespace std;
#define RED 0
#define BLUE 1


unordered_map<int, unordered_set<int>> es;
unordered_set<int> visited_red;
unordered_set<int> visited_blue;


bool dfs(int curr, int color) {
    if (color) { // BLUE
        visited_blue.insert(curr);
        for (int next: es[curr]) {
            if (visited_blue.count(next)) return false;
            else if (!visited_red.count(next)) {
                if (!dfs(next, RED)) return false;
            }
        }
        return true;
    } else { // RED
        visited_red.insert(curr);
        for (int next: es[curr]) {
            if (visited_red.count(next)) return false;
            else if (!visited_blue.count(next)) {
                if (!dfs(next, BLUE)) return false;
            }
        }
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int k, v, e, a, b; cin >> k;
    while (k--) {
        cin >> v >> e;
        while (e--) {
            cin >> a>> b;
            es[a].insert(b);
            es[b].insert(a);
        }
        
        bool bg = true;
        while (visited_red.size() + visited_blue.size() < v) {
            int curr; for (curr = 1; curr <= v; curr++) if (!visited_red.count(curr) && !visited_blue.count(curr)) break;
            if (!dfs(curr, RED)) {
                bg = false; break;
            }
        }
        cout << (bg ? "YES" : "NO") << '\n';
        
        es.clear();
        visited_blue.clear();
        visited_red.clear();
    }
    
    return 0;
}