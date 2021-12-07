/**
 * @file mergesort.c
 * @author your name (you@domain.com)
 * @brief 
 * A test of the code from https://en.wikipedia.org/wiki/Merge_sort
 * @version 0.1
 * @date 2021-12-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "mergesort.h"
#include <stdio.h>

// Array A[] has the items to sort; array B[] is a work array.
int * TopDownMergeSort(int A[], int B[], int n)
{
    CopyArray(A, 0, n, B);           // one time copy of A[] to B[]
    TopDownSplitMerge(B, 0, n, A);   // sort data from B[] into A[]
    return A;
}

// Split A[] into 2 runs, sort both runs into B[], merge both runs from B[] to A[]
// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
    if (iEnd - iBegin <= 1)                     // if run size == 1
        return;                                 //   consider it sorted
    // split the run longer than 1 item into halves
    int iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
    // recursively sort both runs from array A[] into B[]
    TopDownSplitMerge(A, iBegin,  iMiddle, B);  // sort the left  run
    TopDownSplitMerge(A, iMiddle,    iEnd, B);  // sort the right run
    // merge the resulting runs from array B[] into A[]
    TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

// Left source half is A[ iBegin:iMiddle-1].
// Right source half is A[iMiddle:iEnd-1   ].
// Result is            B[ iBegin:iEnd-1   ].
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
    int i = iBegin, j = iMiddle;
 
    // While there are elements in the left or right runs...
    for (int k = iBegin; k < iEnd; k++) {
        // If left run head exists and is <= existing right run head.
        if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;
        }
    }
}

void CopyArray(int A[], int iBegin, int iEnd, int B[])
{
    for (int k = iBegin; k < iEnd; k++)
        B[k] = A[k];
}

// Comment out/remove main() if including in another project. 
int main()
{
    int B[] = {0};
    int A[] = {3,6,1,4,5};
    int length= sizeof(A)/sizeof(A[0]);

    printf("Unsorted list: ");
    for(int y=0;y<=4;y++)
    {
        printf("%d,", A[y]);
    }
    printf("\n");

    TopDownMergeSort(A, B, length);

    int *sorted = TopDownMergeSort(A, B, length);


    printf("Sorted list: ");
    for(int y=0;y<=4;y++)
    {
        printf("%d,", sorted[y]);
    }
    printf("\n");
    return 0;
}