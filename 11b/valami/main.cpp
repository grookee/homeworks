#include <iostream>
using namespace std;

int main()
{
    int n, x, y, S = 0;
    cin >> n;
    
    int similar = n % 10;
    cin >> x >> y;
    
    for (int i = x; i <= y; i++) {
        int temp = i;
        bool nagyobb = true;

        while (temp > 0) {
            int szj = temp % 10;
            if (szj < similar) {
                nagyobb = false;
                break;
            }
            temp /= 10;
    
        }

        if (nagyobb)
        {
            S += i;
        }
    }
    
    cout << S << endl;


    return 0;
}