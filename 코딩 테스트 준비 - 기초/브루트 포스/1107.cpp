#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int N, M; cin >> N >> M;
    
    set<int> brokens;
    while (M--) {
        int broken; cin >> broken;
        brokens.insert(broken);
    }
    
    int min_diff = 1e6;
    for (int channel=0; channel<=1e6; channel++) {
        if (channel) {
            int cnt = 0;
            bool isBroken = false;
            for (int i=10; (i/10)<=channel; i*=10) {
                int digit = (channel % i) / (i / 10);
                cnt++;
                if (brokens.count(digit)) {
                    isBroken = true;
                    break;
                }
            }
            if (!isBroken) {
                int diff = abs(N - channel) + cnt;
                if (diff < min_diff) min_diff = diff;
            }
        } else {
            if (!brokens.count(channel)) {
                int diff = abs(N - channel) + 1;
                if (diff < min_diff) min_diff = diff;
            }
        }
    }
    
    cout << min(min_diff, abs(100 - N));
    
    return 0;
}