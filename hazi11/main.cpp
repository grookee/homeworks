#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("bac.in");
    if (!fin) {
        return 1;
    }

    int n;
    fin >> n;
    fin.close();

    vector<int> eredmeny;
    bool paratlan = false;

    while (n != 0) {
        int szj = n % 10;
        if (szj % 2 == 1) {
            eredmeny.push_back(szj);
            eredmeny.push_back(szj);
            paratlan = true;
        } else {
            eredmeny.push_back(szj);
        }
        n /= 10;
    }

    if (!paratlan) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = eredmeny.size() - 1; i >= 0; i--) {
        cout << eredmeny[i];
    }
    cout << endl;

    return 0;
}