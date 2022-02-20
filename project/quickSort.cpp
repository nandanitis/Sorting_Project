#include <bits/stdc++.h>
#include <algorithm>
#include <sys/time.h>
#include <string>
#include <windows.h>
using namespace std;

extern map<int, string> fastest;

long gettime4()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return (i + 1);
}

void Sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);

        Sort(arr, l, pi - 1);
        Sort(arr, pi + 1, r);
    }
}

void quickSort(int arr[], int n)
{
    long start = gettime4();
    Sort(arr, 0, n - 1);
    long end = gettime4();
    fastest.insert({(end-start),"Quick Sort"});

    string p="Quick sort with time complexity of O(n(logn)) has sorted the elements in ";
    string q= to_string((end-start)/1000);
    string r=" milli seconds";
    p=p+q+r;

    for (int i = 0; i < p.length(); i++) {
        cout << p[i];
        Sleep(35);
    }
    cout<<endl;

}