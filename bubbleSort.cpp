#include <bits/stdc++.h>
#include <algorithm>
#include <sys/time.h>
#include <windows.h>
using namespace std;

extern map<int, string> fastest;

long gettime1()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

void swap1(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    long start = gettime1();
    int i, j;
    int counter = 1;
    while (counter < n)
    {
        for (j = 0; j < n - counter - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap1(&arr[j], &arr[j + 1]);
            }
        }
        counter++;
    }

    long end = gettime1();
    fastest.insert({(end-start),"Bubble Sort"});

     string p="Bubble sort with time complexity of O(n^2) has sorted the elements in ";
    string q= to_string((end-start)/1000);
    string r=" milli seconds";
    p=p+q+r;

    for (int i = 0; i < p.length(); i++) {
        cout << p[i];
        Sleep(35);
    }
    cout<<endl;
}