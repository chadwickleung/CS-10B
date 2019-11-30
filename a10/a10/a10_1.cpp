//
//  client program.cpp
//  a10
//
//  Created by Chadwick Leung on 4/8/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

/*
 Chadwick Leung
 CS 10B
 4/9/19
 Dave Harden
 Assignment 10
 
 This program plays rhe game of life. This game is a computer simulation of the
 life and death events in a population of single-cell organisms. Each position in
 a two dimensional array can support one cell. The program will determine whether
 each position will be able to support life in the next generation

 */





#include <iostream>
#include "boolMatrix.h"
#include <fstream>

using namespace std;

void readData(boolMatrix &array);

void evolve(boolMatrix &array, int NUMlife);

void NUMevolve(int &NUMlife);

void stat(boolMatrix array);






int main()
{
    boolMatrix array1;
    
    readData(array1);
    
    int NUMlife;
    
    NUMevolve(NUMlife);
   
    evolve(array1, NUMlife);
    
    stat(array1);
    
    return 0;
}







/*
 This function would read the data from the input text file and assign a bool value
 to the element in the array with respect to the information in the input file.
 It would set the elements in the text file as a true value, otherwise, false.
 
 pre : Input file is stored in the file
 post: Set the respective element as a true value
 */
void readData(boolMatrix &array)
{
    ifstream infile("data.txt");
    int row, col;

    boolMatrix();

    infile >> row >> col;
    while (infile)
    {
        array.set(row, col, true);
        infile >> row >> col;
    }
    infile.close();
}






/*
 This function would simulate the evolve process of the cells in the array.
 It has the following rules:
 1. If the cell is currently empty:
    1. If the cell has exactly three living neighbors, it will come to life in the
    next generation.
    2. If the cell has any other number of living neighbors, it will remain empty.
 2. If the cell is currently living:
    1. If the cell has one or zero living neighbors, it will die of loneliness in
       the next generation.
    2. If the cell has four or more living neighbors, it will die of overcrowding
       in the next generation.
    3. If the cell has two or three neighbors, it will remain living.
 3. All births and deaths occur simultaneously. This point is critical to the correct result.
 
 pre : The array was set and each element in it has a bool value
 post: A new array that uses pointer to determine whether each element would have a
 true or false value.
 */
void evolve(boolMatrix &array, int NUMlife)
{
    boolMatrix *arrayptr;
    
    arrayptr = &array;
    
    for (int lifeCount = 0; lifeCount < NUMlife; lifeCount++)
    {
        boolMatrix *arrayOUTptr = new boolMatrix;
        
        for (int rowL = 0; rowL < boolMatrix::NUM_ROWS; rowL++)
        {
            for (int colL = 0; colL < boolMatrix::NUM_COLS; colL++)
            {
                if ((*arrayptr).get(rowL, colL) == false)
                {
                    if ((*arrayptr).neighborCount(rowL, colL) == 3)
                    {
                        (*arrayOUTptr).set(rowL, colL, true);
                    }
                }
                
                else if ((*arrayptr).get(rowL, colL) == true)
                {
                    if ((*arrayptr).neighborCount(rowL, colL) <= 1)
                    {
                        (*arrayOUTptr).set(rowL, colL, false);
                    }
                    
                    else if ((*arrayptr).neighborCount(rowL, colL) >= 4)
                    {
                        (*arrayOUTptr).set(rowL, colL, false);
                    }
                    
                    else
                    {
                        (*arrayOUTptr).set(rowL, colL, true);
                    }
                }
            }
        }
        
        arrayptr = arrayOUTptr;
        array = *arrayOUTptr;
    }

        (*arrayptr).print();
}






/*
 This function would prompt the user to enter the number of generations allowed,
 and store it as a reference variable.
 
 pre : The array has been set
 post: Get the number of generations allowed
 */
void NUMevolve(int &NUMlife)
{
    cout << "Please enter the number of generations: ";
    cin  >> NUMlife;
}







/*
 This function would show the statistic of the living cells in the array.
 It includes the total number of living cells, number of living cells in a specific
 row, and the number of living cells in a specific column.
 
 pre : The array has been set and there's a bool value in each of the element
 post: Show the number of living cells in the respective area
 */
void stat(boolMatrix array)
{
        cout << "Total alive in row 10 = " << array.rowCount(10) << endl;
        cout << "Total alive in col 10 = " << array.colCount(10) << endl;
        cout << "Total alive = " << array.totalCount();
}






//Please enter the number of generations: 8
//01234567890123456789
//0
//1         **     *
//2         * *   ** *
//3       **        *
//4    **** * *   **
//5    **  * ** ** *
//6   *      ***
//7    **  *  * *
//8     ***   * *
//9 **        *  *
//10* **        *   * **
//11* ** ** **  * * *
//12*   *   *** *       *
//13* *        ***  * *
//14 *      ***  **   *
//15        *     *      *
//16     * *      *  ** *
//17      *         *
//18
//19
//20
//Total alive in row 10 = 7
//Total alive in col 10 = 5
//Total alive = 94






//Please enter the number of generations: 5
//01234567890123456789
//0
//1         *        *
//2       *   * ***  *
//3       *   **** *
//4      *  * *    **
//5    *  *   *****  *
//6 ** *     *    *** *
//7    * ***       *  *
//8               ****
//9 *         ******
//10* *          *
//11   *  *      **   *
//12**    ****       ***
//13  *         *** ** *
//14      *  *   *   ***
//15 **   ***      ** **
//16      *         * **
//17
//18
//19
//Total alive in row 10 = 3
//Total alive in col 10 = 1
//Total alive = 95
