#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, M;

    cin >> N;
    int tomb1[N];

    for (int i = 0; i < N; i++)
        cin >> tomb1[i];

    cin >> M;
    int tomb2[M];

    for (int i = 0; i < M; i++)
        cin >> tomb2[i];

    int S = 0;
    for (int i = 0; i < min(N, M); i++) {
        if (tomb1[i] == tomb2[i])
            S += tomb1[i];
    }

    int forditottOsszeg = 0;
    while (S != 0) {
        int szj = S % 10;
        forditottOsszeg = forditottOsszeg * 10 + szj;
        S /= 10;
    }

    cout << forditottOsszeg << endl;

    return 0;
}