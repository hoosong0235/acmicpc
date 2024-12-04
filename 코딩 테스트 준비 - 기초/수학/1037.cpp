#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> divs(n);
    for (int i = 0; i < n; i++) std::cin >> divs[i];
    sort(divs.begin(), divs.end());
    
    std::cout << divs[0] * divs[n - 1];
 
    return 0;
}