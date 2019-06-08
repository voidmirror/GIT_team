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

void getRandomName(char *getName[]) {
	FILE *names;
	if ((names = fopen("archive/names.txt", "r")) == NULL)
	{
		printf("Unavailable");
		getchar();
		return;
	}

	names = fopen("archive/names.txt", "r");

	srand(time(0));
	int random, checker = 1, len;
	char temp[20];
	random = rand() % 168 + 1;
	while (fgets(temp, 20, names)) {
		if (checker == random) {
			//puts(temp);
			len = strlen(temp);
			for (int i = 0; i < len; i++) {
				*getName[i] = temp[i];
			}
			return;
		}
		checker++;
	}
}