#include "matrix_search.h"

const string STUDENT_NAME = "Evan Moak";
const string STUDENT_ID = "12422230";
const int NO_WORD_FLAG = -1;
const string WORD_SIZE_ERROR = "Input Word Too Large for Matrix";

void get_identity(string my_id[])
{
  my_id[0] = STUDENT_NAME;
  my_id[1] = STUDENT_ID;
}

char ** build_matrix(int rows, int cols)
{
  char **emptyGrid = new char *[rows];
  
  for(int i = 0; i < rows; i++)
  {
    emptyGrid[i] = new char[cols];
  }
  
  return emptyGrid;
}

void fill_matrix(int rows, int cols, char **matrix)
{
  for(int i = 0; i < rows; i++)
  {
   for(int j = 0; j < cols; j++)
   {
	cin >> matrix[i][j];
   }	   
    
  }
 
  return; 
}

void print_matrix(int rows, int cols, char **matrix)
{
  for(int i = 0; i < rows; i++)
  {
   for(int j = 0; j < cols; j++)
   {
	cout << matrix[i][j] << " ";
   }
   
	cout << endl;
  }
  
  return;
}

bool letter_search(int const & rPos, int const & cPos, int const &nRows, int const &nCols, string word, char **matrix, bool wFound, int *endPos)
{
  int wPos = 1;                    //This function begins searching from the second letter of the word.
  int wSize = word.length();
  int rINC = 1;                    //Row and Column Increments for continued searching along a straight line
  int cINC = 1;                    //Starting at 1 position offset from current matrix position.
	 
		
  wFound = false;                   //Ensures that word has not been found. 
	
  //Search N 
  if(rPos != 0 && matrix[rPos-rINC][cPos] == word[wPos]){
   
    while(matrix[rPos-rINC][cPos] == word[wPos] && !wFound)
    {
	  if(wPos == wSize-1){
        wFound = true;	
	    endPos[0] = rPos - rINC;
		endPos[1] = cPos;
      }
          
	  if(!wFound){
	    rINC++;
		wPos++;	
      }			
    }
		
    //If word isn't found then reset increments for next statement. 
	wPos = rINC = cINC = 1;
  }
	   
  //Search NW
  if(rPos != 0 && cPos != 0 && matrix[rPos-rINC][cPos-cINC] == word[wPos] && !wFound){	  
	while(matrix[rPos-rINC][cPos-cINC] == word[wPos] && !wFound)
    {		   
	  if(wPos == wSize-1){
        wFound = true;	
		endPos[0] = rPos - rINC;
	    endPos[1] = cPos - cINC;
      }	

      if(!wFound){
		rINC++;
	    cINC++;
		wPos++;	
      }		   
	}
		 
	wPos = rINC =  cINC = 1;	    
  }
	    
  //Search W
  if(cPos != 0 && matrix[rPos][cPos-cINC] == word[wPos] && !wFound){
	while(matrix[rPos][cPos-cINC] == word[wPos] && !wFound)
    {
	  if(wPos == wSize-1){
        wFound = true;	
	    endPos[0] = rPos;
	    endPos[1] = cPos - cINC;
      }		   
		   
	  if(!wFound){
		cINC++;
		wPos++;	
      }
	}
		 
	wPos = rINC = cINC = 1;  
  }
	
  //Search SW 
  if(rPos != (nRows-1) && cPos != 0 && matrix[rPos+rINC][cPos-cINC] == word[wPos] && !wFound){
	while(matrix[rPos+rINC][cPos-cINC] == word[wPos] && !wFound)
	{
	  if(wPos == wSize-1){
        wFound = true;	
		endPos[0] = rPos + rINC;
		endPos[1] = cPos - cINC;
      }

      if(!wFound){
		rINC++;
	    cINC++;
		wPos++;	
      }		   
    }
		 
	wPos = rINC =  cINC = 1;	 	   
  }
	   
  //Search S 
  if(rPos != (nRows-1) && matrix[rPos+rINC][cPos] == word[wPos] && !wFound){
	while(matrix[rPos+rINC][cPos] == word[wPos] && !wFound)
	{
	  if(wPos == wSize-1){
        wFound = true;	
	    endPos[0] = rPos + rINC;
	    endPos[1] = cPos;
      }

      if(!wFound){
	    rINC++;
	    wPos++;	
      }		   
	}
		 
    wPos = rINC =  cINC = 1;	  
  }
	   
  //Search SE
  if(rPos != (nRows -1) && cPos != (nCols - 1) && matrix[rPos+rINC][cPos+cINC] == word[wPos] && !wFound){
	while(matrix[rPos+rINC][cPos+cINC] == word[wPos] && !wFound)
    {
	  if(wPos == wSize-1){
        wFound = true;	
	    endPos[0] = rPos + rINC;
	    endPos[1] = cPos + cINC;
      }			   
		   
		if(!wFound){
		   rINC++;
		   cINC++;
		   wPos++;	
        }
	}
		 
	wPos = rINC =  cINC = 1;	 
  }
	     
  //Search E 
  if(cPos != (nCols-1) && matrix[rPos][cPos+cINC] == word[wPos] && !wFound){
	while(matrix[rPos][cPos+cINC] == word[wPos] && !wFound)
	{
	  if(wPos == wSize-1){
        wFound = true;	
		endPos[0] = rPos;
	    endPos[1] = cPos + cINC;
      }

      if(!wFound){
	    cINC++;
		wPos++;	
      }		   
    }
		 
	wPos = rINC =  cINC = 1;	
  } 
     	  
  //Search NE 
  if(rPos != 0 && cPos != (nCols-1) && matrix[rPos-rINC][cPos+cINC] == word[wPos] && !wFound){
	while(matrix[rPos-rINC][cPos+cINC] == word[wPos] && !wFound)
	{
	  if(wPos == wSize-1){
        wFound = true;	
		endPos[0] = rPos - rINC;
		endPos[1] = cPos + cINC;
      }

      if(!wFound){
		rINC++;
	    cINC++;
	 	wPos++;	
      }		   
    }
		 
	wPos = rINC =  cINC = 1;	  
  }
	  
  return wFound;	
	
}

