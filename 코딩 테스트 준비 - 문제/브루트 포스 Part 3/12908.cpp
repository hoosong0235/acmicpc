// 00:10:10
using namespace std;
#include <iostream>
#include <vector>
#include <climits>
#define ll long long


struct teleport { ll x1, y1, x2, y2; };
ll xs, ys, xe, ye, x1, y1, x2, y2;
ll min_num = LONG_LONG_MAX;
teleport ts[6];
vector<teleport> v;
bool visited[6];


ll dist(ll xs, ll ys, ll xe, ll ye) {
    return abs(xs - xe) + abs(ys - ye);
}


ll calc() {
    ll num = 0;
    ll x = xs, y = ys;
    for (auto t: v) {
        num += dist(x, y, t.x1, t.y1) + 10;
        x = t.x2, y = t.y2;
    }
    num += dist(x, y, xe, ye);
    return num;
}


void solve(ll d) {
    min_num = min(min_num, calc());
    
    for (ll i = 0; i < 6; i++)
        if (!visited[i]) {
            visited[i] = true;
            v.push_back(ts[i]);
            solve(d + 1);
            v.pop_back();
            visited[i] = false;
        }
}


int main() {
    cin >> xs >> ys >> xe >> ye;
    for (ll i = 0; i < 3; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        ts[2 * i] = teleport { x1, y1, x2, y2 };
        ts[2 * i + 1] = teleport { x2, y2, x1, y1 };
    }
    
    solve(0);
    cout << min_num;
}