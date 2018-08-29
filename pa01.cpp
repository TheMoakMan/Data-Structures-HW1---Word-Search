#include "matrix_search.h"
#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::cerr;

/*~~~~GLOBAL CONSTANTS~~~~*/
const int NO_WORD_FLAG = -1;

//Reverses a string array passed into it.
string flipWord(string str);

/* 
Searches around a given letter in all directions in a straight line until the complete word is found or there are no more matching characters.
This letter should be the first letter of the target word.
  --rPos: The row index of the target letter to be searched around 
  --cPos: The column index of the target letter to be searched around
  --nRows: Number of rows in the matrix
  --nCols: Number of columns in the matrix
  --word: The target word to be searched for
  --**matrix: Pointer to the matrix (Must be initialized and of size [nRows][nCols])
  -- wFound: Flag to determine if the word has been found yet or not
  --*endPos: Pointer to an array of ints marking the coordinates of the last letter of the word.
*/
bool letter_search(int const & rPos, int const & cPos, int const &nRows, int const &nCols, string word, char **matrix, bool wFound, int *endPos);

int main()
{

  int numRows;                         //Number of Rows in the matrix
  int numCols;                         //Number of COlumns in the matrix
  int numCases;                        //Number of data sets and matrices to search through
  int wordLoc[4] = {0,0,0,0};          //Array representing the coordinates in the grid for the first and 
                                       //last letters of the target word
  string target;                       //Input word to be searched for in the matrix
  
  //Read in the number of cases.
  cin >> numCases;
  
  //Loop through for each case
  for(int i = 0; i < numCases; i++)
  {
 	try{ 
	  //Read in the size of the matrix
      cin >> numRows;
	  cin >> numCols;
	 
      //Create the Matrix
      char ** grid = build_matrix(numRows, numCols);
  
      //Fill the Matrix with data that is input.
      fill_matrix(numRows, numCols, grid);
	  
	  print_matrix(numRows, numCols, grid);
	  
      //Read in the word to be searched
   	  cin >> target;
	 
	  cout << "Searching for " << '"' << target << '"' << " in matrix 1 yields: " << endl;
	
	  //Searches to determine if the target word is in the matrix and where it would be located
      matrix_search(wordLoc, target, numRows, numCols, grid);
    
      //Output the results.
	  if(wordLoc[0] == NO_WORD_FLAG)
	    cout << "The pattern was not found." << endl;
	  else{	
        cout << "Start pos:(" << wordLoc[0] << ", " << wordLoc[1] << ") to End pos:(" 
	         << wordLoc[2] << ", " << wordLoc[3] << ")"; 
      }
	 
 
	  cout << endl << endl;
	
      //Delete the matrix. 
      delete_matrix(numRows, grid);
    }
	
	catch(std::bad_alloc){
	  cout << "Memory Allocation Failed" << endl;
	  cout << "The pattern was not found." << endl;
	}
	
  }	
  
  return 0;
}
