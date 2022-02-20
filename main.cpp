#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include "bubbleSort.cpp"
#include "insertionSort.cpp"
#include "mergeSort.cpp"
#include "quickSort.cpp"
#include "heapSort.cpp"

map<int, string> fastest;

class sorting
{
public:
    static int chooseSort;
    int num;
    int *array;
    sorting()
    {
        num = 0;
        chooseSort = 0;
    }
    sorting(long int a, int b)
    {
        num = a;
        chooseSort = b;
        array = (int *)malloc(num * sizeof(int));
    }
    void callsort()
    {

        void (*func_ptr[5])(int *array, int n) = {bubbleSort, insertionSort, mergeSort, quickSort, heapSort};
        while (chooseSort < 5)
        {
            for (int i = 0; i < num; i++)
            {
                array[i] = rand() % 10000;
            }
            (*func_ptr[chooseSort])(array, num);
            chooseSort++;
        }
    }
    void display()
    {
        cout << " Efficient sorting is important for optimizing the efficiency ";
        cout << "\n of other algorithms that require input data to be in sorted lists ";
        cout << "\n Sorting is also often useful for canonicalizing data and for producing human-readable output. ";
        cout << "\n So we will sort " << num << " random elements using 5 diffrent sorting algos and chechk the fastest one.......\n\n";
    }
    
};

int sorting::chooseSort = 0;



int main()
{

    sorting s1(10000, 0);
    s1.display();
    s1.callsort();
    
    map<int, string>::iterator itr;
    itr = fastest.begin();
    cout << itr->first << " " << itr->second << endl;
    cout << "\n\n";
    cout << "Well.... The fastest algorithm is "<<itr->second;
    Sleep(3);
    cout<<" The number of seconds might be more or less compared to other algos, But when the size multipled by 10 ,\n it becomes very large";
    cout<<" So it is required to choose the algorithm with least time complexity as Above";

    return 0;
}
