#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("bac.in");
    if (!fin) {
        return 1;
    }

    int n;
    fin >> n;

    int eredmeny = 0;
    int szorzo = 1;
    while (n != 0) {
        int digit = n % 10;
        if (digit % 2 == 1) {
            eredmeny += digit * szorzo;
            szorzo *= 10;
        }
        n /= 10;
    }

    cout << eredmeny << endl;

    return 0;
}