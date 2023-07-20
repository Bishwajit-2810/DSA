#include <bits/stdc++.h>
using namespace std;

// only use when we know the data is in 1 to N

void CycleSort(int arr[], int a, int n)
{

    int i = 0;
    while (i < a)
    {
        if (arr[i] != i + 1)
        {
            int temp = arr[i];
            arr[i] = i + 1;
            arr[i + 1] = temp;
        }
        else
        {
            i++;
        }
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
    int N; // the highest value

    CycleSort(arr, a, N);

    for (int i = 0; i < a; i++)
    {

        cout << arr[i] << " ";
    }
    cout << endl;
}
