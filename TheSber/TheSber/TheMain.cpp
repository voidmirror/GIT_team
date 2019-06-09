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
	char surname[20];
	
	//Вывод приветствия
	printf("Please, enter the duration of the simulation: ");
	scanf("%d", &simulateDuration);
	setCurentTime(startSimulateTime_p);
	
	//Проверка доступности получения таймкода
	if (startSimulateTime == -1) {
		printf("\nSimulation is impossible. Timecode is unavailable.\nProgram will terminate in 5 seconds.");
		Sleep(5000);
	}	
	



	//Пример преобразования строки в число
	int top;
	char netop[7] = "000003";
	top = atoi(netop);
	printf("%d - top\n", top);
	char estop[7] = "650540";
	top = atoi(estop);
	printf("%d - top\n", top);

	//Рандомные имя-фамилия 
	int len;
	int *len_p = &len;
	getRandomName(name, len_p);
	for (int i = 0; i < len-1; i++) {
		printf("%c", name[i]);
	}
	printf(" ");
	getRandomSurname(surname, len_p);
	puts(surname);
	
	//system("cls");

	printf("\n");	
}