#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "ctrack.hpp"

using namespace std;

int particionalas(vector<int> &tomb, int alacsony, int magas)
{
    CTRACK;

    int oszlop = tomb[magas];
    int i = (alacsony - 1);

    for (int j = alacsony; j <= magas - 1; j++)
    {
        if (tomb[j] < oszlop)
        {
            i++;
            int temp = tomb[i];
            tomb[i] = tomb[j];
            tomb[j] = temp;
        }
    }
    int temp = tomb[i + 1];
    tomb[i + 1] = tomb[magas];
    tomb[magas] = temp;
    return i + 1;
}

void gyorsRendezes(vector<int> &tomb, int alacsony, int magas)
{
    CTRACK;
    while (alacsony < magas)
    {
        int index = particionalas(tomb, alacsony, magas);

        if (index - alacsony < magas - index)
        {
            gyorsRendezes(tomb, alacsony, index - 1);
            alacsony = index + 1;
        }
        else
        {
            gyorsRendezes(tomb, index + 1, magas);
            magas = index - 1;
        }
    }
}

int main()
{
    srand(time(0));

    int N;
    cin >> N;

    ofstream fout("feladat.out");

    vector<int> szamok(N);

    for (int i = 0; i < N; i++)
    {
        szamok[i] = rand() % 100;
    }

    gyorsRendezes(szamok, 0, N - 1);

    for (int i = 0; i < N; i++)
    {
        fout << szamok[i] << " ";
    }

    fout.close();
    ctrack::result_print();

    return 0;
}