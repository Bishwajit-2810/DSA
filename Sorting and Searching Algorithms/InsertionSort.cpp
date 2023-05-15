#include <bits/stdc++.h>
using namespace std;

void advance_insertionSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        int value = arr[i];
        for (j = i - 1; (j >= 0) && (arr[j] > value); j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = value;
    }
}



void insertionSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        int value = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > value)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = value;
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
    insertionSort(arr, a);

    for (int i = 0; i < a; i++)
    {

        cout << arr[i] << " ";
    }
}