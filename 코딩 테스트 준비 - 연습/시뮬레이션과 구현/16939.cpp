#include <bits/stdc++.h>
using namespace std;
#define MAX 25


int a[MAX];
int b[MAX];


void roll(int i) {
    switch (i) {
        case 1:
            swap(a[13], a[5]), swap(a[14], a[6]);
            swap(a[5], a[17]), swap(a[6], a[18]);
            swap(a[17], a[21]), swap(a[18], a[22]);
            break;
        case 2:
            swap(a[15], a[7]), swap(a[16], a[8]);
            swap(a[7], a[19]), swap(a[8], a[20]);
            swap(a[19], a[23]), swap(a[20], a[24]);
            break;
        case 3:
            swap(a[2], a[6]), swap(a[4], a[8]);
            swap(a[6], a[10]), swap(a[8], a[12]);
            swap(a[10], a[23]), swap(a[12], a[21]);
            break;
        case 4:
            swap(a[1], a[5]), swap(a[3], a[7]);
            swap(a[5], a[9]), swap(a[7], a[11]);
            swap(a[9], a[24]), swap(a[11], a[22]);
            break;
        case 5:
            swap(a[3], a[17]), swap(a[4], a[19]);
            swap(a[17], a[10]), swap(a[19], a[9]);
            swap(a[10], a[16]), swap(a[9], a[14]);
            break;
        case 6:
            swap(a[1], a[18]), swap(a[2], a[20]);
            swap(a[18], a[12]), swap(a[20], a[11]);
            swap(a[12], a[15]), swap(a[11], a[13]);
            break;
        default:
            break;
    }
}


bool check() {
    for (int i = 0; i < 6; i++) {
        int target = a[i * 4 + 1];
        for (int j = i * 4 + 2; j <= i * 4 + 4; j++) if (a[j] != target) return false;
    }
    return true;
}


int main() {
    for (int i = 1; i <= MAX; i++) cin >> b[i];
    for (int i = 1; i <= 6; i++) {
        memcpy(a, b, sizeof(int) * MAX);
        roll(i);
        if (check()) { cout << 1; return 0; }
    }
    cout << 0;
}