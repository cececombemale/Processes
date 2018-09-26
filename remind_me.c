#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "csapp.h"

/*
Cecilia Combemale

This program prints a message to the console after a specified number
of seconds. This program uses the alarm and pause methods to do so. 
*/



static void catchSignal(int sig); //signal handler

int isNumber(char *maybe);

char *message; //global variable so it can be accessed inside the 
//signal handler

int main(int argc, char *argv[]){
	pid_t child; 
	if (argc < 3) // if there are less than three command line 
		//arguments then print an error message and exit
	{
		printf("%s\n", "Sorry, You did not set up the alarm correctly.");
		exit(1);
	}
	message = (char *)malloc(strlen(argv[2])+1);
	strcpy(message,argv[2]); //get the message, this is the case that the 
	//message only takes up one argument.
	
	int howLong; //to store how long the alarm will be set for
	if(isNumber(argv[1]) == 1){ //if the argument is a number (created my 
		//own function for this, comments are there as well)
		howLong = atoi(argv[1]); //set variable equal to the number
	} 
	else{ //if it is not a number
		strcpy(message,argv[1]); //the message must start in the 2nd argument
		//the message will then start there. 
		if(argc > 2){ //if the message spans over several command line
		//arguments
		int length;
		int i; 
		for (i = 2; i < argc; i++) //for the words beyond the first argument that
			//represents the message
		{
			 length = 1 + strlen(argv[i]);

			 message = realloc(message,length);
			 strcat(strcat(message," "), argv[i]); //append the message with the additional words

		}
	}
		howLong = 0; //set howlong to 0 so that the message is printed to the 
		//console immediately. 
	}
	

	
	if(howLong<0){ // if the alarm time is negative
		printf("%s\n", "Sorry, an alarm can't be set in the past.");
		exit(1);
	}


	

	if(argc > 3){ //if the message spans over several command line
		//arguments
		int length;
		int i; 
		for (i = 3; i < argc; i++) //for the words beyond the first argument that
			//represents the message
		{
			 length = 1 + strlen(argv[i]);

			 message = realloc(message,length);
			 strcat(strcat(message," "), argv[i]); //append the message with the additional words

		}
	}
	if(howLong==0){ //if the alarm time is 0
		printf("%s\n", message);
		exit(1);
	}
	child = Fork(); //create a child process 
	
	Signal(SIGALRM,catchSignal); //catch the signal
	

	if(child == 0){
		Alarm(howLong); //create alarm
		
		while(1){ //pause while the alarm is running
			Pause();
			
		}
	}
	printf("Process-id = %ld\n", (long)child); //print the process id

}
static void catchSignal(int sig){ //signal handling. 
	//uses the message we get in the main method
	printf("%s\n", message);
	free(message); //free the allocated space for the memory 
	//capital for wrapper class
}

int isNumber(char *maybe){ //checks to see if the string is a number
	int i; //for counter

	for(i = 0; i<strlen(maybe); i++){ //if the loop through the string
		if(!isdigit(maybe[i])){ //if any of the characters is not a digit return 0 (false)
			return 0;
		}
	}
	return 1; //if the string is a number then return 1(true)
}

