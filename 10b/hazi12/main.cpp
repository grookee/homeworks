#include <bits/stdc++.h>

using namespace std;

void extractDigits(int num, int digits[], int &count) {
    count = 0;
    while (num > 0) {
        int digit = num % 10;

        if (digit != 0 && digit % 2 == 0) {
            digits[count] = digit;
            count++;
        }
        num /= 10;
    }
}

bool isMirror(int aDigits[], int aCount, int bDigits[], int bCount) {
    if (aCount != bCount) {
        return false;
    }

    for (int i = 0; i < aCount; i++) {
        if (aDigits[i] != bDigits[aCount - i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int a, b;
    cin >> a >> b;

    int aDigits[10], aCount;
    extractDigits(a, aDigits, aCount);

    int bDigits[10], bCount;
    extractDigits(b, bDigits, bCount);

    if (isMirror(aDigits, aCount, bDigits, bCount)) {
        cout << 1 << endl;
    } else {
        cout << -1 << endl;
    }
 
    return 0;
}