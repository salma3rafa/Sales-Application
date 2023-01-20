#ifndef CASH_H
#define CASH_H
#include"../include/Payment.h"
class Cash:public Payment
{
    public:
        Cash();
        virtual ~Cash();
        double cashValue;
        double getCashValue();
        void makePay();
        void setCash(double);

    protected:

    private:
};

#endif // CASH_H
