#include <bits/stdc++.h>
using namespace std;


int main() {
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    int price = 0;
    if (2 * c < a + b) {
        if (x < y) {
            price += c * x * 2;
            y -= x;
            if (2 * c < b) {
                price += c * y * 2;
            } else {
                price += b * y;
            }
        } else if (x == y) {
            price += c * x * 2;
        } else {
           price += c * y * 2; 
           x -= y;
           if (2 * c < a) {
                price += c * x * 2;
            } else {
                price += a * x;
            }
        }
    } else {
        price += a * x + b * y;
    }
    cout << price;
}