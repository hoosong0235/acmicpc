#include <iostream>
#include <cassert>
#include <cmath>


int main() {
    int n;
    
    while (std::cin >> n) {
        assert(0 <= n && n <= 10000);
        assert(n % 2);
        assert(n % 5);
        
        int ans = 1, m = 1;
        while (ans % n) {
            m++;
            ans = ans * 10 + 1;
            ans %= n;
        }
        
        std::cout << m << std::endl;
    }
 
    return 0;
}