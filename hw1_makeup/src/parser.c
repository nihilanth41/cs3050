#include "statistics.h"


int parser(FILE* inputFile, int** numberSequence){ //we pass in the double pointer to have the option to change the value


	int* temporaryPointer = NULL; //used in case realloc fails
	int counterNum = 0; //counter that will keep track of the number of elements and the position we are on
	int i = 0; 
	int bufferCountNum = 1; //keeps track of the number of times we have realloc'ed for an exact size
	int bufferCountChar = 1; //keeps track of the number of times we have realloc'ed for an exact size
	int valid = 0; //a flag to throw out bad inputs
	int characterPosition = 0; //keeps track of current position when reading character by character
	char* currentInteger = malloc(sizeof(char) * BUFFER); //an array that will be used to convert to integer
	char* tempCharacterPointer = NULL; //used in case realloc fails
	char charByChar; //holds the character as we move character by character
	
	do {
		charByChar = fgetc(inputFile); //gets the next character
		if(charByChar == ' ' || charByChar == '\t' || charByChar == '\n' || charByChar == EOF){
			if(characterPosition != 0) {
				currentInteger[characterPosition] = '\0'; //end the current string and begin to change to an int
				characterPosition = 0;
				if(counterNum >= (BUFFER * bufferCountNum)){ //if we need more memory
					bufferCountNum++;				
					temporaryPointer = realloc((*numberSequence), (bufferCountNum * BUFFER) * sizeof(int));
					if(temporaryPointer != NULL){ //if the realloc doesn't fail
						(*numberSequence) = temporaryPointer;
					} else {
						free((*numberSequence));
						exit(-1);
					
					} 
				}
			
				valid = 1; //default valid is 1 (innocent until proven guilty)
				for(i=0;i < strlen(currentInteger); i++){
					
					if(i == 0 && currentInteger[i] == '-'){
						//do nothing, string is still valid
					} else if(!isdigit(currentInteger[i])){
						valid = 0; //string is not valid
						exit(PARSING_ERROR_INVALID_CHARACTER_ENCOUNTERED);
					} 
				}

				if(valid){ 
					(*numberSequence)[counterNum] = (int) strtol(currentInteger, NULL, 10); //add the int to the array
					counterNum++; //add a position
				}	
			}	

		} else {
			if(characterPosition >= (BUFFER * bufferCountChar)){ //if we need more memory
				bufferCountChar++;
				tempCharacterPointer = realloc(currentInteger, (bufferCountChar * BUFFER) * sizeof(char));
				if(tempCharacterPointer != NULL){ //if the realloc doesn't fail
					currentInteger = tempCharacterPointer;
				} else {
					free(currentInteger);
					exit(-1);
				}
			}

			currentInteger[characterPosition] = charByChar; //add the character to the array
			characterPosition++; //increment the current position

		}
	} while(charByChar != EOF);

	free(currentInteger); //we are done with this
	if(fclose(inputFile) != 0) exit(FILE_FAILED_TO_CLOSE); //we are also done with this

	if(counterNum == 0){
		exit(PARSING_ERROR_EMPTY_FILE);
	}

	return (counterNum);
}