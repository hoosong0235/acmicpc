#include <bits/stdc++.h>
using namespace std;
#define MAX 10000


struct pos {
    double x, y, z;
};


double x, y, z;
pos a, b, c;


double dist(pos i, pos j) {
    return sqrt((j.x - i.x) * (j.x - i.x) + (j.y - i.y) * (j.y - i.y) + (j.z - i.z) * (j.z - i.z));
}


pos calc(double perc) {
    return pos {
        a.x + (b.x - a.x) * perc,
        a.y + (b.y - a.y) * perc,
        a.z + (b.z - a.z) * perc,
    };
}


double bs(double lo, double hi) {
    double lomid = (2 * lo + hi) / 3, mid = (lo + hi) / 2, midhi = (lo + hi * 2) / 3;
    if (hi - lo < 1e-11) return dist(c, calc(mid));
    if (dist(c, calc(lomid)) < dist(c, calc(midhi))) return bs(lo, midhi);
    else return bs(lomid, hi);
}


int main() {
    std::cout << std::fixed << std::setprecision(10);
    cin >> x >> y >> z; a = pos { x, y, z };
    cin >> x >> y >> z; b = pos { x, y, z };
    cin >> x >> y >> z; c = pos { x, y, z };
    cout << bs(0, 1);
}