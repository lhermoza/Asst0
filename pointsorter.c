#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
												
int main (int argc, char ** argv)
{

  //Checks to make sure the user only inputed 1 argument.
  if(argc != 2)
  {
    printf("INPUT ERROR!\n");
    return 0;
  }

  char currentChar;
  int i,j;
  int charIndex = 0;
  int bufferIndex = 0;
  int sepArrayIndex = 0;
  int wordCont = 0;

  //Creates a character array allocated with the size of the input string.
  char* strBuffer = malloc(strlen(argv[1]));
  //Clears the memory allocated above so theres no  random memory
  memset(strBuffer, '\0', strlen(argv[1]));
  //Array of seperated strings from the input
  char** sepArray = (malloc(strlen(argv[1])*sizeof(char*)));
  //Clearing all parts of the 2d array with memset
  for(i = 0; i < strlen(argv[1]); i++)
  {
    sepArray[i] = malloc(strlen(argv[1]));
    memset(sepArray[i], '\0', strlen(argv[1]));
  }

  //Sets current char to be the first char in the input string
  currentChar = argv[1][charIndex];
  //Runs to the end of the input string
  while(currentChar!= '\0')
  {
    //Runs between A and Z and a and z (will kick out when you find a a non alphabetical character)
    while(((currentChar <= 'Z' && currentChar >= 'A' ) || (currentChar >= 'a' && currentChar <= 'z')))
    {
      strBuffer[bufferIndex] = currentChar; //Writes the current char to a buffer for later user
      bufferIndex++;
      charIndex++;
      currentChar = argv[1][charIndex];//Assigns currChar to the next char in the input string
    }
    //Copies the string in the buffer into the array of strings
      if(*strBuffer!= '\0') //Checks to make sure strBuffer is not empty so there are no errors with strcpy
      {
        strncpy(sepArray[sepArrayIndex], strBuffer, strlen(strBuffer));
        wordCont++;
        sepArrayIndex++;
      }
      //Clear strBuffer
      memset(strBuffer, '\0', strlen(argv[1]));
      //Skips the non alphabetical letter
      if(currentChar != '\0')
      {
        charIndex++;
      }
      bufferIndex = 0;//reset buffer index
      currentChar = argv[1][charIndex]; //assigns the next character to the character AFTER the delimiter
  }

  char* tempStr = malloc(strlen(argv[1]));//allocating memory for a string temporary string variable
  //sorting algorithm compares string j and j+1 and swaps them if j+1 is greater than j, moving strings alphabetical to the front of the list in descending order.
  for(i = 0; i < wordCont; i++)
    for(j = 0; j < wordCont-1;j++)
      {
        if(strcmp(sepArray[j], sepArray[j+1]) < 0)
        {
          strcpy(tempStr, sepArray[j+1]);
          strcpy(sepArray[j+1],sepArray[j]);
          strcpy(sepArray[j],tempStr);
        }
      }
	
//print final list.
 for(i =0; i<wordCont; i++)
  {
   	 //alphaSort(&sepArray[i]);
	 printf("%s \n",sepArray[i]);
  }

  return 0;
}
