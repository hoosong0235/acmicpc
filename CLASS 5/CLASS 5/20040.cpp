#include <iostream>
#define cin std::cin
#define cout std::cout
#define ios_base std::ios_base
#define V 500000
#define E 1000000


int v, e, a, b;


// Union-find structure
int link[V], size[V];
void initialize() {
    for (int i = 0; i < v; i++) link[i] = i, size[i] = 1;
}
int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}
bool same(int a, int b) {
    return find(a) == find(b);
}
void unite(int a, int b) {
    a = find(a), b = find(b);
    if (size[a] < size[b]) link[a] = b, size[b] += size[a];
    else link[b] = a, size[a] += size[b];
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e;
    initialize();
    for (int i = 1; i <= e; i++) {
        cin >> a >> b;
        if (same(a, b)) { cout << i; return 0; }
        unite(a, b);
    }
    cout << 0;
}