/*
Topic : Bubble Sort Algorithm in C
Author: DUlen Wickramanayaka
Date: 1/24/2024
Description: this is a simple algorithm that can sort a given array of integers using
             Bubble sort sort.
*/

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *array, int size);
void swap_elements(int *array,int index);
void print_array(int *array, int size);

int main(void)
{
    int array[] = {3,7,2,4,6,5,1}; //unsorted array
    int size = sizeof(array) / sizeof(int); //finding howmany elements are in the array

    bubble_sort(array,size);

    // printing the sorted array
    print_array(array,size);

}


//as arrays are passed by reference(calee recieve the original array instead of copy) return is not needed cause changes are dne to original array
void bubble_sort(int *array, int size)
{
    int swap_counter = 1; // swap counter is incremented when to adjesent pair in array are swapped becouse fisrt one is bigger than second

    while (swap_counter != 0) // while no swaps are happend(that means every pair is sorted and then whole array is sorted)
    {
        swap_counter = 0; // at the begining of each iteration swap counter should be set to 0 beacuse it stores the number of swaps happen in before iteration

        // looping through every adjecent pair
        for (int i = 0; i < (size - 1); i++) 
        {
            // if the value at current index is bigger than value at next index they should be swapped
            if (array[i] > array[i + 1])
            {
                swap_elements(array,i); //swapping the value at current index with next
                swap_counter++; // when swaps happen swap counter should be incremented
            }
        }
    }
}

// this function swapped the value at current index with the value at next
void swap_elements(int *array,int index)
{
    int temp = array[index]; //when array[index] is set equal to value at next index value at array[index] is gone forever. so it should be stored in temporary variable
    array[index] = array[(index + 1)];
    array[(index + 1)] = temp;
}

void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i  ", array[i]);
    }
    printf("\n");
}

/* here is the logic used :
        if an array is sorted in each adjesent pair first element should be smaller than the next
        so we can find if an array is sorted or not by that concept.

        and if in an adjecent pair first elemet is bigger than next those elemnts should be swapped
        by doing this should be done while array is completly sorted.  

        what happens here is in each iteration of the main loop biggest elemet is pushed towards end.  
*/
