#include <bits/stdc++.h>
using namespace std;

// int b[99999];


void merge(int arr[], int l, int m, int r)
{
    int b[99999];
    int i = l;
    int j = m + 1;
    int k = l;
    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }

    while (j <= r)
    {
        b[k] = arr[j];
        j++;
        k++;
    }

    while (i <= m)
    {
        b[k] = arr[i];
        i++;
        k++;
    }

    for (int t = l; t <= r; t++)
    {
        arr[t] = b[t];
    }
}


void mergeSort(int arr[], int l, int r)
{
    int m;
    if (l < r)
    {
        m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}



int main()
{
    int a;
    cin >> a;
    int arr[a];
    for (int i = 0; i < a; i++)
    {

        cin >> arr[i];
    }
    mergeSort(arr, 0, a - 1);

    for (int i = 0; i < a; i++)
    {

        cout << arr[i] << " ";
    }
}