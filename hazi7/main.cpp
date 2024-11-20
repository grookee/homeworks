// Keressük meg egy 1D tömb utolsó pallindróm elemét és írjuk ki!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> tomb(N);

    for (int i = 0; i < N; ++i) {
        cin >> tomb[i];
    }

    auto palindrom = [](int n) {
        int forditott = 0;
        int szam = n;
        while (n != 0) {
            int szj = n % 10;
            forditott = forditott  * 10 + szj;
            n /= 10;
        }
        return szam == forditott;
    };

    for (int i = N - 1; i >= 0; i--) {
        if (palindrom(tomb[i])) {
            cout << tomb[i];
            break;
        }
    }

    return 0;
}