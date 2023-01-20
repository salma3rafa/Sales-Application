#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<string>
#include<iostream>
#include"../include/Payment.h"
#include"../include/Cash.h"
#include"../include/Credit.h"
#include"../include/Check.h"
#include"../include/Order.h"
#include<ctime>

class Transaction
{

    friend ostream&operator<<(ostream&out,Transaction&t);
    public:
        Transaction();
        virtual ~Transaction();
        // Transaction operator+(Order&o,Payment&p);
         void setPAy(double);
         double getPay();
         void takePay();
         void totalTran();

    protected:

    private:
        int Count;
        char* dt;
        double payAmount;
         time_t transaction_date;
        Order*order;
        Payment**pay;
};

#endif // TRANSACTION_H
