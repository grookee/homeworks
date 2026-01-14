#include <string>
#include <algorithm>

long nextBigger(long n)
{
    std::string digits = std::to_string(n);
    
    int i = digits.length() - 2;
    while (i >= 0 && digits[i] >= digits[i + 1]) {
        i--;
    }
    
    if (i < 0) {
        return -1;
    }
    
    int j = digits.length() - 1;
    while (j > i && digits[j] <= digits[i]) {
        j--;
    }
    
    std::swap(digits[i], digits[j]);
    
    std::reverse(digits.begin() + i + 1, digits.end());
    
    return std::stol(digits);
}