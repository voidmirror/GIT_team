#include "Operations.h"
//#include "Customers/Customer.h"

int changeBalance(CUSTOMER **phead, int IDcode, int sum, void (*oper)(CUSTOMER **, int))
{
	CUSTOMER **p = phead;
	while ((*p)&&((*p)->IDcode!=IDcode))
	{
		p = &((*p)->pnext);
	}
	if ((*p))
	{
		oper(p, sum);
		//SUCESS
		return 1; 
	}
	//FAIL
	return 0;
}
void putMoney(CUSTOMER **p, int sum)
{
	(*p)->Balance += sum;
}
void receiveMoney(CUSTOMER **p, int sum)
{
	if ((*p)->Balance >= sum)
	(*p)->Balance -= sum;
}
//int contribution(CUSTOMER **phead, int ID, int sum, int per);


int transferMoney(CUSTOMER **phead, int IDsource, int IDdest, int sum)
{
	CUSTOMER **pSource = phead;
	CUSTOMER **pDest = phead;
	while (((*pDest)->IDcode!=IDdest)||((*pSource)->IDcode != IDsource))
	{
		if ((!(*pDest)) || (!(*pSource)))
		{
			// ERR
			return 0;
		}
		if ((*pDest)->IDcode != IDdest)
		{
			pDest = &((*pDest)->pnext);
		}
		if ((*pSource)->IDcode != IDsource)
		{
			pSource = &((*pSource)->pnext);
		}

	}
	if ((*pSource)->Balance >= sum) {
		receiveMoney(pSource, sum);
		putMoney(pDest, sum);
	}
	return 0;
}