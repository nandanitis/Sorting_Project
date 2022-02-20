#include <bits/stdc++.h>
#include <algorithm>
#include <sys/time.h>
#include <windows.h>
using namespace std;

extern map<int, string> fastest;

long gettime3()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}


void mergelast(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = a[i];
        i++;k++;
        
    }
    while (j < n2)
    {
        arr[k] = b[j];
        j++;k++;

    }
}

void mergeRecr(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeRecr(arr, l, mid);
        mergeRecr(arr, mid + 1, r);

        mergelast(arr, l, mid, r);
    }
}

void mergeSort(int arr[], int n)
{
   long start = gettime3();

    mergeRecr(arr,0, n-1);

    long end = gettime3();
    fastest.insert({(end-start),"Merge Sort"});

    string p="Merge sort with time complexity of O(n(logn)) has sorted the elements in ";
    string q= to_string((end-start)/1000);
    string r=" milli seconds";
    p=p+q+r;

    for (int i = 0; i < p.length(); i++) {
        cout << p[i];
        Sleep(35);
    }
    cout<<endl;
}