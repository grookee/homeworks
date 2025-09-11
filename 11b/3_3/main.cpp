#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("bac.in");
    
    int start, end;
    fin >> start >> end;

    int count = 0;
    int last = 0;
    int num = 1;
    
    int museum_start, museum_end;
    
    while (fin >> museum_start >> museum_end) {
        
        int overlap_start = max(start, museum_start);
        int overlap_end = min(end, museum_end);
        
        if (overlap_start < overlap_end && (overlap_end - overlap_start) >= 1) {
            count++;
            last = num;
        }
        
        num++;
    }
    
    fin.close();
    
    cout << count << " " << last << endl;
    
    return 0;
}