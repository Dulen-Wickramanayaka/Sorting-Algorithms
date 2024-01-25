/*
Topic : merge Sort Algorithm in C
Author: DUlen Wickramanayaka
Date: 1/25/2024
Description: this is a simple algorithm that can sort a given array of integers using
             merge sort.
*/


#include <stdlib.h>
#include <stdio.h>

void merge_sort(int *array, int size);
void print_array(int *array, int size);
void merge(int *array,int size,int *left, int* right, int L, int R);

int main(void)
{
    int array[] = {3,7,2,4,6,5,1}; //unsorted array
    int size = sizeof(array) / sizeof(array[0]); // number of elements in the array
    merge_sort(array, size); // calling the sorting funtion

    print_array(array,size);

    return 0;
}

void merge_sort(int *array, int size)
{
    if (size < 2) return;
    int mid = size / 2;
    int L = mid, R = size - (mid); // number of elements in the left half and the right half
    //printf("mid : %i left : %i   right : %i\n", mid, L, R);

    //allocation memory for the right half and for the left half
    int *left = malloc(L * sizeof(int));
    int *right = malloc(R * sizeof(int));

    //cheking if the memory allocation is successfull
    if (left == NULL || right == NULL)
    {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    //initializing the left half and the right half
    for (int i = 0; i < L; i++)
    {
        left[i] = array[i];
    }
    for (int j = 0; j < R; j++)
    {
        right[j] = array[j + mid];
    }

    //soring each half(smaller arrays) because idea of merge sort is to devide and conqure
    merge_sort(left, L);
    merge_sort(right, R);

    //mering the two sorted arrays
    merge(array,size,left,right,L,R);

    //freeing the allocated memory
    free(left);
    free(right);
}

void merge(int *array,int size,int *left, int* right, int L, int R)
{
    int i = 0, j = 0, k = 0; //initializing the ariables needed for while loops
    // i is the position in the left part and j is the position in the right part

    while (i < L && j < R)
    {
        if (left[i] < right[j]) // current value in the beggining of left half is smaller than it in the begining or right part
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[], if there are any
    while (i < L) {
        array[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[], if there are any
    while (j < R) {
        array[k] = right[j];
        j++;
        k++;
    }
}

void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i  ", array[i]);
    }
    printf("\n");
}
