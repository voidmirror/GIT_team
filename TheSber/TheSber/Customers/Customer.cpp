#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include "Customer.h"

void printList(CUSTOMER *ph)
{
	CUSTOMER* p = ph;
	while (p)
	{
		printf("%i\n", p->IDcode);
		p = p->pnext;

	}
	printf("\n\n");
}



void newCustomer(CUSTOMER **ph, int ID, int Money, char *Name)
{
	CUSTOMER **pp = ph, *pnew;
	while (*pp)
	{
		if (ID < (*pp)->IDcode)
		{
			break;
		}
		else
		{
			pp = &((*pp)->pnext);
		}

	}
	pnew = (CUSTOMER *)malloc(sizeof(CUSTOMER));
	pnew->IDcode = ID;
	pnew->Balance = Money;
	pnew->Contribution = 0;
	for (int i = 0; i < strlen(Name); i++)
	{
		pnew->Name[i] = *(Name + i);
	}
	pnew->pnext = *pp;
	*pp = pnew;

}
void deleteCustomer(CUSTOMER **ph, int ID)
{
	CUSTOMER **pp = ph;
	CUSTOMER *dopp = NULL;
	while (((*pp)->pnext))
	{
		if (((*pp)->pnext)->IDcode == ID)
		{
			//delete
			dopp = (*pp)->pnext;
			(*pp)->pnext = ((*pp)->pnext)->pnext;
			free(dopp);
			break;
		}
		pp = &((*pp)->pnext);
	}

}

void getRandomName(char getName[], int *len) {
	/*
	Указание к функции:
	На ввод массив символов char[20] и указатель на любой int,
	который будет использован в качестве длины строки.
	После выполнения функции в int *len будет лежать <длина слова + 1>
	Можно использовать для вывода в консоль или печати в другую строку.
	Пример:
	for (int i = 0; i < len-1; i++) {
		printf("%c", name[i]);
	}
	Примечание: puts(name) тоже работает.
	*/

	FILE *names;
	if ((names = fopen("archive/names.txt", "r")) == NULL)
	{
		printf("Unavailable");
		getchar();
		return;
	}

	names = fopen("archive/names.txt", "r");

	srand(time(0));
	int random, checker = 1;
	char temp[20];
	random = rand() % 168 + 1;
	//random = 5;	//Check
	while (fgets(temp, 20, names)) {
		if (checker == random) {
			//puts(temp);
			*len = strlen(temp);
			for (int i = 0; i < *len; i++) {
				getName[i] = temp[i];
				if (i == *len - 1) {
					getName[i] = '\0';
				}
			}
			return;
		}
		checker++;
	}
}

void getRandomSurname(char getName[], int *len) {
	/*
	Указание к функции:
	На ввод массив символов char[20] и указатель на любой int,
	который будет использован в качестве длины строки.
	После выполнения функции в int *len будет лежать <длина слова + 1>
	Можно использовать для вывода в консоль или печати в другую строку.
	Пример:
	for (int i = 0; i < len-1; i++) {
	printf("%c", name[i]);
	}
	Примечание: puts(name) тоже работает.
	*/

	FILE *names;
	if ((names = fopen("archive/surnames.txt", "r")) == NULL)
	{
		printf("Unavailable");
		getchar();
		return;
	}

	names = fopen("archive/surnames.txt", "r");

	srand(time(0));
	int random, checker = 1;
	char temp[20];
	random = rand() % 238 + 1;
	//random = 2;	//Check
	while (fgets(temp, 20, names)) {
		if (checker == random) {
			//puts(temp);
			*len = strlen(temp);
			for (int i = 0; i < *len; i++) {
				getName[i] = temp[i];
				if (i == *len - 1) {
					getName[i] = '\0';
				}
			}
			return;
		}
		checker++;
	}
}