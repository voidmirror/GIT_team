#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <Windows.h>
#include "Customer.h"

void printList(CUSTOMER *ph)
{
	CUSTOMER* p = ph;
	while (p)
	{
		printf("%i  %s  \n   balance: %i ", p->IDcode, p->Name, p->Balance);
		if (p->Contribution != 0) printf("have contrib %i under %4.2f %", p->Contribution, p->per);
		printf("\n");
		p = p->pnext;

	}
	printf("\n\n");
}

void printCustomerName(CUSTOMER *ph, int ID)
{
	CUSTOMER* p = ph;
	while (p&&(p->IDcode!=ID))
	{
		p = p->pnext;
	}
	if (p) printf("%s", p->Name);

}
int getAmount(CUSTOMER *ph)
{
	int k = 0;
	CUSTOMER* p = ph;
	while (p)
	{
		k++;
		p = p->pnext;

	}
	return k;
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
	pnew->per = 0;
	for (int i = 0; i <= strlen(Name); i++)
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
	FILE *names;
	if ((names = fopen("archive/names.txt", "r")) == NULL)
	{
		printf("Unavailable");
		getchar();
		return;
	}

	names = fopen("archive/names.txt", "r");

	//srand(time(0));

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
			fclose(names);
			return;
		}
		checker++;
	}
}

void getRandomSurname(char getName[], int *len) {
	FILE *names;
	if ((names = fopen("archive/surnames.txt", "r")) == NULL)
	{
		printf("Unavailable");
		getchar();
		return;
	}

	names = fopen("archive/surnames.txt", "r");
	
	//srand(time(0));

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
			fclose(names);
			return;
		}
		checker++;
	}
}

int isVoidID(CUSTOMER *ph, int IDcode)
{
	CUSTOMER* p = ph;
	while (p)
	{
		if (p->IDcode == IDcode)
			return 0;
		p = p->pnext;
	}
	return 1;
}

int getFreeID(CUSTOMER *ph)
{
	CUSTOMER* p = ph;
	while (p->pnext)
	{
		if (p->IDcode + 2 == p->pnext->IDcode)
			break;
		p = p->pnext;
	}
	return p->IDcode + 1;
}