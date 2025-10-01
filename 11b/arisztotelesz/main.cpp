#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
            std::cout << p << " ";

    std::cout << std::endl;
    
    return 0;
}