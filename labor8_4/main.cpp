#include <iostream>
#include <fstream>
#include <vector>
#include "ctrack.hpp"

int countMaxEvenRuns(const std::vector<int>& numbers) {
    CTRACK;

    int current_run_length = 0;
    int max_length = 0;
    int count = 0;

    for (const int& number : numbers) {
        if (number % 2 == 0) {
            current_run_length++;
        } else {
            if (current_run_length >= 2) {
                if (current_run_length > max_length) {
                    max_length = current_run_length;
                    count = 1;
                } else if (current_run_length == max_length) {
                    count++;
                }
            }
            current_run_length = 0;
        }
    }

    if (current_run_length >= 2) {
        if (current_run_length > max_length) {
            max_length = current_run_length;
            count = 1;
        } else if (current_run_length == max_length) {
            count++;
        }
    }

    return count;
}

int main()
{
    std::ifstream infile("bac.txt");
    if (!infile)
    {
        return 1;
    }

    std::vector<int> numbers;
    int num;

    while (infile >> num)
    {
        numbers.push_back(num);
    }

    int count = countMaxEvenRuns(numbers);

    infile.close();

    std::cout << count << std::endl;
    ctrack::result_print();
    return 0;
}