#include <iostream>
using namespace std;
void bubble(int *arr, int len)
{
    for (int i = 0; i < len-1; i++)
    {
        int temp;
       for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int arr[] = {10, 85, 96, 12, 4, 5, 8, 6, 2, 46, 2, 6, 56, 8, 468};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubble(arr,len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}



// Bubble sort is a simple sorting algorithm that works by repeatedly iterating through the array and swapping adjacent elements if they are out of order. Here is a step-by-step description of the algorithm:

//     Iterate through the array, starting from the first element.
//     Compare the current element to the next element. If the current element is greater than the next element, swap them.
//     Continue iterating through the array until you reach the end.
//     Repeat this process until no swaps are made on the previous pass.