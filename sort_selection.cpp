#include <iostream>
using namespace std;
void selection(int *arr, int len)
{
    int temp;
    for (int i = 0; i < len - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        
    }
}
int main()
{
    int arr[] = {10, 85, 96, 12, 4, 5, 8, 6, 2, 46, 2, 6, 56, 8, 468};
    int len = sizeof(arr) / sizeof(arr[0]);
    selection(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}




// find the lowest element in the arrey and bring it to 1st position them swap them


// arr[i]== minindex which should comapre with tehe whlole arey if arr[j]is lwsser then swap 



// Here is a step-by-step description of the selection sort algorithm:

//     Find the minimum element in the unsorted part of the array.
//     Swap the minimum element with the first element in the unsorted part of the array.
//     Move the boundary of the unsorted part of the array one element to the right.
//     Repeat this process until the entire array is sorted.