#ifndef OPERATIONS_H
#define OPERATIONS_H
#include"Customers/Customer.h"
int changeBalance(CUSTOMER **phead, int IDcode, int sum, void(*oper)(CUSTOMER **, int));
void putMoney(CUSTOMER **p, int sum);
void receiveMoney(CUSTOMER **p, int sum);
void contribution(CUSTOMER **phead, int IDcode, int sum, float per);
void contribRise(CUSTOMER **phead);
int transferMoney(CUSTOMER **phead, int IDsource, int IDdest, int sum);
#endif // !OPERATIONS_H
