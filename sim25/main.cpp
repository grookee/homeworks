#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;

int getStones(const int& label)
{
    int first = label / 10;
    int second = label % 10;

    return first * 10 + second;
}

int main()
{
    ifstream fin("bijuterii.in");
    int nc, np;
    fin >> nc >> np;

    unordered_set<int> earringPairs;

    for (int i = 0; i < nc; i++)
    {
        int earring;
        fin >> earring;
        earringPairs.insert(getStones(earring));
    }    

    for (int i = 0; i < np; i++)
    {
        int necklace;
        fin >> necklace;
        if (earringPairs.count(getStones(necklace)))
        {
            cout << "DA" << endl;
            return 0;
        }
    }

    cout << "NU" << endl;

    return 0;
}
