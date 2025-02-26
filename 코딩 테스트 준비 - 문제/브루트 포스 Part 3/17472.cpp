// 02:38:10
// Kruskal's algorithm
#include <bits/stdc++.h>
using namespace std;
#define N 10
#define M 10


int n, m, a[N][M];
pair<int, int> ulink[N][M];
int usize[N][M];
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
vector<tuple<pair<int, int>, pair<int, int>, int>> edges; // { a, b, w }


void debug() {
    for (auto [a, b, w]: edges)
        cout << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << ' ' << w << '\n';
}


void udebug() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << ulink[i][j].first << ulink[i][j].second << ' ';
        cout << '\n';
    }
}


void uinit() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j])
                ulink[i][j] = { i, j }, usize[i][j] = 1;
}


pair<int, int> ufind(pair<int, int> p) {
    while (p != ulink[p.first][p.second])
        p = ulink[p.first][p.second];
    return p;
}


bool usame(pair<int, int> a, pair<int, int> b) {
    return ufind(a) == ufind(b);
}


void uunite(pair<int, int> a, pair<int, int> b) {
    a = ufind(a), b = ufind(b);
    if (usize[a.first][a.second] < usize[b.first][b.second])
        swap(a, b);
    usize[a.first][a.second] += usize[b.first][b.second];
    ulink[b.first][b.second] = a;
}


void push_horizontal_edges() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j])
                for (int k = j + 1; k < m; k++)
                    if (a[i][k]) {
                        if (k - j != 2)
                            edges.push_back({ { i, j }, { i, k }, k - j - 1 });
                        break;
                    }
}


void push_vertical_edges() {
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            if (a[i][j])
                for (int k = i + 1; k < n; k++)
                    if (a[k][j]) {
                        if (k - i != 2)
                            edges.push_back({ { i, j }, { k, j }, k - i - 1 });
                        break;
                    }
}


bool check() {
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j])
                s.insert(ufind({ i, j }));
    return s.size() == 1;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    uinit();
    
    push_horizontal_edges();
    push_vertical_edges();

    sort(edges.begin(), edges.end(), [](auto a, auto b) { return get<2>(a) < get<2>(b); });

    int sum = 0;
    for (auto [a, b, w]: edges)
        if (!usame(a, b))
            uunite(a, b), sum += w;

    cout << (check() ? sum : -1);
}