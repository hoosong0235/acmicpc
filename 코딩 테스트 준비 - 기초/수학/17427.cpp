#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    
    long long sum = 0;
    for (int i = 1; i <= n; i++) sum += (n / i) * i;
    
    std::cout << sum;
    
    return 0;
}