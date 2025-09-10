#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>

using namespace std;

int main() {
    ifstream fin("bac.in");
    if (!fin) {
        return 1;
    }

    vector<int> tomb;
    int num;
    while (fin >> num) {
        tomb.push_back(num);
    }

    fin.close();

    set<int> unique_elements(tomb.begin(), tomb.end());
    tomb.assign(unique_elements.begin(), unique_elements.end());

    sort(tomb.begin(), tomb.end());

    if (tomb.size() < 2) {
        cout << "NU" << endl;
        return 0;
    }

    int r = tomb[1] - tomb[0];
    for (int i = 2; i < tomb.size(); i++) {
        if (tomb[i] - tomb[i-1] != r) {
            cout << "NU" << endl;
            return 0;
        }
    }

    cout << r << endl;

    return 0;
}