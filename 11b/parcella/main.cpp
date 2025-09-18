#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input("bac.in");

    int minZ, minP;
    input >> minZ >> minP;

    int nr = 0, S = 0, dayP, start;

    while (input >> dayP) {
        if (dayP >= minZ) {
            start = nr;
            S = dayP;
        } else {
            S += dayP;
        }
    }

    input.close();

        if (S >= minP && nr - start > 1) {
            cout << start << ' ' << nr << " " << S;
        } else {
            cout << "NU EXISTA";
        }

    return 0;
}