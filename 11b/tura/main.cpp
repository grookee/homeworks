#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream fin("bac.txt");
    std::vector<int> heights;
    int x;
    
    while (fin >> x) {
        heights.push_back(x);
    }
    fin.close();
    
    if (heights.size() < 2) {
        std::cout << "nu exista" << std::endl;
        return 0;
    }
    
    int maxLength = 0;
    int bestStart = -1;
    
    for (int i = 0; i < heights.size() - 1; i++) {
        int currentLength = 1;
        int j = i;
        
        while (j + 1 < heights.size() && heights[j + 1] == heights[j] + 1) {
            currentLength++;
            j++;
        }
        
        if (currentLength > maxLength && currentLength >= 2) {
            maxLength = currentLength;
            bestStart = i;
        }
    }
    
    if (maxLength < 2) {
        std::cout << "nu exista" << std::endl;
    } else {
        for (int i = 0; i < maxLength; i++) {
            if (i > 0) std::cout << " ";
            std::cout << heights[bestStart + i];
        }
        std::cout << std::endl;
    }
    
    return 0;
}