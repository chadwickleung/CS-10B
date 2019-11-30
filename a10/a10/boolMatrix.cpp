//
//  boolMatrix.cpp
//  a10
//
//  Created by Chadwick Leung on 4/8/19.
//  Copyright © 2019 Chadwick Leung. All rights reserved.
//

/*
 Class invariants:
 The two dimensional array would have 20 rows and 20 columns by default.
 The set function would set the required bool value to the respective element as
 indicated in the parameter.
 The get function would return the bool value of the respective element in the
 two dimensional array.
 After setting the array, this class can return the total number of true values in
 the array, the true values in a specific row or column, and can return the number
 of true values in a specific element's neighboring cells
 */





#include <iostream>
#include "boolMatrix.h"
#include <cassert>
#include <iomanip>

using namespace std;


boolMatrix::boolMatrix()
{
    for (int row=0; row<NUM_ROWS; row++)
    {
        for (int col=0; col<NUM_COLS; col++)
        {
            array[row][col] = false;
        }
    }
}






bool boolMatrix::get(int INrow, int INcol) const
{
    assert(INrow >= 0 && INrow < NUM_ROWS);
    assert(INcol >= 0 && INcol < NUM_COLS);
    
    bool value;
    
    value = array[INrow][INcol];
    
    return value;
  
}







void boolMatrix::set(int INrow, int INcol, bool decision) 
{
    assert(INrow >= 0 && INrow < NUM_ROWS && INcol >= 0 && INcol < NUM_COLS);
    
    array[INrow][INcol] = decision;
}






int boolMatrix::rowCount(int INrow) const
{
    assert(INrow >= 0 && INrow < NUM_ROWS);
    
    int rowSum = 0;
    
    for (int col=0; col < NUM_COLS; col++)
    {
        rowSum += array[INrow][col];
    }
    
    return rowSum;
}






int boolMatrix::colCount(int INcol) const
{
    assert(INcol >= 0 && INcol < NUM_COLS);
    
    int colSum = 0;
    
    for (int row = 0; row < NUM_ROWS; row++)
    {
        colSum += array[row][INcol];
    }
    
    return colSum;
}






int boolMatrix::totalCount() 
{
    int totalSum = 0;
    
    for (int row = 0; row < NUM_ROWS; row++)
    {
        totalSum += rowCount(row);
    }
    
    return totalSum;
}






int boolMatrix::neighborCount(int INrow, int INcol) const
{
    assert(INrow >= 0 && INrow < NUM_ROWS);
    assert(INcol >= 0 && INcol < NUM_COLS);
    
    int neighborSum = 0;
    
    if (INrow == 0 && INcol == 0)
    {
        neighborSum = get(INrow, INcol+1) + get(INrow+1, INcol)
                     + get(INrow+1, INcol+1);
    }
    
    else if (INrow == NUM_ROWS-1 && INcol == NUM_COLS-1)
    {
        neighborSum = get(INrow, INcol-1) + get(INrow-1, INcol)
                     + get(INrow-1, INcol-1);
    }
    
    else if (INrow == 0 && INcol == NUM_COLS-1)
    {
        neighborSum = get(INrow, INcol-1) + get(INrow+1, INcol)
                     + get(INrow+1, INcol-1);
    }
    
    else if (INrow == NUM_ROWS-1 && INcol == 0)
    {
        neighborSum = get(INrow-1, INcol) + get(INrow, INcol+1)
                     + get(INrow-1, INcol+1);
    }
    
    else if (INrow == 0 && INcol != 0 && INcol != NUM_COLS-1)
    {
        neighborSum = get(INrow, INcol-1) + get(INrow+1, INcol-1)
        + get(INrow+1, INcol) + get(INrow+1, INcol+1) + get(INrow, INcol+1);
    }
    
    else if (INcol == 0 && INrow != 0 && INrow != NUM_ROWS-1)
    {
        neighborSum = get(INrow-1, INcol) + get(INrow-1, INcol+1)
        + get(INrow, INcol+1) + get(INrow+1, INcol+1) + get(INrow+1, INcol);
    }
    
    else if (INrow == NUM_ROWS-1 && INcol != 0 && INcol != NUM_COLS-1)
    {
        neighborSum = get(INrow, INcol-1) + get(INrow-1, INcol-1)
        + get(INrow-1, INcol) + get(INrow-1, INcol+1) + get(INrow, INcol+1);
    }
    
    else if (INcol == NUM_COLS-1 && INrow != 0 && INrow != NUM_COLS-1)
    {
        neighborSum = get(INrow-1, INcol) + get(INrow-1, INcol-1)
        + get(INrow, INcol-1) + get(INrow+1, INcol-1) + get(INrow+1, INcol);
    }
    
    else
    {
        neighborSum = get(INrow-1, INcol-1) + get(INrow-1, INcol)
        + get(INrow-1, INcol+1) + get(INrow, INcol-1) + get(INrow, INcol+1)
        + get(INrow+1, INcol-1) + get(INrow+1, INcol) + get(INrow+1, INcol+1);
    }
    return neighborSum;
}






void boolMatrix::print() const
{
    cout << "  01234567890123456789" << endl;
    for (int row = 0; row < NUM_ROWS; row++)
    {
        cout << setw(2) << row;
        for (int col = 0; col < NUM_COLS; col++)
        {
            if (get(row, col) == true)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
