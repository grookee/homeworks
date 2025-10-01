#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>

std::string stripComments(
  const std::string& str,
  const std::unordered_set<char>& markers
) {
    std::string result;
    std::istringstream stream(str);
    std::string line;
    bool first = true;
    
    while (std::getline(stream, line)) {
        size_t marker_pos = std::string::npos;
        for (char marker : markers) {
            size_t pos = line.find(marker);
            if (pos != std::string::npos) {
                if (marker_pos == std::string::npos || pos < marker_pos) {
                    marker_pos = pos;
                }
            }
        }
        
        if (marker_pos != std::string::npos) {
            line = line.substr(0, marker_pos);
        }
        
        size_t end = line.find_last_not_of(" \t");
        if (end != std::string::npos) {
            line = line.substr(0, end + 1);
        } else {
            line.clear();
        }
    
        if (!first) {
            result += '\n';
        }
        result += line;
        first = false;
    }
    
    return result;
}

int main() {
    std::unordered_set<char> markers = {'#', '!'};  
    std::string text = "apples, pears # and bananas\ngrapes\nbananas !apples";
    
    std::string result = stripComments(text, markers);
    std::cout << result << std::endl;

    return 0;
}