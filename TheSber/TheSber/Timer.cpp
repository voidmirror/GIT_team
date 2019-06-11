#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include "Timer.h"
#include "Customers\Customer.h"

void setCurentTime(time_t *currentTime) {
	time(currentTime);
}

void simulation(time_t *startSimulation, time_t *currentSimulateTime, int simulateDuration) {
	int day = 1, infoStringsNumber = 3, haveCustomer, isCustomerNew, operationNumber, customerNumber, transferRecipient;
	int dayDuration = 30;
	char infoString[50], clientName[20], clientSurname[20];

	int len, clientID, clientBalance, clientContrib;
	int *len_p = &len, *clientID_p = &clientID, *clientBalance_p = &clientBalance, *clientContrib_p = &clientContrib;

	setCurentTime(currentSimulateTime);
	while (day <= simulateDuration) {
		printCurrentDay(currentSimulateTime, day);
		while (currentSimulateTime <= startSimulation + dayDuration) {

			srand(time(0));
			haveCustomer = rand() % 1;
			if (haveCustomer == 1) {
				isCustomerNew = rand() % 100 + 1;
				operationNumber = rand() % 4 + 1;
				/*
				1 - putMoney
				2 - receiveMoney
				3 - transferMoney
				4 - contribution
				*/
				
				if (isCustomerNew < 6) {
					//Customer is NEW

					infoStringsNumber++;
				}
				//Customer isn't new
				customerNumber = rand() % 3 + 1;	//3 = info strings!!!
				getInfoString(infoString, len_p, customerNumber);

			}
			Sleep(2000);
		}
		day++;
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