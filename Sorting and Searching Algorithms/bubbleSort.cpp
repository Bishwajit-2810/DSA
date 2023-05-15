#include <bits/stdc++.h>
using namespace std;

// Function to sort the array using advance bubble sort algorithm.
void advance_bubbleSort(int arr[], int n)
{

    int temp;

    // if we start the array from 1 only then it will iterate to n
    for (int i = 0; i < n - 1; i++)
    {
        // here n-1 base case and we are using n-1-i cause in every loop the last array member is auto sorting
        // if the array is            4 1 3 9 7
        // after first iteration      1 3 4 7 9
        // the last element sort first cause it is the highest
        // thats why we use n-1-i

        bool sorted = false;
        // for optimised bubble sort
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                sorted = true;
            }
        }
        // if i full itreation doesnot do anything that means the array is sorted
        if (sorted == false)
        {
            break;
        }
    }
}

// Function to sort the array using bubble sort algorithm.
void bubbleSort(int arr[], int n)
{

    int temp;

    // if we start the array from 1 only then it will iterate to n
    for (int i = 0; i < n - 1; i++)
    {
        // here n-1 base case and we are using n-1-i cause in every loop the last array member is auto sorting
        // if the array is            4 1 3 9 7
        // after first iteration      1 3 4 7 9
        // the last element sort first cause it is the highest
        // thats why we use n-1-i

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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
    bubbleSort(arr, a);

    for (int i = 0; i < a; i++)
    {

        cout << arr[i] << " ";
    }
}