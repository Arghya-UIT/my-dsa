#include <iostream>
#include <climits>
using namespace std;
void count(int arr[], int len)
{
    int t = INT_MIN;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > t)
        {
            t = arr[i];
        }
    }
    int *b = (int *)calloc((t + 1) , sizeof(int));
    
    for (int i = 0; i < len; i++)
    {
        b[arr[i]] = b[arr[i]] + 1;
    }

    int i = 0;
    int j = 0;
    while (i <= t)
    {
        if (b[i] > 0)
        {
            arr[j] = i;
            b[i] = b[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}



int main()
{
    int arr[] = {10, 85, 96, 12, 4, 5, 8, 6, 2, 46, 2, 6, 56, 8, 468};
    int len = sizeof(arr) / sizeof(arr[0]);
    count(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}








// Here is a brief explanation of how the code works:

//     The input array is scanned to find the maximum element, which is stored in the variable t.
//     Memory is allocated for the b array using calloc, and all elements of the array are initialized to 0.
//     The b array is used to count the occurrences of each element in the input array.
//     The while loop iterates over the range of integers from 0 to t, and for each element in the b array that has a count greater than 0, the corresponding element is added to the output array and the count is decremented by 1.