string flipWord(string str)
{
 int length = str.length();
 for (int i = 0; i < (length / 2); i++) 
 {
    char temp = str[i];                 
	str[i] = str[(length - 1) - i];
    str[(length - 1) - i] = temp;
 }

  return str;
}

void matrix_search(int sol[], string word, int rows, int cols, char **matrix)
{
  int wordSize = word.length();
  int wPos = 0;                  //Current letter in word being searched for, 0 = First letter
  int  i, j;                     //Indexes for searching matrix, i = Row, j = Col
  int endCoord[2] = {0,0};       //Array holding the coordinate of the end of the word.
  bool word_found = false;       //Flag to indicate if full word has been located
  
  sol[0] = sol[1] = sol[2] = sol[3] = -1;  //If word is never found then set the coordinates accordingly;
  
  //If word size is larger than the number or rows or columns then skip to the end of
  //function.
  try{
    if(wordSize > rows && wordSize > cols)
	  throw("WORD_SIZE_ERROR");
  
    //Nested loops parse the array for first or last letter
    //Inner If statements call functions to search for the rest of the word.
    i = 0;
    while(i < rows && !word_found)
    {  
      j = 0;
      while(j < cols && !word_found)
      {
      
        //Searches for word forwards. 		  
	    if(matrix[i][j] == word[wPos]){
	     word_found = letter_search(i, j, rows, cols, word, matrix, word_found, endCoord); 
	    
		  //If word is found then update the position coordinates. 
		  if(word_found){
		    sol[0] = i;
            sol[1] = j;
            sol[2] = endCoord[0];
            sol[3] = endCoord[1];
		  }		  
	    }  
      	 
	    //Searches for word backwards
	    else if(matrix[i][j] == word[wordSize-1] && !word_found){
		
		  //Reverse word to be sent to function.
	      word_found = letter_search(i, j, rows, cols, flipWord(word), matrix, word_found, endCoord); 
		  if(word_found){
		    sol[0] = endCoord[0];
            sol[1] = endCoord[1];
		    sol[2] = i;
		    sol[3] = j;
		  }
	    }
	  
	    j++;
	  }	
	 
    i++;	
    }
  }
  
  catch(char const*){  
    return;
  }
}


void delete_matrix(int rows, char **matrix)
{
  for(int i = 0; i < rows; i++)
  {
    delete[] matrix[i];
  }
  
  delete[] matrix;
  
  return;
}
