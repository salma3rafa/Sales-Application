#include "Payment.h"
#include<iostream>
using namespace std;
Payment::Payment()
{
   date=time(0);
}

Payment::~Payment()
{
    //dtor
}
void Payment::makePay()//takes the customer's pay..a virtual fun
{
    dt=ctime(&date);
    cout<<"Customer's pay : ";
    cin>>this->amount;
}
void Payment::setPay(double pay)
{
    this->amount=pay;
}
double Payment::pay()
{
    return this->amount;
}
std::string Payment:: Update()//updates customer's pay
{
    std::string newPay;
    cout<<"Customer's new pay : ";
     cin.ignore();
     getline(cin,newPay);
     std::string pay=to_string(amount);
     pay=newPay;
     return pay;

}
