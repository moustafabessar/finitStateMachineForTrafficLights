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
	yellow_state,
	green_state
}RGB_state;

RGB_state rgb;
//Implementing states

void red_on(){
	printf("Red sign is now on\n green sign turned off!");
	rgb = yellow_state;
}

void green_on(){
	printf("green sign is now on\n yellow sign turned off!");
	rgb = red_state;
}

void yellow_on(){
	printf("yellow sign is now on\n red sign turned off!");
	rgb = green_state;
}

void (*StartFSM[NO_OF_STATES])() = {red_on,yellow_on, green_on}; //array of function pointers

int main(void) {

	int state;
	const char *colors[]= {"red","yellow","green"};

	printf("Press (1) or (2) or (3)");
	printf("\n\n1- Red light");
	printf("\n2- Yellow light");
	printf("\n3- Green light\n");
	printf("\nEnter state: ");

	while(1){
	//Here i get input from the user to make a delay, the user shouldn't decide the next state. Code will tell him which state should choose
	scanf("%d",&state);
	
	StartFSM[state-1]();

	printf("\n\nnext you should turn on %s: ", colors[rgb]);
	}

	return EXIT_SUCCESS;
}
