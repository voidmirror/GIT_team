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

    void newCustomer (CUSTOMER *ph, int, int, char *);
    void deleteCustomer (CUSTOMER *ph, int);
    

    
#endif