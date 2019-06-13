#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include "Timer.h"
#include "Customers\Customer.h"
#include "Operations.h"

void setCurentTime(time_t *currentTime) {
	time(currentTime);
}
int getExistingID(CUSTOMER *phe)
{
	CUSTOMER *p = phe;
	int ID = rand() % getAmount(p) + 1;
	if (isVoidID(p, ID))
	{
		if (ID == 1) (ID)++;
		else (ID)--;
	}
	return ID;
}


void simulation(time_t *startSimulation, time_t *currentSimulateTime, int simulateDuration) {
	int day = 1, infoStringsNumber = 3, haveCustomer, isCustomerNew, operationNumber, customerNumber, transferRecipient;
	int dayDuration = 15, dailyPutMoney, dailyRecieveMoney;
	char infoString[50], clientName[20], clientSurname[20];

	int len;
	int *len_p = &len;

	srand(time(0));

	CUSTOMER *list = NULL;
	char fullname[50];
	fullname[0] = 0;
	
	char surname[20];
	surname[0] = 0;

	for (int i = 0; i < 5; i++)
	{
		len = 20;
		getRandomName(fullname, &len);
		len = 20;
		getRandomSurname(surname, &len);
		strcat(fullname, surname);
		fullname[strlen(fullname)] = 0;
		newCustomer(&list, i+1, rand() % 5000 + 1, fullname);
	}


	setCurentTime(currentSimulateTime);
	while (day <= simulateDuration) {
		//printCurrentDay(currentSimulateTime, day, startSimulation);		//If all clients are shown
		setCurentTime(currentSimulateTime);								//If all clients are shown
		dailyPutMoney = 0;
		dailyRecieveMoney = 0;
		setCurentTime(startSimulation);
		//printf("%d - start\n", *startSimulation);
		//printf("%d - start + daydur\n", *startSimulation + dayDuration);
		Sleep(1000);
		while (*currentSimulateTime <= *startSimulation + dayDuration) {

			setCurentTime(currentSimulateTime);							//If all clients are shown
			srand(time(0));
			haveCustomer = rand() % 2;
			//printf("%d", haveCustomer);		//CHECK
			if (haveCustomer == 1) {
				system("cls");
				printCurrentDay(currentSimulateTime, day, startSimulation);		//If only 1 client shown
				setCurentTime(currentSimulateTime);								//If only 1 client shown
				isCustomerNew = rand() % 100 + 1;
				operationNumber = rand() % 4 + 1;
				int customerID = 0;
				/*
				1 - putMoney
				2 - receiveMoney
				3 - transferMoney
				4 - contribution
				*/
				//printf("Check random\n");
				if (isCustomerNew < 6) {
					//Customer is NEW
					printf("!New customer!\n");
					len = 20;
					getRandomName(fullname, &len);
					len = 20;
					getRandomSurname(surname, &len);
					strcat(fullname, surname);
					fullname[strlen(fullname)] = 0;
					customerID = getFreeID(list);
					newCustomer(&list, customerID, rand() % 5000 + 1, fullname);
				}
				else
				{
					
					customerID = getExistingID(list);
				}
				//Customer isn't new
				printf("Current customer: %i: ", customerID);
				printCustomerName(list, customerID);
				printf("\n");
				int sum = rand() % 2000 + 1;
				//printf("%Operation: 3\n", operationNumber);	//CHECK
				switch (operationNumber) {
				case 1:
					printf("%Operation: Put money (1)\n");
					break;

				case 2:
					printf("%Operation: Recieve money (2)\n");
					break;
				case 3:
					printf("%Operation: Transfer to another client (3)\n");
					break;
				case 4:
					printf("%Operation: Made contribution (4)\n");
				}
				
				switch (operationNumber)
				{
				case 1: //putMoney
					if (changeBalance(&list, customerID, sum, putMoney)) { 
						printf("Customer %i just put %i on balance\n", customerID, sum); 
						dailyPutMoney += sum;
					}
					else printf("Customer try to put some money but operation is failed\n");
					break;
				case 2: //recieveMoney
					if (changeBalance(&list, customerID, sum, receiveMoney)) { 
						printf("Customer %i just recieved %i from balance\n", customerID, sum);
						dailyRecieveMoney += sum;
					}
					else printf("Customer try to recieve some money but operation is failed\n");
					break;
				case 3: //transferManey
					if (transferMoney(&list, customerID, getExistingID(list), sum)) printf("Customer %i just transfered %i on balance\n", customerID, sum);
					else printf("Customer try to transfer some money but operation is failed\n");
					break;
				case 4: // contrib
					contribution(&list, customerID, sum, (float)rand() / RAND_MAX * (5.00 - 1.00) + 1.00);
					printf("Customer made contribution\n");
					break;
				default:
					break;
				}
				//printList(list);
				//contribRise(&list);
			}
			Sleep(2000);
			
		}
		system("cls");
		printCurrentDay(currentSimulateTime, day, startSimulation);
		printList(list);
		contribRise(&list);
		printf("\n");
		printf("Money, has deposited in the Bank today: %d\n", dailyPutMoney);
		printf("Money, has withdrawn from the Bank today: %d\n", dailyRecieveMoney);
		printf("\n");
		Sleep(10000); //normal - 10000
		if (day == simulateDuration) {
			printf("So, this is the end of the Simulation.");
			Sleep(2500);
			return;
		}
		printf("New day is coming...");
		day++;
		setCurentTime(startSimulation);
		Sleep(2000);
		//system("cls");
	}
}

void printCurrentDay(time_t *currentSimulateTime, int day, time_t* startSimulation) {
	
	char date[24];
	char *curDate;
	char temp[10];

	setCurentTime(currentSimulateTime);
	*currentSimulateTime += 86400 * (day - 1);
	curDate = ctime(currentSimulateTime);
	
	for (int i = 0; i < 24; i++) {
		date[i] = curDate[i];
	}
	date[10] = ',';
	date[11] = ' ';
	for (int i = 12; i <= 15; i++) {
		date[i] = date[i + 8];
	}
	for (int i = 0; i < 16; i++) {
		printf("%c", date[i]);
	}

	printf("\n");
}