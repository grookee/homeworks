#include <bits/stdc++.h>
using namespace std;

bool tokeletes(int n)
{
    int sum = 1;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == n / i)
                sum += i;
            else
                sum += i + n / i;
        }
    }

    return (sum == n && n != 1);
}

int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");

    int n;
    fin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        fin >> x;

        if (tokeletes(x))
            fout << 1 << '\n';
        else
            fout << 0 << '\n';
    }

}