#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include "Timer.h"
#include "Customers\Customer.h"
#include"Operations.h"

/*
int main()
{
	CUSTOMER *list = NULL;
	char names[50];
	srand(time(NULL));
	int len = 49;

	for (int i = 0; i < 7; i++)
	{
		getRandomName(names, &len);
		newCustomer(&list, i+1, rand() % 2000, names);
	}
	printList(list);
	
	changeBalance(&list, 4, 200, putMoney);

	printList(list);

	changeBalance(&list, 4, 200, receiveMoney);

	printList(list);

	changeBalance(&list, 4, 10000, receiveMoney);

	printList(list);

	transferMoney(&list, 2, 3, 100);
	printList(list);


}
*/


int main() {
	//Define variables
	int simulateDuration;

	time_t startSimulateTime;
	time_t currentSimulateTime;
	
	time_t *startSimulateTime_p = &startSimulateTime;
	time_t *currentSimulateTime_p = &currentSimulateTime;

	char name[20];
	char surname[20];
	
	//Welcome
	printf("Please, enter the duration of the simulation: ");
	scanf("%d", &simulateDuration);
	setCurentTime(startSimulateTime_p);
	
	//Checking timecode access
	if (startSimulateTime == -1) {
		printf("\nSimulation is impossible. Timecode is unavailable.\nProgram will terminate in 5 seconds.");
		Sleep(5000);
	}	
	


	/*

	//String to number
	int top;
	char netop[7] = "000003";
	top = atoi(netop);
	printf("%d - top\n", top);
	char estop[7] = "650540";
	top = atoi(estop);
	printf("%d - top\n", top);

	*/

	//Random names
	int len;
	int *len_p = &len;
	for (int j = 0; j < 10; j++) {
		getRandomName(name, len_p);
		for (int i = 0; i < len - 1; i++) {
			printf("%c", name[i]);
		}
		printf(" ");
		getRandomSurname(surname, len_p);
		puts(surname);
		Sleep(1000);
	}

	//system("cls");

	printf("\n");

	

}