#include <bits/stdc++.h>
#include <algorithm>
#include <sys/time.h>
#include <windows.h>
using namespace std;

extern map<int, string> fastest;

long gettime5()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSortNow(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void heapSort(int arr[], int n)
{
    long start = gettime5();
    heapSortNow(arr, n);
    long end = gettime5();
    fastest.insert({(end-start),"Heap Sort"});

    string p = "Heap sort with time complexity of O(n(logn)) has sorted the elements in ";
    string q = to_string((end - start) / 1000);
    string r = " milli seconds";
    p = p + q + r;
    for (int i = 0; i < p.length(); i++)
    {
        cout << p[i];
        Sleep(35);
    }
    cout << endl;
}
