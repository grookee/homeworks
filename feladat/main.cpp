#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "ctrack.hpp"

using namespace std;

int main() {
    CTRACK;
    srand(time(0));

    int N;
    cin >> N;

    vector<int> szamok(N);

    for (int i = 0; i < N; i++) {
        szamok[i] = rand() % 100;
    }

    for (int i = 0; i < N; i++) {
        cout << szamok[i] << " ";
    }
    cout << endl;

    auto particionalas = [](vector<int>& tomb, int alacsony, int magas) -> int {
        int pivot = tomb[magas];
        int i = (alacsony - 1);

        for (int j = alacsony; j <= magas - 1; j++) {
            if (tomb[j] < pivot) {
                i++;
                int temp = tomb[i];
                tomb[i] = tomb[j];
                tomb[j] = temp;
            }
        }
        int temp = tomb[i + 1];
        tomb[i + 1] = tomb[magas];
        tomb[magas] = temp;
        return i + 1;
    };

    auto gyorsRendezes = [&](vector<int>& tomb, int alacsony, int magas) -> void {
        int kezd = alacsony;
        int veg = magas;

        while (kezd < veg) {
            int pi = particionalas(tomb, kezd, veg);

            if (pi - 1 > kezd) {
                veg = pi - 1;
            } else {
                kezd = pi + 1;
            }
        }
    };

    gyorsRendezes(szamok, 0, N - 1);

    for (int i = 0; i < N; i++) {
        cout << szamok[i] << " ";
    }

    ctrack::result_print();

    return 0;
}