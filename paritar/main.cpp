#include <bits/stdc++.h>

using namespace std;

bool paritar(const vector<int> &elso, const vector<int> &masodik)
{
    int min_paros = INT_MAX;
    int min_paratlan = INT_MAX;

    for (int szam : masodik)
    {
        if (szam % 2 == 0)
        {
            if (szam < min_paros)
            {
                min_paros = szam;
            }
        }
        else
        {
            if (szam < min_paratlan)
            {
                min_paratlan = szam;
            }
        }
    }

    bool van_paros = (min_paros != INT_MAX);
    bool van_paratlan = (min_paratlan != INT_MAX);

    for (int x : elso)
    {
        if (x % 2 == 0)
        {
            if (van_paratlan && x >= min_paratlan)
            {
                return false;
            }
        }
        else
        {
            if (van_paros && x >= min_paros)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    ifstream f("input.txt");
    int n;
    f >> n;

    vector<int> szamok(n * 2);
    for (int i = 0; i < n * 2; ++i)
    {
        f >> szamok[i];
    }

    vector<int> elso = vector<int>(szamok.begin(), szamok.begin() + n);
    vector<int> masodik = vector<int>(szamok.begin() + n, szamok.end());

    cout << (paritar(elso, masodik) ? "DA" : "NU");

    return 0;
}