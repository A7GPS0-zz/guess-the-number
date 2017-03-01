/*
	author:	A7GPS0
	date:	28.02.2017
	
	[in]
	random start value to calculate the random number to guess
	range of numbers where your number can be. From 0 to "your Range"
	
	[out]
	number of tries you needed to guess the right number
	guess was to high/small/right
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int inpRndSeed 	     = 0; 	// random start value
	int inpRange 	     = 0; 	// between 0 -> "range" you have to guess
	int guessTheNumber   = 0; 	// the number to guess
	int userInput 	     = 0;	// input of numbers the user
	int triesUserGuessed = 0; 	// tries the user tried to guess the correct number
	
	printf("Give a random number: "); // give a starting value to calculate the random number
	scanf("%d",&inpRndSeed);
	
	printf("Guess from 0 to: "); // give the last possible number to guess
	scanf("%d",&inpRange);
	
	srand(inpRndSeed); // generate a random number based on your random number 
	
	/*
		calculate the number you have to guess. 
		The number is between 0 and your input.
	*/
	guessTheNumber = (rand() % inpRange+1);
	
	do // guess until your guess is right and counts your tries
	{
		printf("\n\nYour guess: ");
		scanf("%d",&userInput);
		
		if(guessTheNumber < userInput)
			printf("Your guess was to high!");
		else if(guessTheNumber > userInput)
			printf("Your guess was to small!");
		else
		{
			printf("\nYour guess was right!\nYou needed %d tries",++triesUserGuessed);
			// increment the "tries" befor the output. The last try will count too.
			return 0;
		}
		
		triesUserGuessed += 1;
		
	}while(userInput != guessTheNumber);
								
	return 0;
}
