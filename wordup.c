//Diego Garcia
//4-29-2025
//Project 10

#include <stdio.h>
#define word_File "mystery.txt"

char fileInfo(char mystery[12][6]){
	FILE *fp;
	fp = fopen(word_File, "r");
	
	fscanf(fp, "%s", mystery[0]);

	fclose(fp);
return mystery[0][6];
}

char winner(char mystery[12][6], char answer[6]){
	for(int a = 0; a < 5; a++){
		answer[a] = mystery[0][a];
		answer[a] = answer[a] - 32;
	}
return answer[6];
}

char letterCheck(char guess[50]){
	char failed;
	for(int l = 0; l < 5; l++){
		if(guess[l] >= 'a' && guess[l] <= 'z'){
			failed = 'N';
		}
		else if(guess[l] >= 'A' && guess[l] <= 'Z'){
			failed = 'N';
			guess[l] = guess[l] + 32;
		}
		else{
			failed = 'Y';
		}
	}
	
	char fail = 'Y';
	if(guess[4] >= 'a' && guess[4] <= 'z'){
		fail = 'N';
	}
	if(guess[5] >= 'a' && guess[5] <= 'z'){
		fail = 'Y';
	}
	
	char failure;
	if(fail == 'Y' && failed != 'Y'){
		failure = 'S';
	}
	else if(fail != 'Y' && failed == 'Y'){
		failure = 'C';
	}
	else if(fail == 'Y' && failed == 'Y'){
		failure = 'B';
	}
	else{
		failure = 'G';
	}
	
return failure;
}

char guessCheck(char guess[50]){
	while(letterCheck(guess) == 'S' || letterCheck(guess) == 'C' || letterCheck(guess) == 'B'){
		if(letterCheck(guess) == 'S' || letterCheck(guess) == 'B'){
			printf("Your guess must be 5 letters long. ");
		}
		if(letterCheck(guess) == 'C' || letterCheck(guess) == 'B'){
			printf("Your guess must contain only letters. ");
		}
		printf("\nPlease try again: ");
		scanf("%s", guess);
	}
return guess[50];
}

char caps(char mystery[12][6], char guess[50], int trys){
	switch(trys){
		case 1: break;
		case 2: trys = trys + 1;
			break;
		case 3: trys = trys + 2;
			break;
		case 4: trys = trys + 3;
			break;
		case 5: trys = trys + 4;
			break;
		default: trys = trys + 5;
			 break;
		}
		
	for(int i = 0; i < 5; i++){
		if(mystery[0][i] == guess[i]){
			mystery[trys][i] = guess[i];
			mystery[trys][i] = mystery[trys][i] - 32;
		}
		else{
			mystery[trys][i] = guess[i];
		}
	}
return mystery[12][6];
}

char arrows(char mystery[12][6], char answer[6], int trys){
	switch(trys){
		case 1: break;
		case 2: trys = trys + 1;
			break;
		case 3: trys = trys + 2;
			break;
		case 4: trys = trys + 3;
			break;
		case 5: trys = trys + 4;
			break;
		default: trys = trys + 5;
			 break;
		}
		
	int trys2;
	trys2 = trys;
	trys2++;
	for(int clear = 0; clear < 5; clear++){
		mystery[trys2][clear] = ' ';
	}

	for(int j = 0; j < 5; j++){
		for(int k = 0; k < 5; k++){
			if(mystery[0][k] == mystery[trys][j]){
					mystery[trys2][j] = '^';	
				}
			}
			
		if(mystery[trys2][j] == '\0'){
			mystery[trys2][j] = ' ';
		}
	}
return mystery[12][6];
}

void endScreen(int trys, int status){
	if(status == 5){
		printf("        You won in %d guess", trys);
		if(trys == 1){
			printf("!\n");
		}
		else{
			printf("es!\n");
		}
		
		switch(trys){
			case 1: printf("	      GOATED 0o0\n");
				break;
			case 2: printf("	    Fantastic XD\n");
				break;
			case 3: printf("	      Amazing ;D\n");
				break;
			case 4: printf("	     Good Job :D\n");
				break;
			case 5: printf("	     Nice One :)\n");
				break;
			default: printf("	        Clutch :O\n");
				break;
		}
	}
	else{
		printf("You lost, better luck next time :(\n");
	}
}	



int main(){
	char mystery2D[12][6];
	char answer[6];
	char guess[50];
	int trys = 0, status;
	char finalGuess;
	
	fileInfo(mystery2D);
	winner(mystery2D, answer);
	
	do{
		trys++;
		
		if(trys == 6){
			printf("FINAL GUESS: ");
			finalGuess = 'Y';
		}
		else{
			printf("GUESS %d! Enter your guess: ", trys);
		}
		scanf("%s", guess);
		guessCheck(guess);
		
		printf("=================================\n");
		
		caps(mystery2D, guess, trys);
		arrows(mystery2D, answer, trys);
		
		int trysTimes, trysAns;
		trysTimes = trys * 2;
		trysAns = trysTimes - 1;
		status = 0;
		
		for(int c = 0; c < 5; c++){
			if(mystery2D[trysAns][c] == answer[c]){
				status++;
			}
		}
		
		if(status == 5){
			printf("                ");
			printf("%s\n", mystery2D[trysAns]);
			finalGuess = 'Y';
		}
		else{
			for(int t = 1; t <= trysTimes; t += 2){
				int t2 = t;
				t2++;
				printf("%s\n%s\n", mystery2D[t], mystery2D[t2]);
			}
		} 
	}while(finalGuess != 'Y');
	
	endScreen(trys, status);

								return 0;
}
