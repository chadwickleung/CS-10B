/*
 
 Chadwick Leung
 CS 10B
 3/18/19
 Dave Harden
 Assignment 7_1
 
 This program is a rewrite of the most recent high scores program so that each
 name/score pair is stored in a struct named highscore. This program would ask
 the user to enter the number of scores, create a struct array, ask the user to
 enter the indicated numbers of names and scores, and then print the names and
 scores sorted by the scores in decending order

*/






#include <iostream>
#include <string>


using namespace std;

struct highscore{
                 int score;
                 char name[24];
                }scores;

void initializeData(highscore scores[], int size);
void sortData(highscore scores[], int size);
void displayData(const highscore scores[], int size);







int main()
{
    int size;
    
    cout << "How many scores will you enter?: ";
    
    cin  >> size;
    
    highscore* scoresptr;
    scoresptr = new highscore[size];
    
    initializeData(scoresptr, size);
    sortData(scoresptr, size);
    displayData(scoresptr, size);
                  
    return 0;
}






/*
 This function initialize the data by asking the user to enter the respective
 names and scores. By using a for loop, the user would enter one name and the
 person's score each time in the struct array.
 The data would finish initializing after it reached the size that the user
 input earlier.
 
 pre: the size was input
 post: the data would be stored in the pointer
 */
void initializeData(highscore scores[], int size)
{
    for (int count=0; count<size; count++)
    {
        cout << "Enter the name for score #" << (count+1) <<": ";
        
        cin.ignore();
        
        cin.getline(scores[count].name, 24);
        
        cout << "Enter the score for score #" << (count+1) <<": ";
        
        cin  >> scores[count].score;
    }
    
}






/*
 This function would sort the data (both the names and the scores) in
 descending order of the scores. It sorts the data by sorting the struct,
 so that it only requires a one-time sorting. An extra pointer was being used
 while sorting, it has the same data type as the struct highscore
 
 pre: the data is initialized and stored in the pointer
 post: the data would be sorted in descending order based on the scores
 */
void sortData(highscore scores[], int size)
{

    for (int count=0; count<size; count++)
    {
        for (int seccount=1; seccount<(size-count); seccount++)
        {
            if (scores[count+seccount].score>scores[count].score)
            {
                highscore swapptr;
                swapptr = scores[count];
                
                scores[count] = scores[count+seccount];
                scores[count+seccount] = swapptr;
                
            }
        }
    }
    
}





/*
 This function would display the scores in descending order after passing
 through the sort function. This function displays the name and the respective
 score of the person.
 
 pre: the data is sorted in the sort function above
 post: the data is being displayed in descending order of the scores
 */
void displayData(const highscore scores[], int size)
{
    cout << "Top Scorers:" <<endl;
    
    for (int count=0; count<size; count++)
    {
        cout << scores[count].name << ": " << scores[count].score <<endl;
    }
}






//How many scores will you enter?: Program ended with exit code: 4
//Enter the name for score #1: Suzy
//Enter the score for score #1: 600
//Enter the name for score #2: Kim
//Enter the score for score #2: 9900
//Enter the name for score #3: Armando
//Enter the score for score #3: 8000
//Enter the name for score #4: Tim
//Enter the score for score #4: 514
//Top Scorers:
//Kim: 9900
//Armando: 8000
//Suzy: 600
//Tim: 514
