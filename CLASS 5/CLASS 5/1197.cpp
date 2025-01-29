#include <iostream>
#include <vector>
#include <algorithm>
#define cin std::cin
#define cout std::cout
#define vector std::vector
#define tuple std::tuple
#define get std::get
#define ios_base std::ios_base
#define sort std::sort
#define MAXV 10000
#define ll long long


ll sum;
int v, e, a, b, w;
// Edge list representation
vector<tuple<int, int, int>> edges;


// Union-find structure
int link[MAXV + 1], size[MAXV + 1];
void initialize() {
    for (int i = 0; i < v; i++) link[i] = i, size[i] = 1;
}
int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}
bool same(tuple<int, int, int> edge) {
    int a = get<0>(edge), b = get<1>(edge);
    return find(a) == find(b);
}
void unite(tuple<int, int, int> edge) {
    int a = get<0>(edge), b = get<1>(edge), w = get<2>(edge);
    sum += w;
    a = find(a), b = find(b);
    if (size[a] < size[b]) link[a] = b, size[b] += size[a];
    else link[b] = a, size[a] += size[b];
}


void debug() {
    for (int i = 0; i < e; i++) {
        auto edge = edges[i];
        cout << get<0>(edge) << get<1>(edge) << get<2>(edge) << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> w;
        edges.push_back({ a, b, w });
    }
    
    // Kruskal's algorithm
    initialize();
    sort(edges.begin(), edges.end(), [](auto a, auto b) { return get<2>(a) < get<2>(b); });
    for (auto edge: edges) if (!same(edge)) unite(edge);
    
    cout << sum;
}