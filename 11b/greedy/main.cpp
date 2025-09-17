#include <iostream>
#include <vector>
#include <fstream>

int main() {
    int n;
    std::ifstream infile("test.in");
    infile >> n;
    
    std::vector<int> start(n);
    std::vector<int> finish(n);
    std::vector<int> activity(n);

    for (int i = 0; i < n; i++) {
        infile >> start[i];
    }

    for (int i = 0; i < n; i++) {
        infile >> finish[i];
    }

    for (int i = 0; i < n; i++) {
        infile >> activity[i];
    }

    infile.close();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (finish[j] > finish[j + 1]) {
                int temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;
                
                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
                
                temp = activity[j];
                activity[j] = activity[j + 1];
                activity[j + 1] = temp;
            }
        }
    }
    
    std::vector<int> selected;
    
    selected.push_back(activity[0]);
    int lastFinishTime = finish[0];
    
    for (int i = 1; i < n; i++) {
        if (start[i] >= lastFinishTime) {
            selected.push_back(activity[i]);
            lastFinishTime = finish[i];
        }
    }

    for (int i : selected) {
        std::cout << i << " ";
    }
    
    return 0;
}
