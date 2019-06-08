#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include "Timer.h"

int main() {
	//ќбъ€вление переменных
	int simulateDuration;
	int *simulateDuration_p = &simulateDuration;

	time_t startSimulateTime;
	time_t currentSimulateTime;
	
	time_t *startSimulateTime_p = &startSimulateTime;
	time_t *currentSimulateTime_p = &currentSimulateTime;
	
	printf("Please, enter the duration of the simulation: ");
	scanf("%d", &simulateDuration);
	setCurentTime(startSimulateTime_p);
	printf("%d - dur, %d - start\n", simulateDuration, *startSimulateTime_p);
	for (int i = 0; i < 50; i++) {
		printf("\n");
	}
	system("cls");
	
	/*
	for (int i = 0; i < 6; i++) {
		setCurentTime(currentSimulateTime_p);
		Sleep(500);
		printf("%d - current\n", currentSimulateTime);
	}
	*/
	
}