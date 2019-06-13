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
	char infoString[50];
	char *p_infoString = infoString;

	int finish = 0;
	
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
	setCurentTime(currentSimulateTime_p);
	while (*currentSimulateTime_p <= *startSimulateTime_p + 30) {
		setCurentTime(currentSimulateTime_p);
		printf("%d\n", currentSimulateTime);
		Sleep(2000);
	}
	*/

	printf("\n\n");
	printf("Simulation is going to start: ");
	Sleep(1000);
	printf("3... ");
	Sleep(1000);
	printf("2... ");
	Sleep(1000);
	printf("1...");
	Sleep(1000);

	//Start Simulation
	setCurentTime(startSimulateTime_p);
	simulation(startSimulateTime_p, currentSimulateTime_p, simulateDuration);

	
	/*printf("%d - start\n", startSimulateTime);
	setCurentTime(currentSimulateTime_p);
	printf("%d - current\n", currentSimulateTime);
	char *curDate;
	curDate = ctime(currentSimulateTime_p);
	char date[24];
	for (int i = 0; i < 24; i++) {
		date[i] = curDate[i];
	}
	printf("%d - start\n", startSimulateTime);
	setCurentTime(currentSimulateTime_p);
	printf("%d - current\n", currentSimulateTime);*/

	/*
	printf("Start PrintDay\n");
	printf("%d - start time\n", *startSimulateTime_p);
	char date[24];
	char *curDate;
	char temp[10];

	printf("%d - start time\n", *startSimulateTime_p);

	setCurentTime(currentSimulateTime_p);
	*currentSimulateTime_p += 86400 * 0;
	printf("\n%d - current in PrintDay\n", *currentSimulateTime_p);
	curDate = ctime(currentSimulateTime_p);
	puts(curDate);
	for (int i = 0; i < 24; i++) {
		date[i] = curDate[i];
	}

	printf("%d - start time\n", *startSimulateTime_p);

	date[10] = ',';
	date[11] = ' ';
	for (int i = 12; i <= 15; i++) {
		date[i] = date[i + 8];
	}

	printf("%d - start time\n", *startSimulateTime_p);

	for (int i = 0; i < 16; i++) {
		printf("%c", date[i]);
	}
	printf("\n");

	printf("%d - start time\n", *startSimulateTime_p);
	printf("End PrintDay");*/

	/*
	printf("%d - start\n", startSimulateTime);
	startSimulateTime += 30;
	printf("%d - start\n", startSimulateTime);*/


	
	system("cls");
	printf("Thanks for this unforgettable %d day(s) with our Bank!!\n", simulateDuration);
	printf("We hope, you enjoyed!\nHave a nice day! See you next time!\n");
	Sleep(4000);
	

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

	/*
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
	*/

	//system("cls");	
	

}