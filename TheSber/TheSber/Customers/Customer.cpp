#include "Customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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