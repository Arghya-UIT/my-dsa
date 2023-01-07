#include <iostream>
using namespace std;
int partision(int a[], int l, int h)
{
    int pvt = a[l];
    int i = l + 1;
    int j = h;
    do
    {
        while (a[i] <= pvt)
        {
            i++;
        }
        while (a[j] > pvt)
        {
            j--;
        }
        if (i < j)
        {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    } while (i < j);
    int tmp = a[l];
    a[l] = a[j];
    a[j] = tmp;
    return j;
}
void marge(int a[], int l, int h)
{
    int parti;
    if (l < h)
    {
        parti = partision(a, l, h);
        marge(a, l, parti - 1);
        marge(a, parti + 1, h);
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
Quick sort is a divide and conquer sorting algorithm that works by choosing a pivot element and partitioning the array around it, such that all elements less than the pivot are moved to its left and all elements greater than the pivot are moved to its right. The process is then repeated on the left and right halves of the array until the array is sorted.

Here is a step-by-step description of the quick sort algorithm:

    If the array has a length of 0 or 1, return the array as it is already sorted.
    Choose a pivot element from the array.
    Partition the array around the pivot by iterating through the array and moving elements less than the pivot to its left and elements greater than the pivot to its right.
    Recursively sort the left and right halves of the array.
    */