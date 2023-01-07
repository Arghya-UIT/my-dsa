#include <iostream>
using namespace std;
void marging(int arr[], int m, int l, int h)
{
    int i = l, j = m+1, k = l;
    int b[h + 1];
    while (i <= m && j <= h)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= m)
    {
        b[k] = arr[i];
        k++;
        i++;
    }
    while (j <= h)
    {
        b[k] = arr[j];
        j++;
        k++;
    }
     for (int i = l; i <= h; i++)
    {
        arr[i] = b[i];
    }
}
void marge(int arr[], int l, int h)
{
    if (l < h)
    {

        int mid = (l + h) / 2;
        marge(arr, l, mid);
        marge(arr, mid + 1, h);
        marging(arr, mid, l, h);
    }
}
int main()
{
    int arr[] = {10, 85, 96, 12, 4, 5, 8, 6, 2, 46, 2, 6, 56, 8, 468};
    int len = sizeof(arr) / sizeof(arr[0]);
    marge(arr, 0, len - 1);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}










/*
Merge sort is a divide and conquer sorting algorithm that works by recursively dividing the array into smaller pieces, sorting each piece, and then merging the sorted pieces back together. Here is a step-by-step description of the algorithm:

    // If the array has a length of 0 or 1, return the array as it is already sorted.
    // Split the array into two halves.
    // Recursively sort the left half of the array.
    // Recursively sort the right half of the array.
    // Merge the left and right halves by iterating through both halves and adding the smaller element to a new array until one of the halves is empty. Add the remaining elements from the non-empty half to the new array.

Here is some example code that demonstrates how to implement merge sort in C++:

#include <iostream>
using namespace std;

void merge(int *arr, int *temp, int leftStart, int rightEnd)
{
    int leftEnd = (rightEnd + leftStart) / 2;
    int rightStart = leftEnd + 1;
    int size = rightEnd - leftStart + 1;

    int left = leftStart;
    int right = rightStart;
    int index = leftStart;

    while (left <= leftEnd && right <= rightEnd)
    {
        if (arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            left++;
        }
        else
        {
            temp[index] = arr[right];
            right++;
        }
        index++;
    }

    for (int i = 0; i <= leftEnd - left; i++)
    {
        temp[index + i] = arr[left + i];
    }

    for (int i = 0; i <= rightEnd - right; i++)
    {
        temp[index + i] = arr[right + i];
    }

    for (int i = leftStart; i <= rightEnd; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int *arr, int *temp, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int middle = (left + right) / 2;
    mergeSort(arr, temp, left, middle);
    mergeSort(arr, temp, middle + 1, right);
    merge(arr, temp, left, right);
}

int main()
{
    int arr[] = {10, 85, 96, 12, 4, 5, 8, 6, 2, 46, 2, 6, 56, 8, 468};
    int len = sizeof(arr) / sizeof(arr[0]);
    int *temp = new int[len];
    mergeSort(arr, temp, 0, len - 1);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

This code sorts the array using the merge sort algorithm. The mergeSort function is called recursively on the left and right halves of the array until the arrays are of length 0 or 1. The merge function is then used to merge the sorted halves of the array back together. The `


*/