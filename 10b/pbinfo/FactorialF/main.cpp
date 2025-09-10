#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    
    int p = 1;
    for(int i = 1; i <= n; i++)
    {
        p *= i;
    }

    return p;
}

int main()
{
    int n;
    cin >> n;

    long long factorial = fact(n);
    cout << factorial;
}