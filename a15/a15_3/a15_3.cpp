//
//  a15_3.cpp
//  a15_3
//
//  Created by Chadwick Leung on 5/13/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//
/*
 Chadwick Leung
 CS 10B
 5/15/19
 Dave Harden
 Assignment 15_1
 
 This program would use recursion to sort an array of integers into ascending order
 using the following idea: the function will place the smallest element in the first
 position, then sort the rest of the array by a recursive call.
 
 It has two auxiliary functions, swap and indexofSmaller to help me find the smallest
 item in the array and swap it with the first position in the function
 */

#include <iostream>

using namespace std;

void swap(int [], int, int);
int indexofSmallest(int [], int, int);
void sort(int [], int, int);

int main()
{
    int a[5] = {2, 10, 7, 9, 8};
    for (int count = 0; count < 5; count++)
    {
        cout << a[count] <<endl;
    }
    
    sort(a, 5, 0);
    
    cout << "After sorting: " <<endl;
    for (int count = 0; count < 5; count++)
    {
        cout << a[count] <<endl;
    }
    
    
    return 0;
}




/*
 This funciton would swap the position of the two indices input, swap1 and swap2
 
 pre: the array of integers is input as array[], start position is input as swap1,
 and end position is input as swap2
 post: the position of swap1 and swap2 is swapped
 */
void swap(int array[], int swap1, int swap2)
{
    char swap = array[swap1];
    array[swap1] = array[swap2];
    array[swap2] = swap;
}





/*
 This funciton is an auxiliary function that finds the index of the smallest item
 in the array and return it
 The smallest item is different with different starting point (start)
 
 pre: the array of integers is input as array[], the size of the array is input as
 size, and the starting point is input as start
 post: return the index of the smallest item in the array
 */
int indexofSmallest(int array[], int size, int start)
{
    int index = start;
    
    int value = array[start];
    
    for (int count = start; count < size; count++)
    {
        if (array[count] < value)
        {
            value = array[count];
            index = count;
        }
    }
    
    return index;
    
}





/*
 This is a recursive function that would find the smallest item in the array using
 indexofSmallest function and swap it with the first position in the remaining
 array using swap function
 
 pre: the array of integers is input as array[], the size of the array is input as
 size, and the starting point is input as start
 post: the array of integers will be sorted into ascending order
 */
void sort(int array[], int size, int start)
{
    if (start >= size-1)
        return;
    
    int smallest = indexofSmallest(array, size, start);
    
    swap(array, start, smallest);
    
    sort(array, size, start+1);
}







//2
//10
//7
//9
//8
//After sorting:
//2
//7
//8
//9
//10
