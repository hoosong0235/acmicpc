#include <iostream>
#include <cassert>
using namespace std;


int gcd(int a, int b) {
    assert(a >= b);
    return a % b ? gcd(b, a % b) : b;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int a, b; cin >> a >> b;
    
    cout << gcd(max(a, b), min(a, b)) << '\n' << lcm(max(a, b), min(a, b));
    return 0;
}