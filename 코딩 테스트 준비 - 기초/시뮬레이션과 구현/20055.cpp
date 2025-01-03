#include <bits/stdc++.h>
using namespace std;


int n, k;
deque<int> dur;
deque<bool> rob;


bool check() {
    int cnt = 0;
    for (int d: dur) {
        if (!d) cnt++;
    }
    return cnt < k;
}


int main() {
    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++) {
        int d; cin >> d; dur.push_back(d); rob.push_back(false);
    }
    
    int cnt = 0;
    while (check()) {
        int dur_back = dur.back(); dur.pop_back(); dur.push_front(dur_back);
        rob.pop_back(); rob.push_front(false); if (rob[n - 1]) rob[n - 1] = false;
        
        for (int i = n - 2; i >= 0; i--) {
            if (rob[i] && !rob[i + 1] && dur[i + 1]) {
                rob[i] = false; rob[i + 1] = true; dur[i + 1]--; if (rob[n - 1]) rob[n - 1] = false;
            }
        }
        
        if (dur[0]) {
            rob[0] = true; dur[0]--;
        }
        
        cnt++;
    }
    cout << cnt;
}