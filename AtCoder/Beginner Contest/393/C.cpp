#include <bits/stdc++.h>
using namespace std;
#define N 200'000
#define M 500'000


int n, m, a, b, cnt;
vector<int> adj[N + 1];


// Union-find structure
// int ulink[N + 1], usize[N + 1];
// void uinit() { for (int i = 1; i <= n; i++) ulink[i] = i, usize[i] = 1; }
// int ufind(int x) { while (x != ulink[x]) x = ulink[x]; return x; }
// bool usame(int a, int b) { return ufind(a) == ufind(b); }
// void uunite(int a, int b) {
//     a = ufind(a), b = ufind(b);
//     if (usize[a] < usize[b]) swap(a, b);
//     usize[a] += usize[b], ulink[b] = a;
// }


int main() {
    cin >> n >> m;
    // uinit();
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        // if (!usame(a, b)) uunite(a, b);
        // else cnt++;
        if (a == b) cnt++;
        else {
            if (find(adj[a].begin(), adj[a].end(), b) != adj[a].end() ||
                find(adj[b].begin(), adj[b].end(), a) != adj[b].end()) {
                cnt++;
            } else {
                adj[a].push_back(b), adj[b].push_back(a);
            }
        }
    }
    cout << cnt;
}