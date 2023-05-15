#include <bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int n, int k)
{
    // return -1 for not found
    // return position if found

    int a = -1;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] == k)
        {
            return i + 1;
        }
    }
    return a;
}

int main()
{
    int a, b;
    cin >> a, b;
    int arr[a];

    for (int i = 0; i < a; i++)
    {

        cin >> arr[i];
    }

    int a = linear_search(arr, a, b);
    cout << a;
    // output -1 for not found
    // output position if found
}