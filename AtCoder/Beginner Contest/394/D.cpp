#include <bits/stdc++.h>
using namespace std;


string s;
int n;


void no() {
    cout << "No";
    exit(0);
}


int main() {
    cin >> s; n = s.size();
    
    stack<int> bs;
    for (char c: s) {
        if (c == '(' || c == '[' || c == '<') {
            if (c == '(') {
                bs.push(1);
            } else if (c == '[') {
                bs.push(2);
            } else {
                bs.push(3);
            }
        } else {
            if (bs.empty())
                no();
                
            int b = bs.top(); bs.pop();
            
            if (c == ')') {
                if (b != 1)
                    no();
            } else if (c == ']') {
                if (b != 2)
                    no();
            } else {
                if (b != 3)
                    no();
            }
        }
    }
    
    if (bs.empty())
        cout << "Yes";
    else
        cout << "No";
}