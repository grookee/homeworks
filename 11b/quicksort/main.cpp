#include <iostream>
#include <chrono>

// szukseges konyvtarak deklaralasa
#include <stdlib.h>
#include <stdio.h>

// a tomb meretenek meghatarozasa
#define n 1000000

using namespace std;

void normal(int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (arr[i] > arr[j])
            {
                int aux = arr[j];
                arr[j] = arr[i];
                arr[i] = aux;
            }
        }
    }
}

void quickSort(int arr[], int balindex, int jobbindex)
{

    int i = balindex, j = jobbindex;

    int tmp;
    int pivot = arr[(balindex + jobbindex) / 2];

    while (i <= j)
    {

        while (arr[i] < pivot)

            i++;

        while (arr[j] > pivot)

            j--;

        if (i <= j)
        {

            tmp = arr[i];

            arr[i] = arr[j];

            arr[j] = tmp;

            i++;

            j--;
        }
    };

    if (balindex < j)

        quickSort(arr, balindex, j);

    if (i < jobbindex)

        quickSort(arr, i, jobbindex);
}

int main()
{
    srand(0);
    int v[n];
    for (int i = 0; i < n; i++)
    {

        v[i] = rand() % 10000;
    }

    auto start = std::chrono::high_resolution_clock::now();
    normal(v);
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Normal sort took " << duration.count() << " microseconds (" 
         << duration.count() / 1000.0 << " ms)" << endl;
    
    // Regenerate array for quicksort
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 10000;
    }
    
    auto start2 = std::chrono::high_resolution_clock::now();
    quickSort(v, 0, n - 1);
    auto end2 = std::chrono::high_resolution_clock::now();
    
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2);
    cout << "QuickSort took " << duration2.count() << " microseconds (" 
         << duration2.count() / 1000.0 << " ms)" << endl;
    
    return 0;
}