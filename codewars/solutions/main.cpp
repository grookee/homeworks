#include <iostream>
#include <vector>
#include <cmath>

typedef unsigned long long ull;

ull sumOfSquaredDivisors(ull num) {
    ull sum = 0;
    for (ull i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i * i; 
            if (i * i != num) {
                ull other_divisor = num / i;
                sum += other_divisor * other_divisor;
            }
        }
    }
    return sum;
}

bool isPerfectSquare(ull num) {
    ull root = sqrt(num);
    return root * root == num;
} 

int main() {
    ull m, n;
    std::cin >> m >> n;

    std::vector<std::pair<ull, ull>> result;

    for (ull num = m; num <= n; num++) {
        ull sumSquared = sumOfSquaredDivisors(num);
        if (isPerfectSquare(sumSquared)) {
            result.push_back({num, sumSquared});
        }
    }

    // Output the results
    std::cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << "[" << result[i].first << ", " << result[i].second << "]";
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}