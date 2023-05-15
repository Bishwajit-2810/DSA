#include <bits/stdc++.h>
using namespace std;

int maximum(int arr[], int n)
{
    int k = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > k)
        {
            k = arr[i];
        }
    }

    return k;
}
void countSort(int arr[], int n)
{
    int max = maximum(arr, n);

    int count[max + 1];
    for (int i = 0; i < max + 1; i++)
    {

        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {

        count[arr[i]]++;
    }

    int i = 0;
    int j = 0;

    while (i <= max)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
}

void advance_countSort(int arr[], int n)
{
    int max = maximum(arr, n);

    int *count;
    count = (int *)malloc(sizeof(int) * (max + 1));

    for (int i = 0; i < max + 1; i++)
    {

        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {

        count[arr[i]]++;
    }

    int i = 0;
    int j = 0;

    while (i <= max)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
    free(count);
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

    countSort(arr, a);

    for (int i = 0; i < a; i++)
    {

        cout << arr[i] << " ";
    }
}