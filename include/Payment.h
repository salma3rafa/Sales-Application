#ifndef PAYMENT_H
#define PAYMENT_H
#include<string>
#include<iostream>
#include<ctime>
using namespace std;
class Payment
{
    public:
        Payment();
        virtual ~Payment();
       virtual void makePay();
        void setPay(double);
        double pay();
       std::string Update();

    protected:

    private:
        char*dt;
        time_t date;
        double amount;
};

#endif // PAYMENT_H
