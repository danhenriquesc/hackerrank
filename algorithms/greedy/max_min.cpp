#include <algorithm>
#include <iostream>
#include <limits>

int main() {
        int N, K, unfairness = std::numeric_limits<int>::max();
        std::cin >> N >> K;

        int candies[N];
        for (auto i = 0; i < N; i++)
                std::cin >> candies[i];

        std::stable_sort(candies, candies+N);
        for (auto i = 0; i < N-K+1; i++) {
                auto min = candies[i];
                auto max = candies[i+K-1];
                if ((max-min) < unfairness)
                        unfairness = max-min;
        }
        std::cout << unfairness << std::endl;;
        return 0;
}