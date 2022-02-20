#include <bits/stdc++.h>
#include <algorithm>
#include <sys/time.h>
#include <windows.h>
using namespace std;

extern map<int, string> fastest;

long gettime2()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}

void insertionSort(int arr[], int n)
{
    long start = gettime2();

    int i, current, j;
    for (i = 1; i < n; i++)
    {
        current = arr[i];
        j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = current;
    }

    long end = gettime2();
    fastest.insert({(end-start),"Insert Sort"});
    string p="Insertion sort with time complexity of O(n^2) has sorted the elements in ";
    string q= to_string((end-start)/1000);
    string r=" milli seconds";
    p=p+q+r;

    for (int i = 0; i < p.length(); i++) {
        cout << p[i];
        Sleep(35);
    }
    cout<<endl;
}
