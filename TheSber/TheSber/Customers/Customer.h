#ifndef CUSTOMER_H
#define CUSTOMER_H

typedef struct Customer
{
	int IDcode;
	char Name[50];
	int Balance;
	int Contribution;
	float per;
	struct Customer *pnext;
} CUSTOMER;



void newCustomer(CUSTOMER **ph, int ID, int Money, char *name);
void deleteCustomer(CUSTOMER **ph, int ID);
void printList(CUSTOMER *ph);
void getRandomName(char getName[], int *len);
void getRandomSurname(char getName[], int *len);
void getInfoString(char getInfo[], int *len, int stringNumber);

int getFreeID(CUSTOMER *ph);
int checkID(CUSTOMER *ph, int IDcode);
int getAmount(CUSTOMER *ph);
void printCustomerName(CUSTOMER *ph, int ID);
#endif