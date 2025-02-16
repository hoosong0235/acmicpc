class Solution {
    public:
        long long maxWeight(vector<int>& pizzas) {
            int n = pizzas.size();
            int m = n / 4;
            int odd = (m + 1) / 2;
            int even = m / 2;
            sort(pizzas.begin(), pizzas.end());
            int i = n - 1;
            long long sum = 0;
            while (odd--) {
                sum += pizzas[i];
                i--;
            }
            i--;
            while (even--) {
                sum += pizzas[i];
                i -= 2;
            }
            return sum;
        }
    };