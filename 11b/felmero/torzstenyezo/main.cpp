#include <iostream>

int main() {
    int x, y, nr = 0;
    std::cin >> x >> y;

    int max = y;
    if (max < y) max = y;

    for (int oszto = 2; oszto <= max / 2; oszto++) {
        int nrX = 0, nrY = 0;
        while (x % oszto == 0) {
            nrX++;
            x /= oszto;
        }

        while (y % oszto == 0) {
            nrY++;
            y /= oszto;
        }
        
        if (nrX > 0 && nrY == nrX) {
            nr++;
        }
    }

    std::cout << nr << std::endl;
    return 0;
}