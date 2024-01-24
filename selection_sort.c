/*
Topic : Selection Sort Algorithm in C
Author: DUlen Wickramanayaka
Date: 1/24/2024
Description: this is a simple algorithm that can sort a given array of integers using
             selection sort.
*/

#include <stdio.h>
#include <stdlib.h>

void sort(int *array,int size);

int main (void)
{
    int array[] = {3,7,2,4,6,5,1};
    int size = (sizeof(array) / sizeof(int)); //finding how many elements are in the array

    sort(array,size);

    for (int i = 0; i < size; i++)
    {
        printf("%i  ",array[i]);
    }
    printf("\n");
}

void sort(int *array,int size)
{   
    //looping through the array
    for (int i = 0; i < size; i++)
    {
        int sm = i; //index of the smallest element

        //finding smallest element in the unsorted part
        for (int j = i; j < size; j++)
        {
            if(array[j] < array[sm]) sm = j;
        }

        //swapping the smallest element with first element of unsorted part
        int temp = array[i];
        array[i] = array[sm];
        array[sm] = temp;
    }
}

/*
here is the logic used:
every value before the index i is sorted and values after index i are the unsorted part
at every iteration of the main loop smallest element of the unsorted part is swapped withfirst element of the unsorted
list and then i is incrementd(when i is incremened that smallest elemt at the beginning gets belong to the sorted part)
*/