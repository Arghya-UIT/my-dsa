#include <iostream>
using namespace std;
void insertion(int *arr, int len)
{
    int min,j;
    for (int i = 1; i < len; i++)
    {
        min=arr[i];
        j=i-1;
        while(j>=0&&min<arr[j]){
            arr[j+1]=arr[j];
            j--;

        }
        arr[j+1]=min;
    }
}
int main()
{
    int arr[] = {10, 85, 96, 12, 4, 5, 8, 6, 2, 46, 2, 6, 56, 8, 468};
    int len = sizeof(arr) / sizeof(arr[0]);
    insertion(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}




// -1   0    1   2   3   4   5
   //      12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
   //      12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

   //      12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
   //      12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

   //      12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
   //      12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
   //      12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
   //      12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
   //      07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

   // Fast forwarding and 4th and 5th pass will give:
   //      07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
   //      07, 12, 23, 54,| 65, 09 --> After the 4th pass

   //      07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
   //      07, 09, 12, 23, 54, 65| --> After the 5th pass 




//    Insertion sort is a simple sorting algorithm that works by building up the sorted part of the array one element at a time. Here is a step-by-step description of the algorithm:

//     Consider the first element in the array to be the sorted part of the array.
//     Pick the next element in the array and insert it into the correct position in the sorted part of the array.
//     Repeat this process until the entire array is sorted.