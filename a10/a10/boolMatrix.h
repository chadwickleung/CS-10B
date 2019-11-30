//
//  boolMatrix.h
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
 
 This is the file boolMatrix.h
 The boolMatrix class can be used to create and store a two-dimensionl array, which
 has dimensions of rows = 20 and columns = 20.
 The number of true values in a row, column or total can be found by using this
 class.
 The following functions are available:
 
 boolMatrix();
 post: The calling object has been created and initialized as an array of 0 value
 
 static const int NUM_ROWS = 20;
 post: The calling object has been created and initialized so that the number of
 rows is 20
 
 static const int NUM_COLS = 20;
 post: The calling object has been created and initialized so that the number of
 columns is 20
 
 void set(int, int, bool);
 pre : The value of row and column and the value being set are known
 post: Set the required element as the value being set
 
 bool get(int, int) const;
 pre : A value was set in the respective element (array[row][col])
 post: Returns the bool value in that element of the array

 void print() const;
 post: The calling object has been printed to the console window as a
 two-dimensional array, with the heading representing the number of columns,
 and a side bar representing the number of rows on the right. The true values are
 represented by * and false values are represented by space
 
 int totalCount();
 pre : The array's element has been set and each has a value
 post: Return the total number of true values in the calling object array
 
 int rowCount(int row) const;
 pre : The array has been set and each element has a bool value
 post: Return the number of true values in the required row
 
 int colCount(int col) const;
 pre : The array has been set and each element has a bool value
 post: Return the number of true values in the required column
 
 int neighborCount(int, int) const;
 pre : The array has been set and each element has a bool value
 post: Return the number of neighboring true values that the calling object element
 has. Most of the elements would have 8 neighbors, while the corner elements have
 3 and the sideline elements have 5
 
 */

#ifndef BOOLMATRIX_H
#define BOOLMATRIX_H

class boolMatrix
{
public:
    static const int NUM_ROWS = 20;
    static const int NUM_COLS = 20;
    
    
    boolMatrix();
    
    void set(int, int, bool);
    bool get(int, int) const;
    void print() const;
    
    int totalCount();
    int rowCount(int row) const;
    int colCount(int col) const;
    int neighborCount(int, int) const;
    
private:
    bool array[NUM_ROWS][NUM_COLS];
};



#endif
