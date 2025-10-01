#include <iostream>
#include <string>

std::string rot13(const std::string& str) {
    std::string result;
    
    for (size_t i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            char base = islower(str[i]) ? 'a' : 'A';
            result.append(1, (str[i] - base + 13) % 26 + base);
        } else {
            result.append(1, str[i]);
        }

    }
    
    return result;
}

int main() {
    std::string input;
    std::getline(std::cin, input); 
    
    std::string result = rot13(input);
    std::cout << result << std::endl;
    
    return 0;
}   