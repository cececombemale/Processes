#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "csapp.h"
/*
Cecilia Combemale

This program displays the content of the home directory.
*/

int main(int argc, char **argv, char **envp){
	
	pid_t child; 
	char *args = "/bin/ls"; //executable binary for ls
	char *home = getenv("HOME"); //gets the environment of the home
	//directory
	if (home == NULL ) //if a system does not have a home directory
		//send a message and exit the program 
		{
			printf("%s\n", "Sorry, no HOME was found.");
			exit(1);
		}

	char *commands [4]; // the commands that will execute and replace the
	//current running program
	commands[0] = "ls"; //commands to list content of home directory
	commands[1] = "-l"; //commands to list content of home directory
	commands[2] = home;
	commands[3] = NULL; //must end in null
	child = Fork(); //create child process. 
	if (child == 0){
		Execve(args,commands,envp); //create new process image that
		//will print the contents of the home directory. 
	}
	Wait(&child); //give control back to the user. 
	
}