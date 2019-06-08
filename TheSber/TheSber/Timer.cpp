#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include "Timer.h"

void setCurentTime(time_t *currentTime) {
	time(currentTime);
}

void simulation(time_t *startSimulation, time_t *currentSimulateTime, int simulateDuration) {
	int day = 1;
	int dayDuration = 30;

	setCurentTime(currentSimulateTime);
	while (day <= simulateDuration) {
		printCurrentDay(currentSimulateTime, day);
		while (currentSimulateTime <= startSimulation + dayDuration) {

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