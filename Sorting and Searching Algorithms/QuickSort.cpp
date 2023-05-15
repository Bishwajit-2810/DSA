#include <bits/stdc++.h>
using namespace std;

// best to understand
int partition(int arr[], int low, int high)
{
    int i = low - 1;
    int pivot = arr[high];
    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

void quickSort(int arr[], int low, int high)
{
    int pivot;
    if (high <= low)
    {
        return;
    }
    pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
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
    quickSort(arr, 0, a - 1);
    for (int i = 0; i < a; i++)
    {

        cout << arr[i] << " ";
    }
}

// worst to learn and understand
int shitty_partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}