#ifndef CUSTOMER_H
#define CUSTOMER_H

typedef struct Customer
{
	int IDcode;
	char Name[50];
	int Balance;
	int Contribution;
	struct Customer *pnext;
} CUSTOMER;



void newCustomer(CUSTOMER **ph, int ID, int Money, char *name);
void deleteCustomer(CUSTOMER **ph, int ID);
void printList(CUSTOMER *ph);
void getRandomName(char getName[], int *len);
void getRandomSurname(char getName[], int *len);

int getFreeID(CUSTOMER *ph);

#endif