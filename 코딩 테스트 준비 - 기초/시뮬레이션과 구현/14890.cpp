#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, l; cin >> n >> l;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> v[i][j];
    
    int cnt = 0;
    
    // row
    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
        bool b = true;
        
        int curr = v[i][0];
        for (int j = 1; j < n; j++) {
            int next = v[i][j];
            
            if (curr < next) {
                if (next - curr > 1) { b = false; break; }
                if (j - l < 0) { b = false; break; }
                for (int k = j - l; k < j; k++) if (v[i][k] != curr) { b = false; break; }
                for (int k = j - l; k < j; k++) {
                    if (visited[k]) { b = false; break; }
                    else visited[k] = true;
                }
            } else if (next < curr) {
                if (curr - next > 1) { b = false; break; }
                if ((j - 1) + l > (n - 1)) { b = false; break; }
                for (int k = j; k < j + l; k++) if (v[i][k] != next) { b = false; break; }
                for (int k = j; k < j + l; k++) {
                    if (visited[k]) { b = false; break; }
                    else visited[k] = true;
                }
            } else {
                
            }
            
            curr = next;
        }
        
        // cout << i << ' ' << b << '\n';
        if (b) cnt++;
    }
    
    // column
    for (int j = 0; j < n; j++) {
        vector<bool> visited(n, false);
        bool b = true;
        
        int curr = v[0][j];
        for (int i = 1; i < n; i++) {
            int next = v[i][j];
            
            if (curr < next) {
                if (next - curr > 1) { b = false; break; }
                if (i - l < 0) { b = false; break; }
                for (int k = i - l; k < i; k++) if (v[k][j] != curr) { b = false; break; }
                for (int k = i - l; k < i; k++) {
                    if (visited[k]) { b = false; break; }
                    else visited[k] = true;
                }
            } else if (next < curr) {
                if (curr - next > 1) { b = false; break; }
                if ((i - 1) + l > (n - 1)) { b = false; break; }
                for (int k = i; k < i + l; k++) if (v[k][j] != next) { b = false; break; }
                for (int k = i; k < i + l; k++) {
                    if (visited[k]) { b = false; break; }
                    else visited[k] = true;
                }
            } else {
                
            }
            
            curr = next;
        }
        
        // cout << j << ' ' << b << '\n';
        if (b) cnt++;
    }
    
    cout << cnt;
    
    return 0;
}