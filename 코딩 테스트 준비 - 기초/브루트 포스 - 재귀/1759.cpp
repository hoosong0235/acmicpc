#include <bits/stdc++.h>
using namespace std;


int c;
vector<char> cs(26, CHAR_MAX);
string s = "";
vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
vector<char> consonants = {
    'b', 'c', 'd', 'f', 'g',
    'h', 'j', 'k', 'l', 'm',
    'n', 'p', 'q', 'r', 's',
    't', 'v', 'w', 'x', 'y',
    'z',
};


bool check() {
    int vowel_cnt = 0, consonant_count = 0;
    for (char vowel: vowels) vowel_cnt += count(s.begin(), s.end(), vowel);
    for (char consonant: consonants) consonant_count += count(s.begin(), s.end(), consonant);
    return !(vowel_cnt < 1 || consonant_count < 2);
}


void solve(int l, int init_i) {
    if (!l && check()) {
        cout << s << '\n';
        return;
    }
    for (int i = init_i; i < c; i++) {
        s.push_back(cs[i]);
        solve(l - 1, i + 1);
        s.pop_back();
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int l; cin >> l >> c;
    for (int i = 0; i < c; i++) cin >> cs[i];
    sort(cs.begin(), cs.begin() + c);
    solve(l, 0);
    return 0;
}