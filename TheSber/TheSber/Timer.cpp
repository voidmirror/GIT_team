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
	if (checkID(p, ID))
	{
		if (ID == 1) (ID)++;
		else (ID)--;
	}
	return ID;
}


void simulation(time_t *startSimulation, time_t *currentSimulateTime, int simulateDuration) {
	int day = 1, infoStringsNumber = 3, haveCustomer, isCustomerNew, operationNumber, customerNumber, transferRecipient;
	int dayDuration = 30, dailyPutMoney, dailyRecieveMoney;
	char infoString[50], clientName[20], clientSurname[20];

	int len;
	int *len_p = &len;

	CUSTOMER *list = NULL;
	char fullname[50];
	fullname[0] = 0;
	
	char surname[20];
	surname[0] = 0;
	setCurentTime(currentSimulateTime);
	while (day <= simulateDuration) {
		printCurrentDay(currentSimulateTime, day);
		while (currentSimulateTime <= startSimulation + dayDuration) {

			dailyPutMoney = 0;
			dailyRecieveMoney = 0;
			srand(time(0));
			haveCustomer = rand() % 1;
			if (haveCustomer == 1) {
				isCustomerNew = rand() % 100 + 1;
				operationNumber = rand() % 4 + 1;
				int customerID = 0;
				/*
				1 - putMoney
				2 - receiveMoney
				3 - transferMoney
				4 - contribution
				*/
				
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

					//infoStringsNumber++;
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
					printf("Customer %i made contribution\n");
					break;
				default:
					break;
				}
				printList(list);
				contribRise(&list);
			}
			Sleep(2000);

		}
		day++;
		printf("\n");
		printf("Money, has deposited in the Bank today: %d\n", dailyPutMoney);
		printf("Money, has withdrawn from the Bank today: %d\n", dailyRecieveMoney);
		Sleep(3000);
		if (day <= simulateDuration) {
			printf("So, this is the end of the Simulation.");
			return;
		}
		printf("New day is coming...");
		Sleep(2000);
		system("cls");
	}
}

void printCurrentDay(time_t *currentSimulateTime, int day) {
	char date[24];
	char *curDate;
	char temp[10];

	setCurentTime(currentSimulateTime);
	*currentSimulateTime += 86400 * day;
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