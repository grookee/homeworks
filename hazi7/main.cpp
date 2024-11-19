#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N;

    vector<int> arrayN(N);

    for (int i = 0; i < N; ++i) {
        cin >> arrayN[i];
    }

    cin >> M;
    vector<int> arrayM(M);

    for (int i = 0; i < M; ++i) {
        cin >> arrayM[i];
    }

    int sum = 0;
    for (int i = 0; i < min(N, M); ++i) {
        if (arrayN[i] == arrayM[i]) {
            sum += arrayN[i];
        }
    }

    int reversedSum = 0;
    while (sum != 0) {
        int digit = sum % 10;
        reversedSum = reversedSum * 10 + digit;
        sum /= 10;
    }

    cout << reversedSum;

    return 0;
}