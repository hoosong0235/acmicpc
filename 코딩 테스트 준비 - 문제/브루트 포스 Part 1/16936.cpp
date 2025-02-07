#include <bits/stdc++.h>
using namespace std;
#define N 100
#define ll long long


int n;
ll a[N];
bool visited[N];
deque<ll> sorted;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sorted.push_back(a[0]);
    visited[0] = true;
    while (sorted.size() < n) for (int i = 0; i < n; i++) if (!visited[i]) {
        if (a[i] == sorted.front() * 3) {
            sorted.push_front(a[i]);
            visited[i] = true;
        } else if (a[i] * 2 == sorted.front()) {
            sorted.push_front(a[i]);
            visited[i] = true;
        } else if (sorted.back() == a[i] * 3) {
            sorted.push_back(a[i]);
            visited[i] = true;
        } else if (sorted.back() * 2 == a[i]) {
            sorted.push_back(a[i]);
            visited[i] = true;
        }
    }
    
    for (ll s: sorted) cout << s << ' ';
}