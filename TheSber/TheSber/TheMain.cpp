#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include "Timer.h"
#include "Customers\Customer.h"

int main() {
	//Объявление переменных
	int simulateDuration;

	time_t startSimulateTime;
	time_t currentSimulateTime;
	
	time_t *startSimulateTime_p = &startSimulateTime;
	time_t *currentSimulateTime_p = &currentSimulateTime;

	char name[20];
	char *name_p[20];

	//FILE *names;

	
	
	/*
	//Добавить в Customer--------------------------------------------------
	if ((names = fopen("archive/names.txt", "r")) == NULL)
	{
		printf("Unavailable");
		getchar();
		return 0;
	}

	names = fopen("archive/names.txt", "r");
	
	srand(time(0));
	int random;
	for (int i = 0; i < 400; i++) {
		random = rand() % 50 + 1;
		printf("%d\n", random);
	}
	//Добавить в Customer--------------------------------------------------
	*/
	
	printf("Please, enter the duration of the simulation: ");
	scanf("%d", &simulateDuration);
	setCurentTime(startSimulateTime_p);
	
	//Проверка доступности получения таймкода
	if (startSimulateTime == -1) {
		printf("\nSimulation is impossible. Timecode is unavailable.\nProgram will terminate in 5 seconds.");
		Sleep(5000);
	}	

	getRandomName(name_p);
	printf("\n\n");
	puts(name);

	//system("cls");
	
	/*
	for (int i = 0; i < 6; i++) {
		setCurentTime(currentSimulateTime_p);
		Sleep(500);
		printf("%d - current\n", currentSimulateTime);
	}
	*/
	
}