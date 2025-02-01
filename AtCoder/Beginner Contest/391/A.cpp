#include <bits/stdc++.h>
using namespace std;


int main() {
    string s; cin >> s;
    if (s ==  "E") cout << "W";
    if (s ==  "W") cout << "E";
    if (s ==  "S") cout << "N";
    if (s ==  "N") cout << "S";
    if (s ==  "NE") cout << "SW";
    if (s ==  "NW") cout << "SE";
    if (s ==  "SE") cout << "NW";
    if (s ==  "SW") cout << "NE";
}