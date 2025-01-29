#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        
        string one = "RGB", two = "GBR", three = "BRG", four = "RBG", five = "GRB", six = "BGR";
        int rgb = 0, gbr = 0, brg = 0, rbg = 0, grb = 0, bgr = 0;
        
        for (int i = 0; i < n; i++) {
            int j = i % 3;
            if (s[i] != one[j]) rgb++;
            if (s[i] != two[j]) gbr++;
            if (s[i] != three[j]) brg++;
            if (s[i] != four[j]) rbg++;
            if (s[i] != five[j]) grb++;
            if (s[i] != six[j]) bgr++;
        }
        
        cout << min({ rgb, gbr, brg, rbg, grb, bgr }) << '\n';
    }
}