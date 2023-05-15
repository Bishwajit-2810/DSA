#include <bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int n, int k)
{
    int min = 0, max = n - 1, mid;

    while (min <= max)
    {
        mid = (min + max) / 2;
        if (k < arr[mid])
        {
            max = mid - 1;
        }
        else if (k > arr[mid])
        {
            min = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}






int main()
{
    int a, b;
    cin >> a >> b;
    int arr[a];

    for (int i = 0; i < a; i++)
    {
        cin >> arr[i];
    }

    int d = binarysearch(arr, a, b);
    cout << d;
}