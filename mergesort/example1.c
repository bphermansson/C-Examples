/**
 * @file exercise14.c
 * @author Patrik Hermansson (hermansson.patrik@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-09
 * 
 * @copyright Copyright (c) Patrik Hermansson 2021
 * 
 * Make a program to fill a 10-element int array with random numbers, then
 * print the array to the output.
 * sort the array ascending and then
 * Print the sorted array to the output.
 * To generate random numbers, you can use srand and rand functions in stdlib.h and the time function in time.h.
 * For example:
 * The array filled with random numbers: {9, 3, 8, 0, 5, 2, 6, 7, 1, 4}
 * The sorted array: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 } 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "exercise-14.h"

#define ARRAY_LENGTH 10

// Array A[] has the items to sort; array B[] is a work array.
void TopDownMergeSort(int A[], int B[], int n)
{
    CopyArray(A, 0, n, B);           // one time copy of A[] to B[]
    TopDownSplitMerge(B, 0, n, A);   // sort data from B[] into A[]
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
    int A[ARRAY_LENGTH];
    int B[ARRAY_LENGTH];

    srand(time(0)); 
    for (uint8_t i = 0; i < ARRAY_LENGTH; ++i)
    {
        A[i] = rand() % 10;
    }

    printf("Unsorted list: ");
    for(int y=0;y<=ARRAY_LENGTH-1;y++)
    {
        printf("%d,", A[y]);
    }
    printf("\n");

    TopDownMergeSort(A, B, ARRAY_LENGTH);

    printf("Sorted list:   ");
    for(int y=0;y<=ARRAY_LENGTH-1;y++)
    {
        printf("%d,", A[y]);
    }
    printf("\n");
    return 0;
}