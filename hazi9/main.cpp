#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int lnko(int a, int b) {
    while(a != b)
    {
        if(a > b)
            a = a - b;
        else
            b = b - a;
    }
    
    return a;
}

int lkkt(int a, int b) {
    int _lkkt = a * b;
    return _lkkt / lnko(a, b);
}

int main() {
    int n;
    cin >> n;

    vector<int> tomb(n);
    for (int i = 0; i < n; i++)
        cin >> tomb[i];

    sort(tomb.begin(), tomb.end());

    int m_ln = tomb[n-2];
    int h_lk = tomb[2];

    int a = lkkt(m_ln, h_lk);
    int b = lnko(m_ln, h_lk);

    cout << a-b << endl;

    return 0;
}