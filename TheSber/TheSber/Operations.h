#ifndef OPERATIONS_H
#define OPERATIONS_H
#include"Customers/Customer.h"
int changeBalance(CUSTOMER **phead, int IDcode, int sum, void(*oper)(CUSTOMER **, int));
void putMoney(CUSTOMER **p, int sum);
void receiveMoney(CUSTOMER **p, int sum);
//int contribution(CUSTOMER **phead, int ID, int sum, int per);
int transferMoney(CUSTOMER **phead, int IDsource, int IDdest, int sum);
#endif // !OPERATIONS_H
