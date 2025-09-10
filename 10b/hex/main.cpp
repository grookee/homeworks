#include <bits/stdc++.h>
#include <string>
#include <cstdlib>

using namespace std;

string konvertalas(int szam, int alap)
{
    if (szam < 0)
        return " ";

    if (szam == 0)
        return "0";

    const string szamok = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string eredmeny;

    while (szam > 0)
    {
        int maradek = szam % alap;
        eredmeny += szamok[maradek];
        szam /= alap;
    }

    reverse(eredmeny.begin(), eredmeny.end());
    return eredmeny;

}

int main()
{
    std::string in;
    getline(cin, in);

    regex regexx("\\d+");
    sregex_iterator it(in.begin(), in.end(), regexx);
    sregex_iterator endd;

    vector<int> szamok;
    while(it != endd)
    {
        szamok.push_back(stoi(it->str()));
        ++it;
    }

    int szam = szamok[0];
    int alap = szamok[1];

    string eredmeny = konvertalas(szam, alap);
    cout << eredmeny;

    return 0;
}
