/*
 ============================================================================
 Name        : FSM_test.c
 Author      : Mostafa Besar
 Version     :
 Copyright   : Your copyright notice
 Description : Finite state machine for traffic light simulation
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NO_OF_STATES	3

//defining states
typedef enum {
	red_state,
	green_state,
	yello_state
}RGB_state;

//Implementing states

void red_on(void){
	printf("Red sign is now on\n green sign turned off!");
}

void green_on(void){
	printf("green sign is now on\n yellow sign turned off!");
}

void yellow_on(void){
	printf("yellow sign is now on\n red sign turned off!");
}


void (*fb[NO_OF_STATES])(void) = {red_on,yellow_on, green_on}; //array of function pointers

int main(void) {
	int state;
	const char *colors[]= {"red","yellow","green"};
	printf("Press (1) or (2) or (3)");
	printf("\n\n1- Red light");
	printf("\n2- Yellow light");
	printf("\n3- Green light\n");
	printf("\nEnter state: ");
	while(1){

	scanf("%d",&state);
	fb[state-1]();
	if(state == NO_OF_STATES)
		printf("\n\nnext you should turn on %s: ", colors[0]);

	else
		printf("\n\nnext you should turn on %s: ", colors[((++state)-1)]);
	}

	return EXIT_SUCCESS;
}




